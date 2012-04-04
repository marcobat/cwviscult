<?php // $Id: template.preprocess-node.inc,v 1.2.2.4 2010/10/14 05:38:01 jmburnz Exp $

/**
 * @file
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called.
 */
global $theme, $user;

$vars['article_id'] = 'article-'. $vars['node']->nid;

$classes = array();
$classes[] = 'article';
if ($vars['teaser']) {
  $classes[] = 'article-teaser';
}
$classes[] = 'article-type-'. $vars['node']->type;
if (!$vars['status']) {
  $classes[] = 'article-unpublished';
}
if (!empty($vars['skinr'])) {
  $classes[] = $vars['skinr'];
  $classes[] = 'skinr-article';
}
if (theme_get_setting('extra_article_classes')) {
  if ($vars['promote']) {
    $classes[] = 'article-promoted';
  }
  if ($vars['sticky']) {
    $classes[] = 'article-sticky';
  }
  if (isset($vars['preview'])) {
    $classes[] = 'article-preview';
  }
  if (function_exists('i18n_init')) {
    if ($vars['node']->language) {
      global $language;
      $classes[] = 'article-lang-'. $vars['node']->language;
    }
  }
  if ($vars['teaser']) {
    $classes[] = 'article-'. $vars['zebra'];
  }
}
$vars['classes'] = implode(' ', $classes);

$title_classes = array();
$title_classes[] = 'title';
$title_classes[] = 'article-title';
$vars['title_classes'] = implode(' ', $title_classes);

$vars['article_aside'] = theme('blocks', 'article_aside');
$vars['template_files'][] = 'node-'.$vars['node']->nid;

$vars['terms'] = theme('links', $vars['taxonomy'], array('class' => 'links term-links'));
$vars['links'] = theme('links', $vars['node']->links, array('class' => 'links link-links'));

if (!$vars['node']->status) {
  if ($vars['page']) {
    drupal_set_message(t('%title is currently unpublished', array('%title' => $vars['node']->title)), 'warning');
  }
  else {
    $vars['unpublished'] = '<span class="unpublished">'. t('Unpublished') .'</span>';
  }
}