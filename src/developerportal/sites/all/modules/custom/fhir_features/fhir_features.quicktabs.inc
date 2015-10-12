<?php
/**
 * @file
 * fhir_features.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function fhir_features_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'latest_apps';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Latest Apps';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'app_gallery',
      'display' => 'grid_view',
      'args' => '',
      'title' => ' ',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'app_gallery',
      'display' => 'list_view',
      'args' => '',
      'title' => ' ',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' ');
  t('Latest Apps');

  $export['latest_apps'] = $quicktabs;

  return $export;
}
