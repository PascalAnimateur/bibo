<?php
/**
 * @file
 * BIBO default field instances.
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bibo_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bibo_contributor-person-bibo_full_name'.
  $field_instances['bibo_contributor-person-bibo_full_name'] = array(
    'bundle' => 'person',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'name',
        'settings' => array(
          'format' => 'default',
          'markup' => 0,
          'multiple' => 'default',
          'multiple_and' => 'text',
          'multiple_delimiter' => ', ',
          'multiple_delimiter_precedes_last' => 'never',
          'multiple_el_al_first' => 1,
          'multiple_el_al_min' => 3,
          'output' => 'default',
        ),
        'type' => 'name_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_contributor',
    'field_name' => 'bibo_full_name',
    'label' => 'Full name',
    'required' => 1,
    'settings' => array(
      'component_css' => '',
      'component_layout' => 'default',
      'components' => array(
        'credentials' => 0,
        'family' => 0,
        'generational' => 0,
        'given' => 0,
        'middle' => 0,
        'title' => 0,
      ),
      'credentials_inline' => 0,
      'field_type' => array(
        'credentials' => 'text',
        'family' => 'text',
        'generational' => 'select',
        'given' => 'text',
        'middle' => 'text',
        'title' => 'select',
      ),
      'generational_field' => 'select',
      'inline_css' => array(
        'credentials' => '',
        'family' => '',
        'generational' => '',
        'given' => '',
        'middle' => '',
        'title' => '',
      ),
      'labels' => array(
        'credentials' => '',
        'family' => '',
        'generational' => '',
        'given' => '',
        'middle' => '',
        'title' => '',
      ),
      'minimum_components' => array(
        'credentials' => 0,
        'family' => 0,
        'generational' => 0,
        'given' => 0,
        'middle' => 0,
        'title' => 0,
      ),
      'override_format' => 'default',
      'show_component_required_marker' => 1,
      'size' => array(
        'credentials' => 35,
        'family' => 20,
        'generational' => 5,
        'given' => 20,
        'middle' => 20,
        'title' => 6,
      ),
      'title_display' => array(
        'credentials' => 'description',
        'family' => 'description',
        'generational' => 'description',
        'given' => 'description',
        'middle' => 'description',
        'title' => 'description',
      ),
      'title_field' => 'select',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'name',
      'settings' => array(),
      'type' => 'name_widget',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_abstract'.
  $field_instances['bibo_work-book-bibo_abstract'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_contributors'.
  $field_instances['bibo_work-book-bibo_contributors'] = array(
    'bundle' => 'book',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_full_text'.
  $field_instances['bibo_work-book-bibo_full_text'] = array(
    'bundle' => 'book',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_issue'.
  $field_instances['bibo_work-book-bibo_issue'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_issue',
    'label' => 'Edition',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_pages'.
  $field_instances['bibo_work-book-bibo_pages'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Number of pages',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 8,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_place'.
  $field_instances['bibo_work-book-bibo_place'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_place',
    'label' => 'Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_publication_status'.
  $field_instances['bibo_work-book-bibo_publication_status'] = array(
    'bundle' => 'book',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 0,
        'in_press' => 'in_press',
        'published' => 'published',
        'submitted' => 0,
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_publisher'.
  $field_instances['bibo_work-book-bibo_publisher'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publisher',
    'label' => 'Publisher',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_secondary_title'.
  $field_instances['bibo_work-book-bibo_secondary_title'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Collection',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_serial_number'.
  $field_instances['bibo_work-book-bibo_serial_number'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_serial_number',
    'label' => 'ISBN',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_url'.
  $field_instances['bibo_work-book-bibo_url'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'bibo_work-book-bibo_volume'.
  $field_instances['bibo_work-book-bibo_volume'] = array(
    'bundle' => 'book',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_volume',
    'label' => 'Volume',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_abstract'.
  $field_instances['bibo_work-book_section-bibo_abstract'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_contributors'.
  $field_instances['bibo_work-book_section-bibo_contributors'] = array(
    'bundle' => 'book_section',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 'book_author',
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_full_text'.
  $field_instances['bibo_work-book_section-bibo_full_text'] = array(
    'bundle' => 'book_section',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_issue'.
  $field_instances['bibo_work-book_section-bibo_issue'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_issue',
    'label' => 'Edition',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_pages'.
  $field_instances['bibo_work-book_section-bibo_pages'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Page range',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 8,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_place'.
  $field_instances['bibo_work-book_section-bibo_place'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_place',
    'label' => 'Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_publication_status'.
  $field_instances['bibo_work-book_section-bibo_publication_status'] = array(
    'bundle' => 'book_section',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 0,
        'in_press' => 'in_press',
        'published' => 'published',
        'submitted' => 0,
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_publisher'.
  $field_instances['bibo_work-book_section-bibo_publisher'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publisher',
    'label' => 'Publisher',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_secondary_title'.
  $field_instances['bibo_work-book_section-bibo_secondary_title'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Book title',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_serial_number'.
  $field_instances['bibo_work-book_section-bibo_serial_number'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_serial_number',
    'label' => 'ISBN',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_url'.
  $field_instances['bibo_work-book_section-bibo_url'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'bibo_work-book_section-bibo_volume'.
  $field_instances['bibo_work-book_section-bibo_volume'] = array(
    'bundle' => 'book_section',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_volume',
    'label' => 'Volume',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_abstract'.
  $field_instances['bibo_work-conference_paper-bibo_abstract'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_contributors'.
  $field_instances['bibo_work-conference_paper-bibo_contributors'] = array(
    'bundle' => 'conference_paper',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_full_text'.
  $field_instances['bibo_work-conference_paper-bibo_full_text'] = array(
    'bundle' => 'conference_paper',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_issue'.
  $field_instances['bibo_work-conference_paper-bibo_issue'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_issue',
    'label' => 'Issue',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_pages'.
  $field_instances['bibo_work-conference_paper-bibo_pages'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Page range',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 8,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_place'.
  $field_instances['bibo_work-conference_paper-bibo_place'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_place',
    'label' => 'Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'bibo_work-conference_paper-bibo_publication_status'.
  $field_instances['bibo_work-conference_paper-bibo_publication_status'] = array(
    'bundle' => 'conference_paper',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 'accepted',
        'in_press' => 0,
        'published' => 'published',
        'submitted' => 'submitted',
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_publisher'.
  $field_instances['bibo_work-conference_paper-bibo_publisher'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publisher',
    'label' => 'Publisher',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_secondary_title'.
  $field_instances['bibo_work-conference_paper-bibo_secondary_title'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Proceedings title',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_serial_number'.
  $field_instances['bibo_work-conference_paper-bibo_serial_number'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_serial_number',
    'label' => 'ISBN',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_url'.
  $field_instances['bibo_work-conference_paper-bibo_url'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'bibo_work-conference_paper-bibo_volume'.
  $field_instances['bibo_work-conference_paper-bibo_volume'] = array(
    'bundle' => 'conference_paper',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_volume',
    'label' => 'Volume',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_abstract'.
  $field_instances['bibo_work-journal_article-bibo_abstract'] = array(
    'bundle' => 'journal_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_contributors'.
  $field_instances['bibo_work-journal_article-bibo_contributors'] = array(
    'bundle' => 'journal_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_full_text'.
  $field_instances['bibo_work-journal_article-bibo_full_text'] = array(
    'bundle' => 'journal_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_issue'.
  $field_instances['bibo_work-journal_article-bibo_issue'] = array(
    'bundle' => 'journal_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_issue',
    'label' => 'Issue',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_pages'.
  $field_instances['bibo_work-journal_article-bibo_pages'] = array(
    'bundle' => 'journal_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Page range',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 8,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'bibo_work-journal_article-bibo_publication_status'.
  $field_instances['bibo_work-journal_article-bibo_publication_status'] = array(
    'bundle' => 'journal_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 'accepted',
        'in_press' => 0,
        'published' => 'published',
        'submitted' => 'submitted',
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_secondary_title'.
  $field_instances['bibo_work-journal_article-bibo_secondary_title'] = array(
    'bundle' => 'journal_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Journal name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_serial_number'.
  $field_instances['bibo_work-journal_article-bibo_serial_number'] = array(
    'bundle' => 'journal_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_serial_number',
    'label' => 'ISSN',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_url'.
  $field_instances['bibo_work-journal_article-bibo_url'] = array(
    'bundle' => 'journal_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'bibo_work-journal_article-bibo_volume'.
  $field_instances['bibo_work-journal_article-bibo_volume'] = array(
    'bundle' => 'journal_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_volume',
    'label' => 'Volume',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_abstract'.
  $field_instances['bibo_work-magazine_article-bibo_abstract'] = array(
    'bundle' => 'magazine_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_contributors'.
  $field_instances['bibo_work-magazine_article-bibo_contributors'] = array(
    'bundle' => 'magazine_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_full_text'.
  $field_instances['bibo_work-magazine_article-bibo_full_text'] = array(
    'bundle' => 'magazine_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_issue'.
  $field_instances['bibo_work-magazine_article-bibo_issue'] = array(
    'bundle' => 'magazine_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_issue',
    'label' => 'Issue',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_pages'.
  $field_instances['bibo_work-magazine_article-bibo_pages'] = array(
    'bundle' => 'magazine_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Page range',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 8,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'bibo_work-magazine_article-bibo_publication_status'.
  $field_instances['bibo_work-magazine_article-bibo_publication_status'] = array(
    'bundle' => 'magazine_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 0,
        'in_press' => 'in_press',
        'published' => 'published',
        'submitted' => 0,
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_secondary_title'.
  $field_instances['bibo_work-magazine_article-bibo_secondary_title'] = array(
    'bundle' => 'magazine_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Magazine name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_serial_number'.
  $field_instances['bibo_work-magazine_article-bibo_serial_number'] = array(
    'bundle' => 'magazine_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_serial_number',
    'label' => 'ISSN',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_url'.
  $field_instances['bibo_work-magazine_article-bibo_url'] = array(
    'bundle' => 'magazine_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'bibo_work-magazine_article-bibo_volume'.
  $field_instances['bibo_work-magazine_article-bibo_volume'] = array(
    'bundle' => 'magazine_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_volume',
    'label' => 'Volume',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-newspaper_article-bibo_abstract'.
  $field_instances['bibo_work-newspaper_article-bibo_abstract'] = array(
    'bundle' => 'newspaper_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'bibo_work-newspaper_article-bibo_contributors'.
  $field_instances['bibo_work-newspaper_article-bibo_contributors'] = array(
    'bundle' => 'newspaper_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-newspaper_article-bibo_full_text'.
  $field_instances['bibo_work-newspaper_article-bibo_full_text'] = array(
    'bundle' => 'newspaper_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'bibo_work-newspaper_article-bibo_issue'.
  $field_instances['bibo_work-newspaper_article-bibo_issue'] = array(
    'bundle' => 'newspaper_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_issue',
    'label' => 'Issue',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-newspaper_article-bibo_pages'.
  $field_instances['bibo_work-newspaper_article-bibo_pages'] = array(
    'bundle' => 'newspaper_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Page',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 4,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bibo_work-newspaper_article-bibo_place'.
  $field_instances['bibo_work-newspaper_article-bibo_place'] = array(
    'bundle' => 'newspaper_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_place',
    'label' => 'Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'bibo_work-newspaper_article-bibo_publication_status'.
  $field_instances['bibo_work-newspaper_article-bibo_publication_status'] = array(
    'bundle' => 'newspaper_article',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 0,
        'in_press' => 'in_press',
        'published' => 'published',
        'submitted' => 0,
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'bibo_work-newspaper_article-bibo_secondary_title'.
  $field_instances['bibo_work-newspaper_article-bibo_secondary_title'] = array(
    'bundle' => 'newspaper_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Newspaper name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-newspaper_article-bibo_url'.
  $field_instances['bibo_work-newspaper_article-bibo_url'] = array(
    'bundle' => 'newspaper_article',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_abstract'.
  $field_instances['bibo_work-presentation-bibo_abstract'] = array(
    'bundle' => 'presentation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_contributors'.
  $field_instances['bibo_work-presentation-bibo_contributors'] = array(
    'bundle' => 'presentation',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_full_text'.
  $field_instances['bibo_work-presentation-bibo_full_text'] = array(
    'bundle' => 'presentation',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_place'.
  $field_instances['bibo_work-presentation-bibo_place'] = array(
    'bundle' => 'presentation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_place',
    'label' => 'Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_presentation_type'.
  $field_instances['bibo_work-presentation-bibo_presentation_type'] = array(
    'bundle' => 'presentation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_presentation_type',
    'label' => 'Presentation type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_publication_status'.
  $field_instances['bibo_work-presentation-bibo_publication_status'] = array(
    'bundle' => 'presentation',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 'accepted',
        'in_press' => 0,
        'published' => 'published',
        'submitted' => 'submitted',
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_secondary_title'.
  $field_instances['bibo_work-presentation-bibo_secondary_title'] = array(
    'bundle' => 'presentation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Meeting name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-presentation-bibo_url'.
  $field_instances['bibo_work-presentation-bibo_url'] = array(
    'bundle' => 'presentation',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_abstract'.
  $field_instances['bibo_work-report-bibo_abstract'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_contributors'.
  $field_instances['bibo_work-report-bibo_contributors'] = array(
    'bundle' => 'report',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 'editor',
        'thesis_supervisor' => 0,
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_full_text'.
  $field_instances['bibo_work-report-bibo_full_text'] = array(
    'bundle' => 'report',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_pages'.
  $field_instances['bibo_work-report-bibo_pages'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Number of pages',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 8,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_place'.
  $field_instances['bibo_work-report-bibo_place'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_place',
    'label' => 'Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_publication_status'.
  $field_instances['bibo_work-report-bibo_publication_status'] = array(
    'bundle' => 'report',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 0,
        'in_press' => 'in_press',
        'published' => 'published',
        'submitted' => 0,
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_publisher'.
  $field_instances['bibo_work-report-bibo_publisher'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publisher',
    'label' => 'Institution',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_report_type'.
  $field_instances['bibo_work-report-bibo_report_type'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_report_type',
    'label' => 'Report type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_secondary_title'.
  $field_instances['bibo_work-report-bibo_secondary_title'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Collection',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_serial_number'.
  $field_instances['bibo_work-report-bibo_serial_number'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_serial_number',
    'label' => 'Report number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'bibo_work-report-bibo_url'.
  $field_instances['bibo_work-report-bibo_url'] = array(
    'bundle' => 'report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_abstract'.
  $field_instances['bibo_work-thesis-bibo_abstract'] = array(
    'bundle' => 'thesis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_abstract',
    'label' => 'Abstract',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_contributors'.
  $field_instances['bibo_work-thesis-bibo_contributors'] = array(
    'bundle' => 'thesis',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(
          'display_link' => TRUE,
          'display_role' => TRUE,
          'name_format' => 'full_name',
        ),
        'type' => 'bibo_contribution_formatter_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_contributors',
    'label' => 'Contributors',
    'required' => 1,
    'settings' => array(
      'allowed_roles' => array(
        'author' => 'author',
        'book_author' => 0,
        'editor' => 0,
        'thesis_supervisor' => 'thesis_supervisor',
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_full_text'.
  $field_instances['bibo_work-thesis-bibo_full_text'] = array(
    'bundle' => 'thesis',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_full_text',
    'label' => 'Full text',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'full-text',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_pages'.
  $field_instances['bibo_work-thesis-bibo_pages'] = array(
    'bundle' => 'thesis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_pages',
    'label' => 'Number of pages',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 8,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_place'.
  $field_instances['bibo_work-thesis-bibo_place'] = array(
    'bundle' => 'thesis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_place',
    'label' => 'Place',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_publication_status'.
  $field_instances['bibo_work-thesis-bibo_publication_status'] = array(
    'bundle' => 'thesis',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bibo',
        'settings' => array(),
        'type' => 'bibo_publication_status_formatter_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publication_status',
    'label' => 'Publication status',
    'required' => 1,
    'settings' => array(
      'allowed_statuses' => array(
        'accepted' => 0,
        'in_press' => 0,
        'published' => 'published',
        'submitted' => 0,
        'unpublished' => 'unpublished',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_publication_status_widget_default',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_publisher'.
  $field_instances['bibo_work-thesis-bibo_publisher'] = array(
    'bundle' => 'thesis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_publisher',
    'label' => 'University',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_secondary_title'.
  $field_instances['bibo_work-thesis-bibo_secondary_title'] = array(
    'bundle' => 'thesis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_secondary_title',
    'label' => 'Thesis degree',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_thesis_type'.
  $field_instances['bibo_work-thesis-bibo_thesis_type'] = array(
    'bundle' => 'thesis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_thesis_type',
    'label' => 'Thesis type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bibo_work-thesis-bibo_url'.
  $field_instances['bibo_work-thesis-bibo_url'] = array(
    'bundle' => 'thesis',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bibo_work',
    'field_name' => 'bibo_url',
    'label' => 'URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 12,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Abstract');
  t('Book title');
  t('Collection');
  t('Contributors');
  t('Edition');
  t('Full name');
  t('Full text');
  t('ISBN');
  t('ISSN');
  t('Institution');
  t('Issue');
  t('Journal name');
  t('Magazine name');
  t('Meeting name');
  t('Newspaper name');
  t('Number of pages');
  t('Page');
  t('Page range');
  t('Place');
  t('Presentation type');
  t('Proceedings title');
  t('Publication status');
  t('Publisher');
  t('Report number');
  t('Report type');
  t('Thesis degree');
  t('Thesis type');
  t('URL');
  t('University');
  t('Volume');

  return $field_instances;
}
