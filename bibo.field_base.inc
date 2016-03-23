<?php
/**
 * @file
 * BIBO default field bases.
 */

/**
 * Implements hook_field_default_field_bases().
 */
function bibo_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'bibo_contributors'.
  $field_bases['bibo_contributors'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibo_contributors',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'bibo',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'bibo_contribution',
  );

  // Exported field_base: 'bibo_full_name'.
  $field_bases['bibo_full_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibo_full_name',
    'indexes' => array(
      'family' => array(
        0 => 'family',
      ),
      'given' => array(
        0 => 'given',
      ),
    ),
    'locked' => 1,
    'module' => 'name',
    'settings' => array(
      'allow_family_or_given' => 0,
      'autocomplete_separator' => array(
        'credentials' => ', ',
        'family' => ' -',
        'generational' => ' ',
        'given' => ' -',
        'middle' => ' -',
        'title' => ' ',
      ),
      'autocomplete_source' => array(
        'credentials' => array(),
        'family' => array(),
        'generational' => array(
          'generational' => 0,
        ),
        'given' => array(),
        'middle' => array(),
        'title' => array(
          'title' => 'title',
        ),
      ),
      'components' => array(
        'credentials' => 0,
        'family' => 'family',
        'generational' => 0,
        'given' => 'given',
        'middle' => 0,
        'title' => 0,
      ),
      'generational_options' => '-- --
Jr.
Sr.
I
II
III
IV
V
VI
VII
VIII
IX
X',
      'labels' => array(
        'credentials' => 'Credentials',
        'family' => 'Family',
        'generational' => 'Generational',
        'given' => 'Given',
        'middle' => 'Middle name(s)',
        'title' => 'Title',
      ),
      'max_length' => array(
        'credentials' => 255,
        'family' => 63,
        'generational' => 15,
        'given' => 63,
        'middle' => 127,
        'title' => 31,
      ),
      'minimum_components' => array(
        'credentials' => 0,
        'family' => 'family',
        'generational' => 0,
        'given' => 'given',
        'middle' => 0,
        'title' => 0,
      ),
      'sort_options' => array(
        'generational' => 0,
        'title' => 'title',
      ),
      'title_options' => '-- --
Mr.
Mrs.
Miss
Ms.
Dr.
Prof.',
    ),
    'translatable' => 0,
    'type' => 'name',
  );

  // Exported field_base: 'bibo_publication_status'.
  $field_bases['bibo_publication_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'bibo_publication_status',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'bibo',
    'settings' => array(
      'year_range' => array(
        'maximum' => 2019,
        'minimum' => 1996,
      ),
    ),
    'translatable' => 0,
    'type' => 'bibo_publication_status',
  );

  return $field_bases;
}
