<?php
/**
 * @file
 * bibo_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function bibo_feeds_feeds_importer_default() {
  $export = array();

  if (module_exists('feeds_zotero')) {
    $feeds_importer = new stdClass();
    $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
    $feeds_importer->api_version = 1;
    $feeds_importer->id = 'bibo_zotero';
    $feeds_importer->config = array(
      'name' => 'BIBO Zotero',
      'description' => '',
      'fetcher' => array(
        'plugin_key' => 'FeedsZoteroFetcher',
        'config' => array(
          'zotero_type' => '',
          'zotero_id' => '',
          'api_key' => '',
        ),
      ),
      'parser' => array(
        'plugin_key' => 'FeedsZoteroParser',
        'config' => array(),
      ),
      'processor' => array(
        'plugin_key' => 'FeedsBIBOProcessor',
        'config' => array(
          'mappings' => array(
            0 => array(
              'source' => 'key',
              'target' => 'guid',
              'unique' => 1,
              'language' => 'und',
            ),
            1 => array(
              'source' => 'itemType',
              'target' => 'type',
              'unique' => FALSE,
              'language' => 'und',
            ),
            2 => array(
              'source' => 'title',
              'target' => 'title',
              'unique' => FALSE,
              'language' => 'und',
            ),
            3 => array(
              'source' => 'creator:author',
              'target' => 'bibo_contributors:author',
              'unique' => FALSE,
              'language' => 'und',
            ),
            4 => array(
              'source' => 'creator:bookAuthor',
              'target' => 'bibo_contributors:book_author',
              'unique' => FALSE,
              'language' => 'und',
            ),
            5 => array(
              'source' => 'creator:editor',
              'target' => 'bibo_contributors:editor',
              'unique' => FALSE,
              'language' => 'und',
            ),
            6 => array(
              'source' => 'creator:presenter',
              'target' => 'bibo_contributors:author',
              'unique' => FALSE,
              'language' => 'und',
            ),
            7 => array(
              'source' => 'creator:translator',
              'target' => 'bibo_contributors:translator',
              'unique' => FALSE,
              'language' => 'und',
            ),
            8 => array(
              'source' => 'date',
              'target' => 'bibo_publication_status',
              'unique' => FALSE,
              'language' => 'und',
            ),
            9 => array(
              'source' => 'seriesTitle',
              'target' => 'bibo_secondary_title',
              'unique' => FALSE,
              'language' => 'und',
            ),
            10 => array(
              'source' => 'bookTitle',
              'target' => 'bibo_secondary_title',
              'unique' => FALSE,
              'language' => 'und',
            ),
            11 => array(
              'source' => 'proceedingsTitle',
              'target' => 'bibo_secondary_title',
              'unique' => FALSE,
              'language' => 'und',
            ),
            12 => array(
              'source' => 'publicationTitle',
              'target' => 'bibo_secondary_title',
              'unique' => FALSE,
              'language' => 'und',
            ),
            13 => array(
              'source' => 'meetingName',
              'target' => 'bibo_secondary_title',
              'unique' => FALSE,
              'language' => 'und',
            ),
            14 => array(
              'source' => 'publisher',
              'target' => 'bibo_publisher',
              'unique' => FALSE,
              'language' => 'und',
            ),
            15 => array(
              'source' => 'institution',
              'target' => 'bibo_publisher',
              'unique' => FALSE,
              'language' => 'und',
            ),
            16 => array(
              'source' => 'university',
              'target' => 'bibo_publisher',
              'unique' => FALSE,
              'language' => 'und',
            ),
            17 => array(
              'source' => 'place',
              'target' => 'bibo_place',
              'unique' => FALSE,
              'language' => 'und',
            ),
            18 => array(
              'source' => 'volume',
              'target' => 'bibo_volume',
              'unique' => FALSE,
              'language' => 'und',
            ),
            19 => array(
              'source' => 'edition',
              'target' => 'bibo_issue',
              'unique' => FALSE,
              'language' => 'und',
            ),
            20 => array(
              'source' => 'issue',
              'target' => 'bibo_issue',
              'unique' => FALSE,
              'language' => 'und',
            ),
            21 => array(
              'source' => 'numPages',
              'target' => 'bibo_pages',
              'unique' => FALSE,
              'language' => 'und',
            ),
            22 => array(
              'source' => 'pages',
              'target' => 'bibo_pages',
              'unique' => FALSE,
              'language' => 'und',
            ),
            23 => array(
              'source' => 'ISBN',
              'target' => 'bibo_serial_number',
              'unique' => FALSE,
              'language' => 'und',
            ),
            24 => array(
              'source' => 'ISSN',
              'target' => 'bibo_serial_number',
              'unique' => FALSE,
              'language' => 'und',
            ),
            25 => array(
              'source' => 'reportNumber',
              'target' => 'bibo_serial_number',
              'unique' => FALSE,
              'language' => 'und',
            ),
            26 => array(
              'source' => 'abstractNote',
              'target' => 'bibo_abstract',
              'unique' => FALSE,
              'language' => 'und',
            ),
            27 => array(
              'source' => 'url',
              'target' => 'bibo_url:url',
              'unique' => FALSE,
              'language' => 'und',
            ),
            28 => array(
              'source' => 'DOI',
              'target' => 'bibo_doi',
              'unique' => FALSE,
              'language' => 'und',
            ),
            29 => array(
              'source' => 'presentationType',
              'target' => 'bibo_presentation_type',
              'unique' => FALSE,
              'language' => 'und',
            ),
            30 => array(
              'source' => 'reportType',
              'target' => 'bibo_report_type',
              'unique' => FALSE,
              'language' => 'und',
            ),
            31 => array(
              'source' => 'thesisType',
              'target' => 'bibo_thesis_type',
              'unique' => FALSE,
              'language' => 'und',
            ),
          ),
          'insert_new' => '1',
          'update_existing' => '2',
          'update_non_existent' => 'skip',
          'input_format' => 'plain_text',
          'skip_hash_check' => 1,
          'bundle' => NULL,
          'language' => 'und',
        ),
      ),
      'content_type' => '',
      'update' => 0,
      'import_period' => '-1',
      'expire_period' => 3600,
      'import_on_create' => 1,
      'process_in_background' => 0,
    );
    $export['bibo_zotero'] = $feeds_importer;
  }

  return $export;
}
