<?php
/**
 * @file
 * BIBO Work entity controllers and related functions.
 */

/**
 * Work entity.
 */
class BIBOWork extends Entity {
  /**
   * Default work entity constructor.
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'bibo_work');
  }

  /**
   * Default work entity URI.
   */
  protected function defaultUri() {
    return array('path' => 'work/' . $this->bibo_work_id);
  }
}

/**
 * Work controller.
 */
class BIBOWorkController extends EntityAPIController {
  /**
   * Create work entity from array of values.
   */
  public function create(array $values = array()) {
    // Default values.
    $values += array(
      'bibo_work_id' => '',
      'is_new' => TRUE,
      'title' => '',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
    );

    // Create the Contributor entity.
    $entity = parent::create($values);

    return $entity;
  }

  /**
   * Build content for rendering work entity.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    // Prepare render array for APA reference view mode.
    if ($view_mode == 'apa') {
      $build = array(
        '#view_mode' => $view_mode,
        '#entity_type' => 'bibo_work',
        '#bundle' => $entity->type,
      );

      // Get fields instances info ordered by widget weight.
      $instances = field_info_instances('bibo_work', $entity->type);
      uasort($instances, function($a, $b) {
        $a_weight = (is_array($a) && isset($a['widget']['weight'])) ? $a['widget']['weight'] : 0;
        $b_weight = (is_array($b) && isset($b['widget']['weight'])) ? $b['widget']['weight'] : 0;
        if ($a_weight == $b_weight) {
          return 0;
        }
        return ($a_weight < $b_weight) ? -1 : 1;
      });

      foreach ($instances as $instance) {
        $value = '';
        $items = $entity->$instance['field_name'];
        if (isset($items[LANGUAGE_NONE])) {
          $i = 0;
          foreach ($items[LANGUAGE_NONE] as $item) {
            if ($instance['field_name'] == 'bibo_contributors') {
              $render = field_view_value('bibo_work', $entity, $instance['field_name'], $item, array(
                'settings' => array(
                  'display_link' => TRUE,
                  'display_role' => FALSE,
                  'name_format' => 'abbreviated_name',
                ),
              ));
              $build[$item['bibo_contribution_role']][] = array('#markup' => ($i ? ', ' : '') . drupal_render($render));
            }
            else {
              $render = field_view_value('bibo_work', $entity, $instance['field_name'], $item);
              $build[$instance['field_name']][] = array('#markup' => drupal_render($render));
            }
            $i++;
          }

        }
      }
    }
    else {
      $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    }

    // Populate Bibliontology RDF mapping from work type.
    if (isset($entity->rdf_mapping)) {
      $entity->rdf_mapping['rdftype'] = _bibo_work_type_rdf_mapping($entity->type);
    }

    return $build;
  }
}

/**
 * Work metadata controller.
 */
class BIBOWorkMetadataController extends EntityDefaultMetadataController {
  /**
   * Provides basic entity property info for work entities.
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['title']['label'] = t('Title');
    $properties['title']['description'] = t('The title of the work.');

    $properties['created']['type'] = 'date';
    $properties['created']['description'] = t('The Unix timestamp when the work was created.');

    $properties['changed']['type'] = 'date';
    $properties['changed']['description'] = t('The Unix timestamp when the work was most recently saved.');

    unset($properties['status']);
    unset($properties['module']);

    return $info;
  }
}

/**
 * Work UI controller.
 */
class BIBOWorkUIController extends EntityDefaultUIController {
  /**
   * Menu callback for the work UI controller.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $wildcard = $this->entityInfo['admin ui']['menu wildcard'];

    // Change the menu type for the works overview page.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Replaces default entity title.
    $items[$this->path]['title'] = 'Works';

    // 'Add work' local action.
    $items[$this->path . '/add'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType),
      'page callback' => 'bibo_work_bundle_add_page_view',
      'page arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    );
    // Add actions for individual work types.
    $items[$this->path . '/add/%'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType, $this->id_count + 1),
      'page callback' => 'entity_ui_get_bundle_add_form',
      'page arguments' => array($this->entityType, $this->id_count + 1),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
    );

    // Work 'View' tab.
    $items[$this->path . '/manage/' . $wildcard . '/view'] = array(
      'title' => 'View',
      'page callback' => 'bibo_work_redirect_view',
      'page arguments' => array(4),
      'access callback' => 'entity_access',
      'access arguments' => array('view', $this->entityType),
      'weight' => -10,
      'type' => MENU_LOCAL_TASK,
    );
    $items['work/' . $wildcard] = array(
      'title callback' => 'bibo_work_label',
      'title arguments' => array(1),
      'page callback' => 'bibo_work_page_view',
      'page arguments' => array(1),
      'access callback' => 'user_access',
      'access arguments' => array('view any bibo_work'),
    );
    $items['work/' . $wildcard . '/view'] = array(
      'title' => 'View',
      'weight' => -10,
      'type' => MENU_DEFAULT_LOCAL_TASK,
    );

    // Work 'Edit' tab.
    $items['work/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'page callback' => 'bibo_work_redirect_edit',
      'page arguments' => array(1),
      'access callback' => 'entity_access',
      'access arguments' => array('edit', $this->entityType),
      'type' => MENU_LOCAL_TASK,
    );

    return $items;
  }
}

/**
 * Work views controller.
 */
class BIBOWorkViewsController extends EntityDefaultViewsController {
  /**
   * Defines the result for hook_views_data().
   */
  public function views_data() {
    $data = parent::views_data();
    
    // Override default views data (link_to_work).
    $data['bibo_work']['table']['base']['defaults'] = array('field' => 'title');
    $data['bibo_work']['bibo_work_id']['field']['handler'] = 'views_handler_field_work';
    $data['bibo_work']['title']['field']['handler'] = 'views_handler_field_work';
    $data['bibo_work']['title']['field']['link_to_work default'] = TRUE;
    
    // Work edit / delete links.
    $data['bibo_work']['edit_link'] = array(
      'field' => array(
        'title' => t('Work edit link'),
        'help' => t('Provide a simple link to edit a work.'),
        'handler' => 'views_handler_field_work_link_edit',
      ),
    );
    $data['bibo_work']['delete_link'] = array(
      'field' => array(
        'title' => t('Work delete link'),
        'help' => t('Provide a simple link to delete a work.'),
        'handler' => 'views_handler_field_work_link_delete',
      ),
    );

    return $data;
  }
}

/**
 * Access callback for the work entity.
 */
function bibo_work_access($op, $entity = NULL, $account = NULL) {
  if (user_access('administer bibo_works', $account)) {
    return TRUE;
  }
  if ($op == 'view') {
    return user_access('view any bibo_work');
  }
  return user_access("edit any $entity->type bibo_work", $account);
}

/**
 * Label callback for the work entity.
 */
function bibo_work_label($entity, $entity_type = 'bibo_work') {
  return empty($entity) ? t('Untitled work') : $entity->title;
}

/**
 * Fetch a work entity object.
 */
function bibo_work_load($bibo_work_id) {
  return entity_load_single('bibo_work', $bibo_work_id);
}

/**
 * Fetch multiple work entity objects based on certain conditions.
 */
function bibo_work_load_multiple($bibo_work_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('bibo_work', $bibo_work_ids, $conditions, $reset);
}

/**
 * Page callback for selecting the work type to be added.
 */
function bibo_work_bundle_add_page_view($entity_type) {
  module_load_include('inc', 'entity', 'includes/entity.ui');
  drupal_set_title(t('Select work type'));

  // Get entity info for our bundles.
  $info = entity_get_info($entity_type);
  $output = '<dl class="work-type-list">';
  foreach ($info['bundles'] as $bundle_name => $bundle_info) {
    if (user_access('edit any ' . $bundle_name . ' bibo_work')) {
      $add_path = $info['admin ui']['path'] . '/add/' . $bundle_name;
      if (module_exists('bibo_i18n')) {
        $label = entity_i18n_string('bibo:work_type:' . $bundle_name . ':label', $bundle_info['label']);
        $description = entity_i18n_string('bibo:work_type:' . $bundle_name . ':description', $bundle_info['description']);
      }
      else {
        $label = $bundle_info['label'];
        $description = $bundle_info['description'];
      }
      $output .= '<dt>' . l(t('Add @label', array('@label' => $label)), $add_path) . '</dt>';
      $output .= '<dd>' . $description . '</dd>';
    }
  }
  $output .= '</dl>';

  return $output;
}

/**
 * Sets up content to show an individual work entity.
 */
function bibo_work_page_view($entity, $view_mode = 'full') {
  return entity_view('bibo_work', array($entity), $view_mode);
}

/**
 * Form callback to create or edit a work entity.
 */
function bibo_work_form($form, &$form_state, $entity, $op = 'edit', $entity_type) {
  // Set the breadcrumbs.
  bibo_work_set_breadcrumb();

  // Set the translated page title (add).
  if ($op == 'add') {
    $info = entity_get_info('bibo_work');
    if (module_exists('bibo_i18n')) {
      $label = entity_i18n_string('bibo:work_type:' . $entity->type . ':label', $info['bundles'][$entity->type]['label']);
    }
    else {
      $label = $info['bundles'][$entity->type]['label'];
    }
    drupal_set_title(t('Add @label', array('@label' => $label)));
  }

  // Add the default property elements.
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($entity->title) ? $entity->title : '',
    '#maxlength' => 1024,
    '#size' => 120,
    '#required' => TRUE,
    '#weight' => -5,
  );

  // Add the field related form elements.
  $form_state['bibo_work'] = $entity;
  field_attach_form('bibo_work', $entity, $form, $form_state);

  // Autocomplete place field.
  if (isset($form['bibo_place'])) {
    $form['bibo_place'][$form['bibo_place']['#language']][0]['value']['#autocomplete_path'] = 'bibo_place/autocomplete';
  }

  // Autocomplete publisher field.
  if (isset($form['bibo_publisher'])) {
    $form['bibo_publisher'][$form['bibo_publisher']['#language']][0]['value']['#autocomplete_path'] = 'bibo_publisher/autocomplete/' . $entity->type;
  }

  // Autocomplete secondary_title field.
  if (isset($form['bibo_secondary_title'])) {
    $form['bibo_secondary_title'][$form['bibo_secondary_title']['#language']][0]['value']['#autocomplete_path'] = 'bibo_secondary_title/autocomplete/' . $entity->type;
  }

  // Display certain fields inline.
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'bibo') . '/css/inline-fields.css',
  );

  // Form actions.
  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );
  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => $submit + array('bibo_work_edit_form_submit'),
  );
  if (!empty($entity->title)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#suffix' => l(t('Cancel'), 'admin/content/work'),
      '#submit' => $submit + array('bibo_work_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'] = array('bibo_work_edit_form_validate');

  return $form;
}

/**
 * Validation callback for the work form.
 */
function bibo_work_edit_form_validate(&$form, &$form_state) {
  $bibo_work = $form_state['bibo_work'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('bibo_work', $bibo_work, $form, $form_state);
}

/**
 * Submit callback for the work form.
 */
function bibo_work_edit_form_submit(&$form, &$form_state) {
  // Build the entity from $form and $form_state.
  $entity = entity_ui_controller('bibo_work')->entityFormSubmitBuildEntity($form, $form_state);

  // Add in created and changed times.
  $is_new_entity = $entity->is_new = isset($entity->is_new) ? $entity->is_new : 0;
  if ($is_new_entity) {
    $entity->created = time();
  }
  $entity->changed = time();
  $entity->save();

  // Send feedback message to the user.
  $message = t("Work :title updated.", array(':title' => $entity->title));
  if ($is_new_entity) {
    $message = t("Work :title created.", array(':title' => $entity->title));
  }
  drupal_set_message($message);

  // Redirect to work entity.
  $form_state['redirect'] = 'work/' . $entity->bibo_work_id;
}

/**
 * Submit callback for the contributor delete action.
 */
function bibo_work_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/work/manage/' . $form_state['bibo_work']->bibo_work_id . '/delete';
}

/**
 * Redirect callback for the work 'View' tab.
 */
function bibo_work_redirect_view($entity) {
  drupal_goto('work/' . $entity->bibo_work_id);
}

/**
 * Redirect callback for the work 'Edit' tab.
 */
function bibo_work_redirect_edit($entity) {
  drupal_goto('admin/content/work/manage/' . $entity->bibo_work_id);
}

/**
 * Sets the breadcrumb for administrative work pages.
 */
function bibo_work_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Works'), 'admin/content/work'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
