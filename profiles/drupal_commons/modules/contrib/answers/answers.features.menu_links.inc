<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function answers_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-answers:node/add/question
  $menu_links['menu-answers:node/add/question'] = array(
    'menu_name' => 'menu-answers',
    'link_path' => 'node/add/question',
    'router_path' => 'node/add/question',
    'link_title' => 'Ask a new question (without search)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-answers:questions/all
  $menu_links['menu-answers:questions/all'] = array(
    'menu_name' => 'menu-answers',
    'link_path' => 'questions/all',
    'router_path' => 'questions/all',
    'link_title' => 'View all questions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-answers:questions/search
  $menu_links['menu-answers:questions/search'] = array(
    'menu_name' => 'menu-answers',
    'link_path' => 'questions/search',
    'router_path' => 'questions/search',
    'link_title' => 'Search for a question',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-answers:questions/start_ask
  $menu_links['menu-answers:questions/start_ask'] = array(
    'menu_name' => 'menu-answers',
    'link_path' => 'questions/start_ask',
    'router_path' => 'questions/start_ask',
    'link_title' => 'Ask a new question (with search)',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-answers:questions/unanswered
  $menu_links['menu-answers:questions/unanswered'] = array(
    'menu_name' => 'menu-answers',
    'link_path' => 'questions/unanswered',
    'router_path' => 'questions/unanswered',
    'link_title' => 'View unanswered questions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ask a new question (with search)');
  t('Ask a new question (without search)');
  t('Search for a question');
  t('View all questions');
  t('View unanswered questions');


  return $menu_links;
}
