<?php

/**
 * @file
 * Contains the basic 'work' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a work.
 * Definition terms:
 * - link_to_work default: Should this field have the checkbox "link to work" enabled by default.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_work extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    // Don't add the additional fields to groupby
    if (!empty($this->options['link_to_work'])) {
      $this->additional_fields['bibo_work_id'] = array('table' => 'bibo_work', 'field' => 'bibo_work_id');
      if (module_exists('translation')) {
        $this->additional_fields['language'] = array('table' => 'bibo_work', 'field' => 'language');
      }
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_work'] = array('default' => isset($this->definition['link_to_work default']) ? $this->definition['link_to_work default'] : FALSE, 'bool' => TRUE);
    return $options;
  }

  /**
   * Provide link to node option
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_work'] = array(
      '#title' => t('Link this field to the original work'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_work']),
    );

    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the work.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_work']) && !empty($this->additional_fields['bibo_work_id'])) {
      if ($data !== NULL && $data !== '') {
        $this->options['alter']['make_link'] = TRUE;
        $this->options['alter']['path'] = "work/" . $this->get_value($values, 'bibo_work_id');
        if (isset($this->aliases['language'])) {
          $languages = language_list();
          $language = $this->get_value($values, 'language');
          if (isset($languages[$language])) {
            $this->options['alter']['language'] = $languages[$language];
          }
          else {
            unset($this->options['alter']['language']);
          }
        }
      }
      else {
        $this->options['alter']['make_link'] = FALSE;
      }
    }
    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }
}
