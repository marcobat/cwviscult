<?php // $Id: template.preprocess-search-result.inc,v 1.2.2.1 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 *  Modify search results based on theme settings.
 */
$result = $vars['result'];
$vars['url'] = check_url($result['link']);
$vars['title'] = check_plain($result['title']);
$vars['snippet'] = '';
if (!empty($result['snippet']) && theme_get_setting('search_snippet')) {
  $vars['snippet'] = $result['snippet'];
}
$info = array();
if (!empty($result['type']) && theme_get_setting('search_info_type')) {
  $info['type'] = check_plain($result['type']);
}
if (!empty($result['user']) && theme_get_setting('search_info_user')) {
  $info['user'] = $result['user'];
}
if (!empty($result['date']) && theme_get_setting('search_info_date')) {
  $info['date'] = format_date($result['date'], 'small');
}
if (isset($result['extra']) && is_array($result['extra'])) {
  if (!empty($result['extra'][0]) && theme_get_setting('search_info_comment')) {
    $info['comment'] = $result['extra'][0];
  }
  if (!empty($result['extra'][1]) && theme_get_setting('search_info_upload')) {
    $info['upload'] = $result['extra'][1];
  }
}
$vars['info_split'] = $info;
$vars['info'] = implode(' - ', $info);
$vars['template_files'][] = 'search-result-'. $vars['type'];
$vars['info_separator'] = filter_xss(theme_get_setting('search_info_separator'));