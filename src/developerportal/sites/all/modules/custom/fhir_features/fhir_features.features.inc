<?php
/**
 * @file
 * fhir_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fhir_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fhir_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function fhir_features_image_default_styles() {
  $styles = array();

  // Exported image style: 265x190.
  $styles['265x190'] = array(
    'label' => '265x190',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 190,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blog_large_image.
  $styles['blog_large_image'] = array(
    'label' => 'Blog Large Image',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 870,
          'height' => 353,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blog_timeline.
  $styles['blog_timeline'] = array(
    'label' => 'Blog Timeline',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 502,
          'height' => 265,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium_blog.
  $styles['medium_blog'] = array(
    'label' => 'Medium Blog',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 219,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function fhir_features_node_info() {
  $items = array(
    'apps' => array(
      'name' => t('Apps'),
      'base' => 'node_content',
      'description' => t('Use <em>Apps</em> for App Gallery Content'),
      'has_title' => '1',
      'title_label' => t('Apps'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'clients' => array(
      'name' => t('Clients'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'dexp_portfolio' => array(
      'name' => t('Portfolio'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'feed' => array(
      'name' => t('Feed'),
      'base' => 'node_content',
      'description' => t('Feed'),
      'has_title' => '1',
      'title_label' => t('Feed'),
      'help' => '',
    ),
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
