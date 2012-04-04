<?php // $Id: theme-settings.php,v 1.2.2.4 2010/10/14 16:15:10 jmburnz Exp $

// DONT TOUCH THIS LINE:
include_once(drupal_get_path('theme', 'adaptivetheme') .'/theme-settings.php');

/**
* USAGE:
* 1 - Change all instances of "adaptivetheme_subtheme" to your themes name (there are only 2).
* 2 - Set "style_enable_schemes" to "on" in your themes info file (right at the bottom).
* 3 - See template.php for the changes you need to make there.
*/

// Change 'adaptivetheme_subtheme_settings' to 'your_themes_name_settings'
function adaptivetheme_subtheme_settings($saved_settings) {

  // Change ('adaptivetheme_subtheme') to ('your_themes_name')
  $defaults = adaptivetheme_theme_get_default_settings('adaptivetheme_subtheme');

  $settings = array_merge($defaults, $saved_settings);
  $form = array();

  // Style schemes
  if ($settings['style_enable_schemes'] == 'on') {
    $form['style'] = array(
      '#type' => 'fieldset',
      '#title' => t('Style settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => 90,
      '#description'   => t('Use these settings to modify the style - such as the color scheme. If no stylesheet is selected the default styles will apply.'),
    );
    $form['style']['style_schemes'] = array(
      '#type' => 'select',
      '#title' => t('Styles'),
      '#default_value' => $settings['style_schemes'],
      '#options' => array(
        'style-default.css' => t('Default Style'),
        // 'my-style.css' => t('My Style'), // Add your own schemes (must go in your themes /schemes directory)
      ),
    );
    $form['style']['style_enable_schemes'] = array(
      '#type' => 'hidden',
      '#value' => $settings['style_enable_schemes'],
    );
  } // endif schemes

  // DONT TOUCH THIS LINE.
  $form += adaptivetheme_settings($saved_settings, $defaults);

  // Return the form
  return $form;
}