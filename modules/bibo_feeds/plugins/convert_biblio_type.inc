<?php

/**
 * @file
 * Convert default Biblio type ID to BIBO type name.
 */

$plugin = array(
  'form' => 'feeds_tamper_convert_biblio_type_form',
  'callback' => 'feeds_tamper_convert_biblio_type_callback',
  'name' => 'Convert Biblio type',
  'multi' => 'direct',
  'category' => 'Other',
);

function feeds_tamper_convert_biblio_type_form($importer, $element_key, $settings) {
  return array(
    'help' => array(
      '#markup' => t('Converts the Biblio type ID to BIBO work type name.'),
    ),
    'override' => array(
    ),
  );
}

function feeds_tamper_convert_biblio_type_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $biblio_type_mapping = array(
    '100' => 'book',
    '101' => 'bookSection',
    '102' => 'journalArticle',
    '103' => 'conferencePaper',
    '104' => 'conferenceProceedings',
    '105' => 'newspaperArticle',
    '106' => 'magazineArticle',
    '107' => 'webArticle',
    '108' => 'thesis',
    '109' => 'report',
    '110' => 'film',
    '111' => 'broadcast',
    '112' => 'artwork',
    '113' => 'software',
    '114' => 'audiovisual',
    '115' => 'hearing',
    '116' => 'case',
    '117' => 'bill',
    '118' => 'statute',
    '119' => 'patent',
    '120' => 'personal',
    '121' => 'manuscript',
    '122' => 'map',
    '123' => 'chart',
    '124' => 'unpublished',
    '125' => 'database',
    '126' => 'governmentReport',
    '127' => 'classical',
    '128' => 'legalRuling',
    '129' => 'miscellaneous',
    '130' => 'miscellaneousSection',
    '131' => 'journal',
    '132' => 'website',
    '133' => 'webService',
    '134' => 'webProjectPage',
    '135' => 'presentation',
    'Article de colloque' => 'conferencePaper',
    'Article de journal' => 'newspaperArticle',
    'Article de magazine' => 'magazineArticle',
    'Article de revue' => 'journalArticle',
    'Chapitre de livre' => 'bookSection',
    'Communication' => 'presentation',
    'Livre' => 'book',
    'Rapport' => 'report',
    'Thèse' => 'thesis',
  );

  $field = isset($biblio_type_mapping[$field]) ? $biblio_type_mapping[$field] : '';
}
