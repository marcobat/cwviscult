<?php // $Id: template.preprocess-comment.inc,v 1.2.2.1 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 * Override or insert variables in comment templates.
 *
 * @param $vars
 *   A sequential array of variables to pass to the theme template.
 * @param $hook
 *   The name of the theme function being called.
 */
global $theme, $user;
$node = node_load($vars['comment']->nid);

$classes = array();
$classes[]  = 'comment';
if ($vars['status'] != 'comment-published') {
  $classes[] = $vars['status'];
}
else {
  if (theme_get_setting('extra_comment_classes')) {
    if ($vars['comment']->uid == 0) {
      $classes[] = 'comment-by-anonymous';
    }
    if ($vars['comment']->uid === $vars['node']->uid) {
      $classes[] = 'comment-by-article-author';
    }
    if ($vars['comment']->uid === $vars['user']->uid) {
      $classes[] = 'comment-by-viewer';
    }
    if ($vars['comment']->new) {
      $classes[] = 'comment-new';
    }
    $classes[] = 'comment-'. $vars['zebra'];
  }
}
$vars['classes'] = implode(' ', $classes);

$title_classes = array();
$title_classes[] = 'title';
$title_classes[] = 'comment-title';
$vars['title_classes'] = implode(' ', $title_classes);

if (variable_get('comment_subject_field', 1) == 0) {
  $vars['title'] = '';
}

if (!function_exists('submitted_by_comment_submitted')) {
  $submitted_by = t('by ') .'<em class="author">'.  theme('username', $vars['comment']) .'</em>';
  $submitted_by .= t(' - ') .'<em class="time">'.  format_date($vars['comment']->timestamp, 'small') .'</em>'; // Format date as small, medium, or large
  $vars['submitted'] = $submitted_by;
}

if ($vars['comment']->status == COMMENT_NOT_PUBLISHED) {
  drupal_set_message(t('Comment #!id !title is currently unpublished', array('!id' => $vars['id'], '!title' => $vars['title'])), 'warning');
  $vars['unpublished'] = '<span class="unpublished">'. t('Unpublished') .'</span>';
}