<?php
/**
 * @file
 * bibo.views.inc
 */

/**
 * Implements hook_field_views_data().
 *
 * Add relationship to referenced contributor (bibo_contribution).
 */
function bibo_field_views_data($field) {
  if ($field['type'] == 'bibo_contribution') {
    $data = field_views_field_default_views_data($field);
    $entity_info = entity_get_info('bibo_contributor');
    foreach ($data as $table_name => $table_data) {
      $field_name = $field['field_name'] . '_bibo_contributor_id';
      $replacements = array(
        '@entity' => $entity_info['label'],
        '!field_name' => $field['field_name'],
      );
      $data[$table_name][$field_name]['relationship'] = array(
        'handler' => 'views_handler_relationship',
        'base' => $entity_info['base table'],
        'base field' => $entity_info['entity keys']['id'],
        'label' => t('@entity referenced via !field_name', $replacements),
        'group' => t('BIBO'),
        'title' => t('Referenced @entity', $replacements),
        'help' => t('A bridge to the @entity that is referenced via !field_name', $replacements),
      );
    }
    return $data;
  }

  if ($field['type'] == 'bibo_publication_status') {
    $data = field_views_field_default_views_data($field);
    foreach ($data as $table_name => $table_data) {
      // Provide default options for 'status' filter select list.
      $field_name = $field['field_name'];
      $data[$table_name][$field_name . '_status']['filter']['handler'] = 'views_handler_filter_in_operator';
      $data[$table_name][$field_name . '_status']['filter']['options callback'] = '_bibo_get_default_publication_statuses';
      // Provide custom handler to support click sorting.
      $data[$table_name][$field_name]['field']['handler'] = 'views_handler_field_publication_status';
    }
    return $data;
  }
}

/**
 * Implements hook_field_views_data_views_data_alter().
 *
 * Add reverse relationship to entities referencing a contributor (bibo_contribution).
 */
function bibo_field_views_data_views_data_alter(&$data, $field) {
  if ($field['type'] == 'bibo_contribution') {
    $target_entity_info = entity_get_info('bibo_contributor');
    foreach ($field['bundles'] as $entity_type => $bundles) {
      $entity_info = entity_get_info($entity_type);
      $pseudo_field_name = 'reverse_' . $field['field_name'] . '_' . $entity_type;
      $replacements = array(
        '@entity' => $entity_info['label'],
        '@target_entity' => $target_entity_info['label'],
        '!field_name' => $field['field_name'],
      );
      $data[$target_entity_info['base table']][$pseudo_field_name]['relationship'] = array(
        'handler' => 'views_handler_relationship_entity_reverse',
        'field_name' => $field['field_name'],
        'field table' => _field_sql_storage_tablename($field),
        'field field' => $field['field_name'] . '_bibo_contributor_id',
        'base' => $entity_info['base table'],
        'base field' => $entity_info['entity keys']['id'],
        'label' => t('@entity referencing @target_entity via !field_name', $replacements),
        'group' => t('BIBO'),
        'title' => t('Referencing @entity', $replacements),
        'help' => t('A bridge to the @entity that is referencing @target_entity via !field_name', $replacements),
        'join_extra' => array(
          0 => array(
            'field' => 'entity_type',
            'value' => $entity_type,
          ),
          1 => array(
            'field' => 'deleted',
            'value' => 0,
            'numeric' => TRUE,
          ),
        ),
      );
    }

    return $data;
  }
}
