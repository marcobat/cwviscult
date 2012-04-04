<?php // $Id: threecol_at_stacked_inset.inc,v 1.2 2010/06/04 21:30:04 jmburnz Exp $
// adpativethemes.com

/**
 * @file threecol_at_stacked_inset.inc
 * Implementation of hook_panels_layouts()
 */
function adaptivetheme_threecol_at_stacked_inset_panels_layouts() {
  $items['threecol_at_stacked_inset'] = array(
    'title' => t('Three column AT stacked inset'),
    'icon' => 'threecol_at_stacked_inset.png',
    'theme' => 'threecol_at_stacked_inset',
    'theme arguments' => array('id', 'content'),
    'css' => 'threecol_at_stacked_inset.css',
    'panels' => array(
      'top' => t('Top'),
      'left' => t('Left side'),
      'middle' => t('Middle column'),
      'right' => t('Right side'),
      'bottom' => t('Bottom'),
    ),
  );

  return $items;
}
