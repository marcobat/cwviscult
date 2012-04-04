<?php // $Id: template.theme-js.inc,v 1.2.2.2 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 * Load Javascript files as required.
 */
$path_to_js_core = drupal_get_path('theme', 'adaptivetheme') .'/js/';
$regions = array(
  'leaderboard',
  'header',
  'secondary-content',
  'content-top',
  'content-bottom',
  'tertiary-content',
  'footer'
);
foreach ($regions as $region) {
  $setting = theme_get_setting('equalize_'. $region);
  if ($setting == 1) {
    $active_regions[] = $region;
  }
}
if (!empty($active_regions)) {
  $active_regions_list = $active_regions;
  drupal_add_js(array('active_regions' => $active_regions_list), 'setting');
  drupal_add_js($path_to_js_core .'equalize-blocks.js', 'theme', 'header', FALSE, TRUE, TRUE);
}
if (theme_get_setting('equal_heights_sidebars')) {
  drupal_add_js($path_to_js_core .'equalize-columns.js', 'theme', 'header', FALSE, TRUE, TRUE);
}
if (theme_get_setting('equal_heights_gpanels')) {
  drupal_add_js($path_to_js_core .'equalize-gpanels.js', 'theme', 'header', FALSE, TRUE, TRUE);
}
if (theme_get_setting('slider_login_block')) {
  drupal_add_js($path_to_js_core .'loginslider.js', 'theme', 'header', FALSE, TRUE, TRUE);
}