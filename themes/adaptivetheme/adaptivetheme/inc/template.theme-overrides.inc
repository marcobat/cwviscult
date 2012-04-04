<?php // $Id: template.theme-overrides.inc,v 1.2.2.5 2010/10/25 08:55:44 jmburnz Exp $

/**
 * @file
 * template.theme-overrides.inc
 */

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function adaptivetheme_breadcrumb($breadcrumb) {
  $show_breadcrumb = theme_get_setting('breadcrumb_display');
  if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {
    $show_breadcrumb_home = theme_get_setting('breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }
    if (!empty($breadcrumb)) {
      $breadcrumb_separator = filter_xss(theme_get_setting('breadcrumb_separator'));
      return implode($breadcrumb_separator, $breadcrumb);
    }
  }
  return '';
}

/**
 * Theme a form button.
 */
function adaptivetheme_button($element) {
  if (isset($element['#attributes']['class'])) {
    $element['#attributes']['class'] = 'form-'. $element['#button_type'] .' '. $element['#attributes']['class'];
  }
  else {
    $element['#attributes']['class'] = 'form-'. $element['#button_type'];
  }
  if (stristr($element['#attributes']['style'], 'display: none;') || stristr($element['#attributes']['class'], 'fivestar-submit')) {
    return '<input type="submit" '. (empty($element['#name']) ? '' : 'name="'. $element['#name'] .'" ')  .'id="'. $element['#id'] .'" value="'. check_plain($element['#value']) .'" '. drupal_attributes($element['#attributes']) ." />\n";
  }
  else {
    return '<span class="button-wrapper '. $element['#id'] .'"><span class="button"><input type="submit" '. (empty($element['#name']) ? '' : 'name="'. $element['#name'] .'" ')  .'id="'. $element['#id'] .'" value="'. check_plain($element['#value']) .'" '. drupal_attributes($element['#attributes']) ." /></span></span>\n";
  }
}

/**
 * Format a group of form items.
 *
 * @param $element
 *   An associative array containing the properties of the element.
 *
 * @return
 *   A themed HTML string representing the form item group.
 */
function adaptivetheme_fieldset($element) {
  if ($element['#collapsible']) {
    drupal_add_js('misc/collapse.js');
    if (!isset($element['#attributes']['class'])) {
      $element['#attributes']['class'] = '';
    }
    $element['#attributes']['class'] .= ' collapsible';
    if ($element['#collapsed']) {
     $element['#attributes']['class'] .= ' collapsed';
    }
  }
  $css_class = 'fieldset-'. safe_string($element['#title']);
  $element['#attributes']['class'] .= (!empty($element['#attributes']['class']) ? " " : "") . $css_class;
  return '<fieldset'. drupal_attributes($element['#attributes']) .'>'. ($element['#title'] ? '<legend>'. $element['#title'] .'</legend>' : '') . ($element['#description'] ? '<div class="description">'. $element['#description'] .'</div>' : '') . $element['#children'] . $element['#value'] ."</fieldset>\n";
}

/**
 * Modify the theme settings form.
 */
function adaptivetheme_system_settings_form($form) {
  if (arg(2) == 'themes' && arg(3) == 'settings') {
    $form['theme_settings']['#title'] = t('Drupal core theme settings');
    $form['theme_specific']['#title'] = t('Advanced theme settings');
    $form_elements = element_children($form);
    foreach ($form_elements as $element) {
      if ($form[$element]['#type'] == 'fieldset') {
        $form[$element]['#collapsible'] = TRUE;
        $form[$element]['#collapsed']   = TRUE;
        $form[$element]['#prefix'] = '<div class="'. safe_string($element) .'-settings-wrapper">';
        $form[$element]['#suffix'] = '</div>';
      }
    }
    return drupal_render($form);
  }
}

/**
 * Return a themed set of links.
 *
 * @param $links
 *   A keyed array of links to be themed.
 * @param $attributes
 *   A keyed array of attributes
 * @return
 *   A string containing an unordered list of links.
 */
function adaptivetheme_links($links, $attributes = array('class' => 'links')) {
  $output = '';
  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';
    $num_links = count($links);
    $i = 1;
    foreach ($links as $key => $link) {
      $class = $key;
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }
      if (theme_get_setting('add_access_keys')) {
        $link['attributes']['accesskey'] = $i;
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))) {
        $class .= ' active';
      }
      if (isset($link['href'])) {
        if (strpos($link['attributes']['class'], 'active-trail') !== FALSE && strpos($class, 'active') === FALSE) {
          $class .= ' active';
          $link['attributes']['class'] .= ' active';
        }
        if (theme_get_setting('links_add_span_elements')) {
          $link['title'] = '<span>' . check_plain($link['title']) . '</span>';
          $link['html'] = TRUE;
        }
        $link = l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $link = '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }
      $i++;
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';
      $output .= $link;
      $output .= "</li>";
    }
    $output .= "</ul>";
  }
  return $output;
}

// If DHTML module is installed dont override theme_menu_item.
if (!function_exists('dhtml_menu_init')) {
  /**
   * Generate the HTML output for a menu item and submenu.
   */
  function adaptivetheme_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
    static $counter = 0;
    $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
    if ($class == 'leaf') {
      $counter ++;
      if ($extra_class == 'last') {
        if ($counter == 1) {
          $extra_class = 'single-item';
        }
        else $counter = 0;
      }
    }
    if (!empty($extra_class)) {
      if ($class) {
        $class .= ' '. $extra_class;
      }
      else {
        $class .= $extra_class;
      }
    }
    if (theme_get_setting('extra_menu_classes')) {
      $class .= ' menu-item-' . safe_string(strip_tags($link));
    }
    if ($in_active_trail) {
      $class .= ' active-trail';
    }
    return '<li class="'. $class .'">'. $link . $menu ."</li>";
  }
}

/**
 * Return a themed list of items.
 *
 * @param $items
 *   An array of items to be displayed in the list. If an item is a string,
 *   then it is used as is. If an item is an array, then the "data" element of
 *   the array is used as the contents of the list item. If an item is an array
 *   with a "children" element, those children are displayed in a nested list.
 *   All other elements are treated as attributes of the list item element.
 * @param $title
 *   The title of the list.
 * @param $type
 *   The type of list to return (e.g. "ul", "ol")
 * @param $attributes
 *   The attributes applied to the list element.
 * @return
 *   A string containing the list output.
 */
function adaptivetheme_item_list($items = array(), $title = NULL, $type = 'ul', $attributes = NULL) {
  $output = '<div class="item-list">';
  if (isset($title)) {
    $output .= '<h3>'. $title .'</h3>';
  }
  if (!empty($items)) {
    $output .= "<$type". drupal_attributes($attributes) .'>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        $data .= theme_item_list($children, NULL, $type, $attributes);
      }
      if (theme_get_setting('extra_item_list_classes')) {
        if ($i & 1) {
          $attributes['class'] = empty($attributes['class']) ? 'odd' : ($attributes['class'] .' odd');
        }
        else {
          $attributes['class'] = empty($attributes['class']) ? 'even' : ($attributes['class'] .' even');
        }
        if ($i == 0) {
          $attributes['class'] = empty($attributes['class']) ? 'first' : ($attributes['class'] .' first');
        }
        if ($i == $num_items - 1) {
          $attributes['class'] = empty($attributes['class']) ? 'last' : ($attributes['class'] .' last');
        }
      }
      $output .= '<li'. drupal_attributes($attributes) .'>'. $data ."</li>";
    }
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}