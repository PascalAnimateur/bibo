<?php

/**
 * Creates works from feed items.
 */
class FeedsBIBOProcessor extends FeedsProcessor {

  /**
   * Define entity type.
   */
  public function entityType() {
    return 'bibo_work';
  }

  /**
   * Save a work.
   */
  public function entitySave($entity) {
    entity_save('bibo_work', $entity);
  }

  /**
   * Delete a series of works.
   */
  protected function entityDeleteMultiple($ids) {
    entity_delete_multiple('bibo_work', $ids);
  }


  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    // Bundle is determined dynamically from $parser_result.
    unset($form['bundle']);

    return $form;
  }

  /**
   * Declare possible mapping targets that this processor exposes.
   */
  public function getMappingTargets() {
    $targets = array();

    $targets['guid'] = array(
      'name' => t('GUID'),
      'description' => t('The globally unique identifier of the item. E. g. the feed item GUID in the case of a syndication feed. May be unique.'),
      'optional_unique' => TRUE,
    );
    $targets['bibo_work_id'] = array(
      'name' => t('Work ID'),
      'description' => t('The ID of the work. NOTE: use this feature with care, ids are usually assigned by Drupal.'),
      'optional_unique' => TRUE,
    );
    $targets['type'] = array(
      'name' => t('Work type'),
      'description' => t('The type of work to import.'),
    );
    $targets['title'] = array(
      'name' => t('Title'),
      'description' => t('The title of the work.'),
      'optional_unique' => TRUE,
    );
    $targets['created'] = array(
      'name' => t('Creation date'),
      'description' => t('The Unix timestamp when the work was created.'),
    );
    $targets['changed'] = array(
      'name' => t('Updated date'),
      'description' => t('The Unix timestamp when the work was most recently saved.'),
    );

    $this->getHookTargets($targets);

    return $targets;
  }

  /**
   * Execute mapping on an item.
   */
  protected function map(FeedsSource $source, FeedsParserResult $result, $target_item = NULL) {
    $targets = $this->getCachedTargets();
    if (!isset($result->current_item['type'])) {
      drupal_set_message(t('Could not determine work type from parsed result. Make sure type is properly mapped and populated.'), 'error');
      return array();
    }

    // Get fields for the work type we are mapping to.
    $fields = field_info_instances($this->entityType(), $result->current_item['type']);

    if (empty($target_item)) {
      $target_item = array();
    }

    foreach ($this->getMappings() as $mapping) {
      if (isset($targets[$mapping['target']]['real_target'])) {
        $target_name = $targets[$mapping['target']]['real_target'];
      }
      else {
        $target_name = $mapping['target'];
      }
      if (isset($fields[$target_name])) {
        $target_item->{$target_name}[$mapping['language']] = array();
      }
      else {
        $target_item->{$target_name} = NULL;
      }
    }

    foreach ($this->getMappings() as $mapping) {
      $value = $this->getSourceValue($source, $result, $mapping['source']);
      $this->mapToTarget($source, $mapping['target'], $target_item, $value, $mapping);
    }

    return $target_item;
  }

  /**
   * Override setTargetElement to operate on a target item that is a work.
   */
  public function setTargetElement(FeedsSource $source, $target_work, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_work->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;

      case 'changed':
        $target_work->feeds_item->node_changed = feeds_to_unixtime($value, REQUEST_TIME);
        break;

      case 'title':
        $target_work->title = $value;
        break;

      case 'type':
        $target_work->type = $value;
        break;

      default:
        parent::setTargetElement($source, $target_work, $target_element, $value);
        break;
    }
  }
}
