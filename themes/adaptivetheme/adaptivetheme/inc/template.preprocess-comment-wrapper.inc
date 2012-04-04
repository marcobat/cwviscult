<?php // $Id: template.preprocess-comment-wrapper.inc,v 1.2.2.2 2010/10/14 05:38:01 jmburnz Exp $

/**
 * @file
 * Override or insert variables into the comment-wrapper template.
 */
global $theme;
$classes = array();
if (function_exists('node_skinr_data') && !empty($vars['skinr'])) {
  $classes[] = $vars['skinr'];
  $classes[] = 'skinr-comments';
}
$classes[] = $vars['node']->type .'-comments';
$vars['classes'] = implode(' ', $classes);