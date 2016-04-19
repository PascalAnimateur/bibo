<?php

/**
 * @file
 * Contains the custom 'publication_status' field handler.
 */

class views_handler_field_publication_status extends views_handler_field_field {

  function click_sort($order) {
    parent::click_sort($order);
    $columns = array(
      $this->definition['field_name'] . '_year',
      $this->definition['field_name'] . '_month',
      $this->definition['field_name'] . '_day'
    );
    foreach ($columns as $column) {
      if (!isset($this->aliases[$column])) {
        // Column is not in query; add a sort on it (without adding the column).
        $this->aliases[$column] = $this->table_alias . '.' . $column;
        $this->query->add_orderby(NULL, NULL, $order, $this->aliases[$column]);
      }
    }
  }
  
}
