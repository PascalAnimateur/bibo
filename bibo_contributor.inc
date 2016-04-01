<?php
/**
 * @file
 * BIBO Contributor entity controllers and related functions.
 */

/**
 * Contributor entity.
 */
class BIBOContributor extends Entity {
  /**
   * Default contributor entity constructor.
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'bibo_contributor');
  }

  /**
   * Default contributor entity URI.
   */
  protected function defaultUri() {
    return array('path' => 'contributor/' . $this->bibo_contributor_id);
  }
}

/**
 * Contributor controller.
 */
class BIBOContributorController extends EntityAPIController {
  /**
   * Create contributor entity from array of values.
   */
  public function create(array $values = array()) {
    // Default values.
    $values += array(
      'bibo_contributor_id' => '',
      'name' => '',
      'is_new' => TRUE,
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
    );

    // Guess Contributor type from name.
    if (empty($values['type'])) {
      $parts = explode(',', $values['name']);
      if (sizeof($parts) == 2) {
        $values['type'] = 'person';
        // Update name property so that given name is abbreviated.
        $values['name'] = _bibo_contributor_abbreviate_person_name(trim($parts[0]), trim($parts[1]));
      }
      else {
        $values['type'] = 'organization';
      }
    }

    // Create the contributor entity.
    $entity = parent::create($values);

    // Set person's bibo_full_name field value (given/family).
    if (isset($parts) && $values['type'] == 'person') {
      $entity->wrapper()->bibo_full_name->set(array(
        'given' => trim($parts[1]),
        'family' => trim($parts[0]),
      ));
    }

    return $entity;
  }

  /**
   * Save contributor entity.
   */
  public function save($entity) {
    // Warn about duplicate Contributors.
    $duplicates = _bibo_contributor_find_duplicates($entity->name);
    unset($duplicates[$entity->bibo_contributor_id]);
    foreach ($duplicates as $duplicate) {
      drupal_set_message(t('Possible duplicate contributor exists (!duplicate).', array(
        '!duplicate' => l(bibo_contributor_label($duplicate), 'contributor/' . $duplicate->bibo_contributor_id),
      )), 'warning');
    }

    return parent::save($entity);
  }

  /**
   * Merge contributors by updating contribution field references.
   */
  public function merge($bibo_contributor_id, $merged_ids) {
    if (empty($merged_ids)) {
      return 0;
    }
    // Update all references to the merged contributor.
    $update_count = 0;
    foreach (field_info_fields() as $field_name => $field) {
      if ($field['type'] == 'bibo_contribution') {
        foreach ($field['storage']['details']['sql'] as $storage) {
          $table = array_keys($storage)[0];
          $column = $storage[$table]['bibo_contributor_id'];
          $update_count += db_update($table)
            ->fields(array(
              $column => $bibo_contributor_id,
            ))
            ->condition($column, $merged_ids, 'IN')
            ->execute();
        }
      }
    }
    field_cache_clear();
    return $update_count;
  }

  /**
   * Delete contributor entities, removing existing contribution field references.
   */
  public function delete($ids) {
    // Remove all references to the deleted contributors.
    foreach (field_info_fields() as $field_name => $field) {
      if ($field['type'] == 'bibo_contribution') {
        foreach ($field['storage']['details']['sql'] as $storage) {
          $table = array_keys($storage)[0];
          $column = $storage[$table]['bibo_contributor_id'];
          db_delete($table)
            ->condition($column, $ids)
            ->execute();
        }
      }
    }
    field_cache_clear();
    return parent::delete($ids);
  }
}

/**
 * Helper function to abbreviate person name.
 */
function _bibo_contributor_abbreviate_person_name($family, $given) {
  if (empty($family) || empty($given)) {
    return t('Unknown contributor');
  }
  // Start with Family name followed by ', '.
  $name = $family . ', ';

  // Add initial(s) from given name (split with ' ' and '-' delimiters).
  $parts = preg_split("/[\s-]/", $given);
  foreach ($parts as $part) {
    $name .= drupal_substr($part, 0, 1) . '.';
  }

  return $name;
}

/**
 * Helper function to find duplicate contributors with matching labels.
 *
 * @param $bibo_contributor_label
 *   The label of the contributor as displayed in a reference (abbreviated).
 *
 * @return
 *   An array of contributor entity objects indexed by their ids. When no
 *   results are found, an empty array is returned.
 */
function _bibo_contributor_find_duplicates($bibo_contributor_label) {
  $query = new EntityFieldQuery();
  $results = $query->entityCondition('entity_type', 'bibo_contributor')
    ->propertyCondition('name', $bibo_contributor_label)
    ->execute();

  $ids = isset($results['bibo_contributor']) ? array_keys($results['bibo_contributor']) : array();

  return bibo_contributor_load_multiple($ids);
}

/**
 * Contributor metadata controller.
 */
class BIBOContributorMetadataController extends EntityDefaultMetadataController {
  /**
   * Provides basic entity property info for contributor entities.
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['name']['label'] = t('Contributor Label');
    $properties['name']['description'] = t('The label of the contributor as displayed in a reference (i.e. abbreviated given name).');

    $properties['created']['type'] = 'date';
    $properties['created']['description'] = t('The Unix timestamp when the contributor was created.');

    $properties['changed']['type'] = 'date';
    $properties['changed']['description'] = t('The Unix timestamp when the contributor was most recently saved.');

    unset($properties['status']);
    unset($properties['module']);

    return $info;
  }
}

/**
 * Contributor UI controller.
 */
class BIBOContributorUIController extends EntityDefaultUIController {
  /**
   * Menu callback for the contributor UI controller.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $wildcard = $this->entityInfo['admin ui']['menu wildcard'];

    // Contributor 'Add' local actions (Add organization / Add person).
    unset($items[$this->path . '/add']);
    $items[$this->path . '/add/person'] = array(
      'title' => t('Add person'),
      'page callback' => 'entity_ui_get_bundle_add_form',
      'page arguments' => array($this->entityType, $this->id_count + 1),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    );
    $items[$this->path . '/add/organization'] = array(
      'title' => t('Add organization'),
      'page callback' => 'entity_ui_get_bundle_add_form',
      'page arguments' => array($this->entityType, $this->id_count + 1),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    );

    // Contributor 'View' tab.
    $items[$this->path . '/manage/' . $wildcard . '/view'] = array(
      'title' => 'View',
      'page callback' => 'bibo_contributor_redirect_view',
      'page arguments' => array(4),
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
      'weight' => -10,
      'type' => MENU_LOCAL_TASK,
    );
    $items['contributor/' . $wildcard] = array(
      'title callback' => 'bibo_contributor_page_title',
      'title arguments' => array(1),
      'page callback' => 'bibo_contributor_page_view',
      'page arguments' => array(1),
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
    );
    $items['contributor/' . $wildcard . '/view'] = array(
      'title' => 'View',
      'weight' => -10,
      'type' => MENU_DEFAULT_LOCAL_TASK,
    );

    // Contributor 'Edit' tab.
    $items['contributor/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'page callback' => 'bibo_contributor_redirect_edit',
      'page arguments' => array(1),
      'access callback' => 'entity_access',
      'access arguments' => array('edit', $this->entityType),
      'type' => MENU_LOCAL_TASK,
    );

    // Contributor 'Merge' tab.
    $items[$this->path . '/manage/' . $wildcard . '/merge'] = array(
      'title' => 'Merge',
      'page callback' => 'drupal_get_form',
      'page arguments' => array('bibo_contributor_merge_form', 4),
      'access callback' => 'user_access',
      'access arguments' => array('administer bibo_contributors'),
      'type' => MENU_LOCAL_TASK,
    );
    $items['contributor/' . $wildcard . '/merge'] = array(
      'title' => 'Merge',
      'page callback' => 'bibo_contributor_redirect_merge',
      'page arguments' => array(1),
      'access callback' => 'user_access',
      'access arguments' => array('administer bibo_contributors'),
      'type' => MENU_LOCAL_TASK,
    );

    return $items;
  }
}

/**
 * Contributor views controller.
 */
class BIBOContributorViewsController extends EntityDefaultViewsController {
  /**
   * Defines the result for hook_views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    // Override default views data (link_to_contributor).
    $data['bibo_contributor']['table']['base']['defaults'] = array('field' => 'name');
    $data['bibo_contributor']['bibo_contributor_id']['field']['handler'] = 'views_handler_field_contributor';
    $data['bibo_contributor']['name']['field']['handler'] = 'views_handler_field_contributor';
    $data['bibo_contributor']['name']['field']['link_to_contributor default'] = TRUE;

    // Contributor edit / delete / merge links.
    $data['bibo_contributor']['edit_link'] = array(
      'field' => array(
        'title' => t('Contributor edit link'),
        'help' => t('Provide a simple link to edit a contributor.'),
        'handler' => 'views_handler_field_contributor_link_edit',
      ),
    );
    $data['bibo_contributor']['delete_link'] = array(
      'field' => array(
        'title' => t('Contributor delete link'),
        'help' => t('Provide a simple link to delete a contributor.'),
        'handler' => 'views_handler_field_contributor_link_delete',
      ),
    );
    $data['bibo_contributor']['merge_link'] = array(
      'field' => array(
        'title' => t('Contributor merge link'),
        'help' => t('Provide a simple link to merge a contributor.'),
        'handler' => 'views_handler_field_contributor_link_merge',
      ),
    );

    return $data;
  }
}

/**
 * Access callback for the contributor entity.
 */
function bibo_contributor_access($op, $entity = NULL, $account = NULL) {
  if (user_access('administer bibo_contributors', $account)) {
    return TRUE;
  }
  if (isset($entity)) {
    $op = ($op == 'view') ? 'view' : 'edit';
    if (user_access("$op any bibo_contributor", $account)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Label callback for the contributor entity.
 */
function bibo_contributor_label($entity, $entity_type = 'bibo_contributor') {
  $label = t('Unknown contributor');

  if ($entity->type == 'person') {
    $label = $entity->wrapper()->bibo_full_name->value();
    $label = $label['family'] . ', ' . $label['given'];
  }
  else {
    $label = $entity->name;
  }

  return $label;
}

/**
 * Fetch a contributor entity object.
 */
function bibo_contributor_load($bibo_contributor_id) {
  return entity_load_single('bibo_contributor', $bibo_contributor_id);
}

/**
 * Fetch multiple contributor entity objects based on certain conditions.
 */
function bibo_contributor_load_multiple($bibo_contributor_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('bibo_contributor', $bibo_contributor_ids, $conditions, $reset);
}

/**
 * Menu title callback for showing individual contributor entities.
 */
function bibo_contributor_page_title($entity) {
  return bibo_contributor_label($entity);
}

/**
 * Sets up content to show an individual contributor entity.
 */
function bibo_contributor_page_view($entity, $view_mode = 'full') {
  return entity_view('bibo_contributor', array($entity), $view_mode);
}

/**
 * Form callback to create or edit a contributor entity.
 */
function bibo_contributor_form($form, &$form_state, $entity, $op = 'edit', $entity_type) {
  // Add the default property elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Organization name'), // This will be hidden if bundle is person.
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#access' => ($entity->type == 'person') ? FALSE : TRUE,
    '#weight' => -5,
  );

  // Add the field related form elements.
  $form_state['bibo_contributor'] = $entity;
  field_attach_form('bibo_contributor', $entity, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => $submit + array('bibo_contributor_edit_form_submit'),
  );
  // Add the Delete action if this is an Edit form.
  if ($op == 'edit') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#suffix' => l(t('Cancel'), 'admin/people/contributor'),
      '#submit' => $submit + array('bibo_contributor_form_submit_delete'),
      '#weight' => 45,
    );
  }

  $form['#validate'] = array('bibo_contributor_edit_form_validate');

  return $form;
}

/**
 * Validation callback for the contributor form.
 */
function bibo_contributor_edit_form_validate(&$form, &$form_state) {
  $entity = $form_state['bibo_contributor'];

  // Set name from person given/family.
  if ($entity->type == 'person') {
    $lang = $form['bibo_full_name']['#language'];
    $family = $form_state['values']['bibo_full_name'][$lang][0]['family'];
    $given = $form_state['values']['bibo_full_name'][$lang][0]['given'];
    $form_state['values']['name'] = _bibo_contributor_abbreviate_person_name($family, $given);
  }

  // Notify field widgets to validate their data.
  field_attach_form_validate('bibo_contributor', $entity, $form, $form_state);
}


/**
 * Submit callback for the contributor form.
 */
function bibo_contributor_edit_form_submit(&$form, &$form_state) {
  // Build the entity from $form and $form_state.
  $entity = entity_ui_controller('bibo_contributor')->entityFormSubmitBuildEntity($form, $form_state);

  // Add in created and changed times.
  $is_new_entity = $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
  if ($is_new_entity) {
    $entity->created = time();
  }
  $entity->changed = time();
  $entity->save();

  // Send feedback message to the user.
  $message = t("Contributor :name updated.", array(':name' => bibo_contributor_label($entity)));
  if ($is_new_entity) {
    $message = t("Contributor :name created.", array(':name' => bibo_contributor_label($entity)));
  }
  drupal_set_message($message);

  // Redirect to contributors overview page.
  $form_state['redirect'] = 'admin/people/contributor';
}

/**
 * Form callback to merge contributors.
 */
function bibo_contributor_merge_form($form, &$form_state, $entity = NULL) {
  // Set the page title.
  drupal_set_title(t('Merge @name', array('@name' => bibo_contributor_label($entity))));

  // Merge form fieldset that will be dynamically updated via AJAX.
  $form['merge'] = array(
    '#type' => 'fieldset',
    '#title' => t('Merge with the following contributors:'),
    '#description' => t('Please select the contributors you would like to merge with %name.
    This means all references to the selected contributors will be automatically replaced with references to <em>%name</em> in all works.
    <br><strong>WARNING:</strong> This cannot be undone.',
      array('%name' => bibo_contributor_label($entity))),
    '#bibo_contributor_id' => $entity->bibo_contributor_id,
    '#prefix' => '<div id="merge-container">',
    '#suffix' => '</div>',
  );

  // Build the tableselect header.
  $header = array(
    'name' => t('Name'),
    'type' => t('Type'),
    'created' => t('Created'),
    'reference_count' => t('Reference count'),
  );

  // Build the merge candidates for the tableselect.
  if (isset($form_state['complete form']['merge']['candidates']['#options'])) {
    // Use existing merge candidates list.
    $options = $form_state['complete form']['merge']['candidates']['#options'];
  }
  else {
    // Create a new merge candidates list.
    $options = array();
    $candidates = _bibo_contributor_find_duplicates($entity->name);
    unset($candidates[$entity->bibo_contributor_id]);
    foreach ($candidates as $candidate) {
      $options[$candidate->bibo_contributor_id] = _bibo_contributor_merge_candidates_option($candidate);
    }
  }

  // Merge candidates list in a tableselect.
  $form['merge']['candidates'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No merge candidates found. You may add some manually using the form below.'),
  );

  // Add merge candidates manually.
  $form['merge']['add'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional merge candidates'),
    '#description' => t('Search for individual contributors that will be added to the merge candidates list above.'),
  );
  $form['merge']['add']['bibo_contributor'] = array(
    '#type' => 'textfield',
    '#size' => 50,
    '#autocomplete_path' => 'bibo_contribution/autocomplete',
  );
  $form['merge']['add']['submit'] = array(
    '#type' => 'button',
    '#value' => t('Add'),
    '#ajax' => array(
      'callback' => '_bibo_contributor_merge_add_candidates_ajax',
    ),
  );

  // Delete merged contributors checkbox.
  $form['delete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete merged contributors'),
    '#description' => t('Checking this option will delete the selected contributors from the database once they have been merged.
        <br><strong>WARNING</strong>: This cannot be undone.'),
  );

  // Merge submit action.
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Merge'),
    ),
  );

  return $form;
}

/**
 * Helper function to build tableselect row from contributor entity.
 */
function _bibo_contributor_merge_candidates_option($entity) {
  $bundles = entity_get_info('bibo_contributor')['bundles'];

  return array(
    'name' => l(bibo_contributor_label($entity), entity_uri('bibo_contributor', $entity)['path']) . ' [' . $entity->bibo_contributor_id . ']',
    'type' => $bundles[$entity->type]['label'],
    'created' => format_date($entity->created, 'short'),
    // TODO: Display reference count in merge candidate row.
    'reference_count' => '--',
  );
}

/**
 * AJAX callback to add contributors to the merge candidates table.
 */
function _bibo_contributor_merge_add_candidates_ajax($form, &$form_state) {
  $commands = array();

  // Empty value in additional contributors widget.
  unset($form['merge']['add']['bibo_contributor']['#value']);

  // Determine bibo_contributor_id from autocomplete result.
  $bibo_contributor_id = 0;
  if (preg_match("/.+\[(\d+)\]/", $form_state['values']['bibo_contributor'], $matches)) {
    // Match bibo_contributor_id from square bracket in "Name [id]".
    $bibo_contributor_id = $matches[1];
  }

  // Validate specified contributor.
  if ($bibo_contributor_id == $form['merge']['#bibo_contributor_id']) {
    // Cannot merge contributor with itself.
    $commands[] = ajax_command_replace('#merge-container', drupal_render($form['merge']));
    return array('#type' => 'ajax', '#commands' => $commands);
  }
  if (empty($entity = bibo_contributor_load($bibo_contributor_id))) {
    // Invalid contributor specified.
    $commands[] = ajax_command_replace('#merge-container', drupal_render($form['merge']));
    return array('#type' => 'ajax', '#commands' => $commands);
  }

  // Create new candidate option in tableselect.
  $form['merge']['candidates']['#options'][$bibo_contributor_id] = _bibo_contributor_merge_candidates_option($entity);

  // Update cached options for tableselect.
  // @see https://www.drupal.org/node/2319435#comment-9905099
  $cached_form = form_get_cache($form['#build_id'], $form_state);
  $cached_form['merge']['candidates']['#options'] = $form['merge']['candidates']['#options'];
  form_set_cache($form['#build_id'], $cached_form, $form_state);

  // Remove checkboxes from tableselect.
  foreach (element_children($form['merge']['candidates']) as $key) {
    if (is_numeric($key)) {
      unset($form['merge']['candidates'][$key]);
    }
  }

  // Add new checkboxes to tableselect.
  form_builder($form['#form_id'], $form['merge']['candidates'], $form_state);

  // Update the tableselect with the new options.
  $commands[] = ajax_command_replace('#merge-container', drupal_render($form['merge']));
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Submit callback for the contributor merge form.
 */
function bibo_contributor_merge_form_submit($form, &$form_state) {
  $bibo_contributor_id = $form['merge']['#bibo_contributor_id'];
  $merged_ids = array_filter($form_state['values']['candidates']);
  if (!empty($merged_ids)) {
    // Merge selected contributors.
    $controller = entity_get_controller('bibo_contributor');
    $update_count = $controller->merge($bibo_contributor_id, $merged_ids);
    if ($update_count) {
      drupal_set_message(t('@count references updated successfully.', array('@count' => $update_count)));
    }
    // Delete merged contributors if option was checked.
    if ($form_state['values']['delete']) {
      entity_delete_multiple('bibo_contributor', $merged_ids);
      if (sizeof($merged_ids)) {
        drupal_set_message(t('@count contributors deleted.',
          array('@count' => sizeof($merged_ids))));
      }
    }
  }

  // Redirect to the contributor view.
  $form_state['redirect'] = 'contributor/' . $form['merge']['#bibo_contributor_id'];
}

/**
 * Submit callback for the contributor delete action.
 */
function bibo_contributor_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/people/contributor/manage/' . $form_state['bibo_contributor']->bibo_contributor_id . '/delete';
}

/**
 * Redirect callback for the contributor 'View' tab.
 */
function bibo_contributor_redirect_view($entity) {
  drupal_goto('contributor/' . $entity->bibo_contributor_id);
}

/**
 * Redirect callback for the contributor 'Edit' tab.
 */
function bibo_contributor_redirect_edit($entity) {
  drupal_goto('admin/people/contributor/manage/' . $entity->bibo_contributor_id);
}

/**
 * Redirect callback for the contributor 'Merge' tab.
 */
function bibo_contributor_redirect_merge($entity) {
  drupal_goto('admin/people/contributor/manage/' . $entity->bibo_contributor_id . '/merge');
}

/**
 * Helper function to find existing contributor(s) or create a new one.
 */
function _bibo_contributor_find_or_create($name) {
  $contributor_ids = array();
  $parts = explode(',', $name);

  // Find person contributor(s) using full name.
  if (sizeof($parts) == 2) {
    $query = new EntityFieldQuery;
    $result = $query->entityCondition('entity_type', 'bibo_contributor')
      ->fieldCondition('bibo_full_name', 'family', trim($parts[1]), '=')
      ->fieldCondition('bibo_full_name', 'given', trim($parts[1]), '=')
      ->execute();
    if (isset($result['bibo_contributor'])) {
      $contributor_ids = array_keys($result['bibo_contributor']);
    }
    else {
      // Try abbreviated name instead of full name.
      $query = new EntityFieldQuery;
      $result = $query->entityCondition('entity_type', 'bibo_contributor')
        ->propertyCondition('name', _bibo_contributor_abbreviate_person_name(trim($parts[0]), trim($parts[1])), '=')
        ->execute();
      if (isset($result['bibo_contributor'])) {
        $contributor_ids = array_keys($result['bibo_contributor']);
      }
    }
  }
  else {
    // Find organization contributor(s) using name.
    $query = new EntityFieldQuery;
    $result = $query->entityCondition('entity_type', 'bibo_contributor')
      ->propertyCondition('name', $name, '=')
      ->execute();
    if (isset($result['bibo_contributor'])) {
      $contributor_ids = array_keys($result['bibo_contributor']);
    }
  }
  // Create new contributor
  if (empty($contributor_ids)) {
    // Found no contributor, create a new one.
    $entity = entity_create('bibo_contributor', array('name' => $name));
    if (entity_save('bibo_contributor', $entity)) {
      $contributor_ids[] = $entity->bibo_contributor_id;
    }
  }

  return $contributor_ids;
}
