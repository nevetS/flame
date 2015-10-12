<?php
/**
 * @file
 * fhir_features.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fhir_features_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|apps|dexp_portfolio';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'apps';
  $ds_fieldsetting->view_mode = 'dexp_portfolio';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'Strong',
        'class' => 'app-gallery',
      ),
    ),
  );
  $export['node|apps|dexp_portfolio'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|apps|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'apps';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => 'app-details-title',
      ),
    ),
    'changed_date' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|apps|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|apps|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'apps';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'Strong',
        'class' => 'app-gallery',
      ),
    ),
  );
  $export['node|apps|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function fhir_features_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|apps|dexp_portfolio';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'apps';
  $ds_layout->view_mode = 'dexp_portfolio';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_app_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_one_liner',
        3 => 'field_app_categories',
        4 => 'field_website',
      ),
    ),
    'fields' => array(
      'field_app_image' => 'left',
      'title' => 'right',
      'field_one_liner' => 'right',
      'field_app_categories' => 'right',
      'field_website' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|apps|dexp_portfolio'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|apps|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'apps';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_app_image',
        1 => 'field_app_video',
      ),
      'right' => array(
        2 => 'title',
        3 => 'field_author_name',
        4 => 'field_website',
        5 => 'field_app_categories',
        6 => 'changed_date',
      ),
      'footer' => array(
        7 => 'body',
      ),
    ),
    'fields' => array(
      'field_app_image' => 'left',
      'field_app_video' => 'left',
      'title' => 'right',
      'field_author_name' => 'right',
      'field_website' => 'right',
      'field_app_categories' => 'right',
      'changed_date' => 'right',
      'body' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 1,
  );
  $export['node|apps|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|apps|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'apps';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_app_image',
        1 => 'title',
        2 => 'field_one_liner',
        3 => 'field_website',
      ),
    ),
    'fields' => array(
      'field_app_image' => 'ds_content',
      'title' => 'ds_content',
      'field_one_liner' => 'ds_content',
      'field_website' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => 'role="description"',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|apps|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|app_categories|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'app_categories';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'description',
      ),
    ),
    'fields' => array(
      'description' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['taxonomy_term|app_categories|default'] = $ds_layout;

  return $export;
}
