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
      'weight' => 2,
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
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 2,
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
      'weight' => 4,
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
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 2,
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
      'weight' => 4,
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
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 2,
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
      'weight' => 4,
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
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 2,
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
      'weight' => 4,
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
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 2,
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
      'weight' => 4,
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
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
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
      'weight' => 4,
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
        'translator' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'bibo',
      'settings' => array(),
      'type' => 'bibo_contribution_widget_default',
      'weight' => 2,
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
      'weight' => 4,
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
      'weight' => 2,
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
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contributors');
  t('Full name');
  t('Publication status');

  return $field_instances;
}
