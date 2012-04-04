<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function answers_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-answers
  $menus['menu-answers'] = array(
    'menu_name' => 'menu-answers',
    'title' => 'Using Answers',
    'description' => 'Quick access to Q&A',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Quick access to Q&A');
  t('Using Answers');


  return $menus;
}
