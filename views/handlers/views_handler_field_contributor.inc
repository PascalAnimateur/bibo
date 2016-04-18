<?php

/**
 * @file
 * Contains the basic 'contributor' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a contributor.
 * Definition terms:
 * - link_to_contributor default: Should this field have the checkbox "link to contributor" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_contributor extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    // Don't add the additional fields to groupby
    if (!empty($this->options['link_to_contributor'])) {
      $this->additional_fields['bibo_contributor_id'] = array('table' => 'bibo_contributor', 'field' => 'bibo_contributor_id');
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['name_format'] = array(
      'default' => isset($this->definition['name_format default']) ? $this->definition['name_format default'] : FALSE,
    );
    $options['link_to_contributor'] = array(
      'default' => isset($this->definition['link_to_contributor default']) ? $this->definition['link_to_contributor default'] : FALSE,
      'bool' => TRUE
    );
    return $options;
  }

  /**
   * Provide link to node option
   */
  function options_form(&$form, &$form_state) {
    $form['name_format'] = array(
      '#title' => t('Name format'),
      '#type' => 'select',
      '#options' => _bibo_get_default_name_formats(),
      '#default_value' => isset($this->options['name_format']) ? $this->options['name_format'] : BIBO_NAME_FORMAT_LAST_FIRST,
    );
    $form['link_to_contributor'] = array(
      '#title' => t('Link this field to the original contributor'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_contributor']),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the contributor.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_contributor']) && !empty($this->additional_fields['bibo_contributor_id'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;
        $this->options['alter']['path'] = "contributor/" . $this->get_value($values, 'bibo_contributor_id');
        unset($this->options['alter']['language']);
      }
      else {
        $this->options['alter']['make_link'] = FALSE;
      }
    }
    return $data;
  }

  function render($values) {
    $name_format = isset($this->options['name_format']) ? $this->options['name_format'] : BIBO_NAME_FORMAT_LAST_FIRST;
    $name = bibo_contributor_label(bibo_contributor_load($values->bibo_contributor_id), 'bibo_contributor', $name_format);
    return $this->render_link($this->sanitize_value($name), $values);
  }
}
