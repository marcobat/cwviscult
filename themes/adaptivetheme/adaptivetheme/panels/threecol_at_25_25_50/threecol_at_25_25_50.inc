<?php // $Id: threecol_at_25_25_50.inc,v 1.2 2010/06/04 21:30:04 jmburnz Exp $
// adpativethemes.com

/**
 * @file twocol_at_25_25_50.inc
 * Implementation of hook_panels_layouts()
 */
function adaptivetheme_threecol_at_25_25_50_panels_layouts() {
  $items['threecol_at_25_25_50'] = array(
    'title' => t('Three column AT 25/25/50'),
    'icon' => 'threecol_at_25_25_50.png',
    'theme' => 'threecol_at_25_25_50',
    'theme arguments' => array('id', 'content'),
    'css' => 'threecol_at_25_25_50.css',
    'panels' => array(
      'left' => t('Left side'),
      'middle' => t('Middle column'),
      'right' => t('Right side'),
    ),
  );

  return $items;
}
