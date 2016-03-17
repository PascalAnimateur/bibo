<?php

/**
 * Field handler to present a contributor delete link.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_contributor_link_delete extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['bibo_contributor_id'] = 'bibo_contributor_id';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    // Check there is an actual value, as on a relationship there may not be.
    if ($bibo_contributor_id = $this->get_value($values, 'bibo_contributor_id')) {
      if (user_access('administer bibo_contributors')) {
        $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
        $bibo_contributor_id = $this->get_value($values, 'bibo_contributor_id');
        return l($text, 'admin/people/contributor/manage/'. $bibo_contributor_id . '/delete', array('query' => drupal_get_destination()));
      }
    }
  }
}
