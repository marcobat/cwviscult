<?php // $Id: template.preprocess-page.inc,v 1.2.2.3 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 * Override or insert variables into page templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called.
 */
global $theme, $theme_info, $language;

if($vars['in_maintenance'] && !$vars['logged_in'] && arg(0) == 'user') {
  $vars['template_files'][] = 'maintenance-page';
  $vars['head_title'] = drupal_set_title(t('User Login'));
  $vars['title'] = drupal_set_title(t('User Login'));
}

if ($vars['content_front'] && $vars['is_front']) {
  $vars['content'] = $vars['content_front'];
}

if ($vars['help'] == "<div class=\"help\"> \n</div>") {
  $vars['help'] = '';
}

if (!$vars['show_blocks']) {
  $vars['left'] = '';
  $vars['right'] = '';
}

if (theme_get_setting('skip_navigation_display') == 'hide') {
  $vars['skip_nav_class'] = 'element-invisible';
}
if (theme_get_setting('skip_navigation_display') == 'show') {
  $vars['skip_nav_class'] = 'show';
}
if (theme_get_setting('skip_navigation_display') == 'focus') {
  $vars['skip_nav_class'] = 'show-on-focus';
}

$vars['logo_alt_text']    = check_plain(variable_get('site_name', '')) .' '. t('logo');
$vars['logo_img']         = $vars['logo'] ? '<img src="'. check_url($vars['logo']) .'" alt="'. $vars['logo_alt_text'] .'" title="'. t('Home page') .'"/>' : '';
$vars['linked_site_logo'] = $vars['logo_img'] ? l($vars['logo_img'], '<front>', array('attributes' => array('rel' => 'home'), 'title' => t('Home page'), 'html' => TRUE)) : '';
$vars['linked_site_name'] = $vars['site_name'] ? l($vars['site_name'], '<front>', array('attributes' => array('rel' => 'home'), 'title' => t('Home page'))) : '';

$primary_menu_links = $vars['primary_links'];
$secondary_menu_links = $vars['secondary_links'];

if (!empty($primary_menu_links)) {
  $vars['primary_menu'] = theme('links', $primary_menu_links, array('class' => 'primary-links clearfix'));
}
if (!empty($secondary_menu_links)) {
  $vars['secondary_menu'] = theme('links', $secondary_menu_links, array('class' => 'secondary-links clearfix'));
}

if (!empty($primary_menu_links) && theme_get_setting('primary_links_tree')) {
  $primary_tree_menu = menu_tree_all_data('primary-links');
  $vars['primary_menu'] = menu_tree_output($primary_tree_menu);
}
if (!empty($secondary_menu_links) && theme_get_setting('secondary_links_tree')) {
  $secondary_tree_menu = menu_tree_all_data('secondary-links');
  $vars['secondary_menu'] = menu_tree_output($secondary_tree_menu);
}

$vars['attribution'] = "<div id=\"attribution\"><a href=\"http://adaptivethemes.com\">Premium Drupal Themes</a></div>"  ;

$classes = explode(' ', $vars['body_classes']);
if ($index = array_search(preg_replace('![^abcdefghijklmnopqrstuvwxyz0-9-_]+!s', '', 'page-'. drupal_strtolower(arg(0))), $classes)) {
  unset($classes[$index]);
}
$classes = str_replace('node-type-', 'page-type-', $classes);
$classes = str_replace('sidebar-left', 'sidebar-first', $classes);
$classes = str_replace('sidebar-right', 'sidebar-last', $classes);
$path_alias = drupal_get_path_alias($_GET['q']);
if (!$vars['is_front']) {
  list($section, ) = explode('/', $path_alias, 2);
  $classes[] = safe_string('section-'. $section);
}
if (theme_get_setting('extra_page_classes')) {
  if (!$vars['is_front']) {
    $normal_path = drupal_get_normal_path($_GET['q']);
    $classes[] = safe_string('page-'. $normal_path);
    if (arg(2) == 'block') {
      $classes[] = 'page-block';
    }
    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        $classes[] = 'article-add';
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        $classes[] = 'article-'. arg(2);
      }
    }
  }
  if (function_exists('locale')) {
  $classes[] = 'lang-'. $language->language;
  }
}
$vars['classes'] = trim(implode(' ', $classes));

if (theme_get_setting('layout_enable_settings') == 'on') {
  $vars['at_layout_width'] = 'div.container{width:'. theme_get_setting('layout_width') .';}';
  $method = theme_get_setting('layout_method');
  $sidebar_last_width = theme_get_setting('layout_sidebar_last_width');
  $sidebar_first_width = theme_get_setting('layout_sidebar_first_width');
  if ($vars['language']->dir == 'ltr') {
    $left = 'left';
    $right = 'right';
  }
  if ($vars['language']->dir == 'rtl') {
    $left = 'right';
    $right = 'left';
  }
  if ($method == '0') {
    $push_right = $sidebar_last_width;
    $push_left  = $sidebar_first_width;
    $pull_right = $sidebar_last_width;
    $styles = array();
    $styles[] = '.two-sidebars .content-inner{margin-'. $left .':'. $push_left .'px; margin-'. $right .':'. $push_right .'px;}';
    $styles[] = '.sidebar-first .content-inner{margin-'. $left .':'. $push_left .'px; margin-'. $right .':0;}';
    $styles[] = '.sidebar-last .content-inner{margin-'. $right .':'. $push_right .'px; margin-'. $left .':0;}';
    $styles[] = '#sidebar-first{width:'. $sidebar_first_width .'px;margin-'. $left .':-100%;}';
    $styles[] = '#sidebar-last{width:'. $sidebar_last_width .'px;margin-'. $left .':-'. $pull_right .'px;}';
  }
  if ($method == '1') {
    $content_margin = $sidebar_last_width + $sidebar_first_width;
    $push_right     = $sidebar_last_width;
    $push_left      = $sidebar_first_width;
    $left_margin    = $sidebar_last_width + $sidebar_first_width;
    $right_margin   = $sidebar_last_width;
    $styles = array();
    $styles[] = '.two-sidebars .content-inner{margin-'. $right .':'. $content_margin .'px;margin-'. $left .':0;}';
    $styles[] = '.sidebar-first .content-inner{margin-'. $right .':'. $push_left .'px;margin-'. $left .':0;}';
    $styles[] = '.sidebar-last .content-inner{margin-'. $right .':'. $push_right .'px;margin-'. $left .':0;}';
    $styles[] = '#sidebar-first{width:'. $sidebar_first_width .'px;margin-'. $left .':-'. $left_margin .'px;}';
    $styles[] = '#sidebar-last{width:'. $sidebar_last_width .'px;margin-'. $left .':-'. $right_margin .'px;}';
    $styles[] = '.sidebar-first #sidebar-first{width:'. $sidebar_first_width .'px;margin-'. $left .':-'. $sidebar_first_width .'px;}';
  }
  if ($method == '2') {
    $content_margin = $sidebar_last_width + $sidebar_first_width;
    $left_margin    = $sidebar_first_width;
    $right_margin   = $sidebar_last_width;
    $push_right     = $sidebar_first_width;
    $styles = array();
    $styles[] = '.two-sidebars .content-inner{margin-'. $left .':'. $content_margin .'px;margin-'. $right .':0;}';
    $styles[] = '.sidebar-first .content-inner{margin-'. $left .':'. $left_margin .'px;margin-'. $right .':0;}';
    $styles[] = '.sidebar-last .content-inner{margin-'. $left .':'. $right_margin .'px;margin-'. $right .':0;}';
    $styles[] = '#sidebar-first{width:'. $sidebar_first_width .'px; margin-'. $left .': -100%;}';
    $styles[] = '#sidebar-last{width:'. $sidebar_last_width .'px; margin-'. $left .': -100%;}';
    $styles[] = '.two-sidebars #sidebar-last {width:'. $sidebar_last_width .'px; position: relative;'. $left .':'. $push_right .'px;}';
  }
  $styles ? $vars['at_layout'] = implode('', $styles) : '';
  $vars['layout_settings'] = '<style type="text/css">'. $vars['at_layout_width'] . $vars['at_layout'] .'</style>';
}

if ($vars['search_box'] && theme_get_setting('display_search_form_label') == 0) {
  $vars['toggle_label'] = ' class="hide-label"';
}

if ($vars['logged_in'] && theme_get_setting('at_user_menu') == 1) {
  if (!function_exists(admin_menu_perm)) {
    $admin_user_links[] = l(t('Create content'), 'node/add');
    $admin_user_links[] = user_access('administer nodes') ? l(t('Manage content'), 'admin/content/node') : '';
    $admin_user_links[] = user_access('administer blocks') ? l(t('Blocks'), 'admin/build/block') : '';
    $admin_user_links[] = user_access('administer menu') ? l(t('Menus'), 'admin/build/menu') : '';
    $admin_user_links[] = user_access('administer users') ? l(t('Users'), 'admin/user/user') : '';
    $admin_user_links[] = user_access('access administration pages') ? l(t('Admin'), 'admin') : '';
  }
  if ($vars['logged_in']) {
    $admin_user_links[] = l(t('My Account'), 'user/'. $user->uid);
  }
  if (!function_exists(admin_menu_perm)) {
    $admin_user_links[] = l(t('Logout'), 'logout');
  }
  $vars['admin_user_menu'] = $admin_user_links;
  $vars['admin_user_links'] = theme('item_list', $admin_user_links);
}