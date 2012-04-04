<?php // $Id: template.php,v 1.2.2.4 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 * Modify and add stuff.
 */
if (db_is_active()) {
  function adaptivetheme_theme() {
    return array(
      'system_settings_form' => array(
        'arguments' => array('form' => NULL, 'key' => 'adaptivetheme'),
      ),
    );
    include(drupal_get_path('theme', 'adaptivetheme') .'/inc/template.theme-settings.inc');
  }
   function adaptivetheme_preprocess(&$vars, $hook) {
    global $user;
    $vars['theme_path'] = path_to_theme() .'/';
    $vars['in_maintenance'] = MAINTENANCE_MODE;
    if (is_file(drupal_get_path('theme', 'adaptivetheme') .'/inc/template.preprocess-'. str_replace('_', '-', $hook) .'.inc')) {
      include(drupal_get_path('theme', 'adaptivetheme') .'/inc/template.preprocess-'. str_replace('_', '-', $hook) .'.inc');
    }
  }
  include_once(drupal_get_path('theme', 'adaptivetheme') .'/inc/template.custom-functions.inc');
  include_once(drupal_get_path('theme', 'adaptivetheme') .'/inc/template.theme-overrides.inc');
  include_once(drupal_get_path('theme', 'adaptivetheme') .'/inc/template.theme-js.inc');
  if (theme_get_setting('rebuild_registry')) {
    drupal_set_message(t('The theme registry has been rebuilt. <a href="!link">Turn off</a> this feature on production websites.', array('!link' => url('admin/build/themes/settings/'. $GLOBALS['theme']))), 'warning');
  }
  if (theme_get_setting('block_edit_links')) {
    drupal_add_css(drupal_get_path('theme', 'adaptivetheme') .'/css/edit-links.css', 'theme');
  }
}