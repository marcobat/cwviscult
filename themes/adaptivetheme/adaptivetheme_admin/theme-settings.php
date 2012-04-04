<?php // $Id: theme-settings.php,v 1.2.2.1 2010/08/31 10:18:42 jmburnz Exp $
// adaptivethemes.com admin

/**
 * @file theme-settings.php
 */

// Include the definition of adaptivetheme_settings() and adaptivetheme_theme_get_default_settings().
include_once(drupal_get_path('theme', 'adaptivetheme') .'/theme-settings.php');

/**
 * Implementation of themehook_settings() function.
 *
 * @param $saved_settings
 *   An array of saved settings for this theme.
 * @return
 *   A form array.
 */
function adaptivetheme_admin_settings($saved_settings) {

  // Get the default values from the .info file.
  $defaults = adaptivetheme_theme_get_default_settings('adaptivetheme_admin');

  // Merge the saved variables and their default values.
  $settings = array_merge($defaults, $saved_settings);

  // Create the form using Forms API: http://api.drupal.org/api/6
  $form = array();

  // Style schemes
  if ($settings['style_enable_schemes'] == 'on') {
    $form['style'] = array(
      '#type' => 'fieldset',
      '#title' => t('Style settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => 90,
      '#description'   => t('Change the color scheme of your admin theme.'),
    );
    $form['style']['style_schemes'] = array(
      '#type' => 'select',
      '#title' => t('Color Schemes'),
      '#default_value' => $settings['style_schemes'],
      '#options' => array(
        'style-default.css' => t('Onyx'),
        'ruby.css' => t('Ruby'),
        'saphire.css' => t('Saphire'),
        'amber.css' => t('Amber'),
        'emerald.css' => t('Emerald'),
      ),
    );
    $form['style']['style_enable_schemes'] = array(
      '#type' => 'hidden',
      '#value' => $settings['style_enable_schemes'],
    );
  }

  // Add the base theme's settings.
  $form += adaptivetheme_settings($saved_settings, $defaults);

  // Return the form
  return $form;
}
