<?php // $Id: template.preprocess-block.inc,v 1.2.2.3 2010/10/14 05:38:01 jmburnz Exp $

/**
 * @file
 * Override or insert variables into block templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called.
 */
global $theme, $user;
$block = $vars['block'];

if ($block->region == 'left') {
  $block->region = 'sidebar-first';
}
if ($block->region == 'right') {
  $block->region = 'sidebar-last';
}

$vars['block_module_delta'] = 'block-'. $block->module .'-'. $block->delta;

$classes = array();
$classes[] = 'block';
$classes[] = 'block-'. $block->module;
if (isset($vars['blocktheme'])) {
  $classes[] = $vars['blocktheme'];
  $classes[] = safe_string($block->region) .'-'. $vars['blocktheme'];
}
if (function_exists('block_class') && block_class($block)) {
  $classes[] = block_class($block);
  $classes[] = safe_string($block->region) .'-'. block_class($block);
}
if (!empty($vars['skinr'])) {
  $classes[] = $vars['skinr'];
  $classes[] = 'skinr-block';
}
if (theme_get_setting('block_edit_links') && user_access('administer blocks')) {
  $classes[] = 'block-edit-links';
}
if (theme_get_setting('horizontal_login_block') && $block->module == 'user' && $block->delta == '0') {
  $classes[] = 'at-horizontal-login clearfix';
}
if ($block->module == 'search' && $block->delta == 0) {
  if (theme_get_setting('display_search_form_label') == 0) {
    $classes[] = 'hide-label';
  }
}
if (theme_get_setting('extra_block_classes')) {
  $classes[] = 'block-'. $vars['block_zebra'];
  $classes[] = 'block-region-'. safe_string($block->region);
  $classes[] = 'block-count-'. $vars['id'];
}
$vars['classes'] = implode(' ', $classes);

$title_classes = array();
$title_classes[] = 'title';
$title_classes[] = 'block-title';
if ($block->module == 'superfish' && $block->region == 'menu_bar') {
  $title_classes[] = 'element-invisible';
}
$vars['title_classes'] = implode(' ', $title_classes);

$content_classes = array();
$content_classes[] = 'content';
$content_classes[] = 'block-content';
if ($block->module == 'superfish') {
  $content_classes[] = 'clearfix';
}
$vars['content_classes'] = implode(' ', $content_classes);

$vars['edit_links_array'] = array();
$vars['edit_links'] = '';
if (theme_get_setting('block_edit_links') && user_access('administer blocks')) {
  include_once './'. drupal_get_path('theme', 'adaptivetheme') .'/inc/template.block-editing.inc';
  adaptivetheme_preprocess_block_editing($vars, $hook);
}

if (theme_get_setting('slider_login_block') && $vars['block_module_delta'] == 'block-user-0') {
 $vars['template_files'][] = 'block-slider-login';
}