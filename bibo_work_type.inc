<?php
/**
 * @file
 * BIBO Work type entity controllers and related functions.
 */

/**
 * Work type entity.
 */
class BIBOWorkType extends Entity {
  public $type;
  public $label;
  public $description;

  /**
   * Default work_type entity constructor.
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'bibo_work_type');
  }

  /**
   * Default work_type translation method.
   */
  public function getTranslation($property, $langcode = NULL) {
    if (module_exists('bibo_i18n')) {
      return parent::getTranslation($property, $langcode);
    }
    return $this->$property;
  }
}

/**
 * Work type controller.
 */
class BIBOWorkTypeController extends EntityAPIControllerExportable {
  /**
   * Create work_type entity from array of values.
   */
  public function create(array $values = array()) {
    // Default values.
    $values += array(
      'bibo_work_type_id' => '',
    );

    // Create the work_type entity.
    $entity = parent::create($values);

    return $entity;
  }
}

/**
 * Work type UI controller.
 */
class BIBOWorkTypeUIController extends EntityDefaultUIController {
  /**
   * Menu callback for the work_type UI controller.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage work types, including fields and display options.';

    return $items;
  }
}

/**
 * Access callback for the entity API.
 */
function bibo_work_type_access($op, $type = NULL, $account = NULL) {
  return user_access('administer bibo_work_types', $account);
}

/**
 * Label callback for the work_type entity.
 */
function bibo_work_type_label($entity, $entity_type) {
  if (module_exists('bibo_i18n')) {
    return entity_i18n_string('bibo:work_type:' . $entity->type . ':label', $entity->label);
  }
  return empty($entity) ? t('Untitled work type') : $entity->label;
}

/**
 * Fetch a work_type entity object.
 */
function bibo_work_type_load($type) {
  return _bibo_get_work_types($type);
}

/**
 * Form callback to create or edit a work_type entity.
 */
function bibo_work_type_form($form, &$form_state, $entity, $op = 'edit') {
  // Append cloned suffix if necessary.
  if ($op == 'clone') {
    $entity->label .= ' (cloned)';
    $entity->type = '';
  }

  // Add the default property elements.
  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->label) ? $entity->label : '',
    '#description' => t('The human-readable name of this work type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($entity->type) ? $entity->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => '_bibo_get_work_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this work type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#default_value' => isset($entity->description) ? isset($entity->description) : '',
    '#description' => t('Describe this work type. The text will be displayed on the <em>Add work</em> page.'),
  );

  // Default submit action.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Submit callback for the work_type form.
 */
function bibo_work_type_form_submit(&$form, &$form_state) {
  // Build the entity from $form and $form_state.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);
  $entity->save();
  $form_state['redirect'] = 'admin/structure/work_types';
}

/**
 * Form API submit callback for the delete button.
 */
function bibo_work_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/work_types/manage/' . $form_state['bibo_work_type']->type . '/delete';
}

/**
 * Helper function to get work types.
 */
function _bibo_get_work_types($type_name = NULL) {
  $types = entity_load_multiple_by_name('bibo_work_type', isset($type_name) ? array($type_name) : FALSE);

  return isset($type_name) ? reset($types) : $types;
}
