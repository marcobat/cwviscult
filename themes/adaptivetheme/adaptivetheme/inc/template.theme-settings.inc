<?php // $Id: template.theme-settings.inc,v 1.2.2.1 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 * template.theme-settings.inc
 */

/**
 * Return the default values from the info file
 * and save them into the database. The theme settings functions
 * code mostly comes from the Zen theme, whose inplimentation
 * for subthemes is superb.
 *
 * @param $theme
 *   The name of theme.
 */
function adaptivetheme_theme_get_default_settings($theme) {
  $themes = list_themes();
  $defaults = !empty($themes[$theme]->info['settings']) ? $themes[$theme]->info['settings'] : array();
  if (!empty($defaults)) {
    $settings = theme_get_settings($theme);
    if (module_exists('node')) {
      foreach (node_get_types() as $type => $name) {
        unset($settings['toggle_node_info_'. $type]);
      }
    }
    variable_set(
      str_replace('/', '_', 'theme_'. $theme .'_settings'),
      array_merge($defaults, $settings)
    );
    if (!empty($GLOBALS['theme_key'])) {
      theme_get_setting('', TRUE);
    }
  }
  return $defaults;
}
