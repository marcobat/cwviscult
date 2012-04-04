<?php // $Id: template.custom-functions.inc,v 1.2.2.2 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 * template.custom-functions.inc
 */

/**
 * Clean a string of unwanted characters.
 *
 * @param $string
 *   The string
 * @return
 *   The converted string
 */
function safe_string($string) {
  $string = drupal_strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $string));
  return $string;
}

/**
 * Limit the length of a string.
 *
 * @param $string
 *   The string
 * @param $lenght
 *   The lenght of the trimmed string
 * @$ellipsis
 *
 * @return
 *   The converted string
 */
function wordlimit($string, $length = 50, $ellipsis = "...") {
  $words = explode(' ', strip_tags($string));
  if (count($words) > $length)
    return implode(' ', array_slice($words, 0, $length)) . $ellipsis;
  else
    return $string;
}

/**
 * Set a default style scheme and set a cookie.
 */
function get_at_styles() {
  $scheme = theme_get_setting('style_schemes');
  if (!$scheme) {
    $scheme = 'style-default.css';
  }
  if (isset($_COOKIE["atstyles"])) {
    $scheme = $_COOKIE["atstyles"];
  }
  return $scheme;
}