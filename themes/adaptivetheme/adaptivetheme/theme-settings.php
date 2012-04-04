<?php // $Id: theme-settings.php,v 1.2.2.5 2010/10/25 08:55:44 jmburnz Exp $

/**
 * @file
 * Add custom theme settings.
 */

// Initialize theme settings.
include_once(drupal_get_path('theme', 'adaptivetheme') .'/inc/template.theme-settings.inc');

/**
* Implementation of themehook_settings() function.
*
* @param $saved_settings
*   An array of saved settings for this theme.
* @return
*   A form array.
*/
function adaptivetheme_settings($saved_settings, $subtheme_defaults = array()) {

  global $theme_info;

  // Get the default values from the .info file.
  $defaults = adaptivetheme_theme_get_default_settings('adaptivetheme');

  // Allow a subtheme to override the default values.
  $defaults = array_merge($defaults, $subtheme_defaults);

  // Merge the saved variables and their default values
  $settings = array_merge($defaults, $saved_settings);

  // Export theme settings
  $exportable_settings = array (
    'skip_navigation_display'           => $settings['skip_navigation_display'],
    'breadcrumb_display'                => $settings['breadcrumb_display'],
    'breadcrumb_separator'              => $settings['breadcrumb_separator'],
    'breadcrumb_home'                   => $settings['breadcrumb_home'],
    'display_search_form_label'         => $settings['display_search_form_label'],
    'search_snippet'                    => $settings['search_snippet'],
    'search_info_type'                  => $settings['search_info_type'],
    'search_info_user'                  => $settings['search_info_user'],
    'search_info_date'                  => $settings['search_info_date'],
    'search_info_comment'               => $settings['search_info_comment'],
    'search_info_upload'                => $settings['search_info_upload'],
    'search_info_separator'             => $settings['search_info_separator'],
    'extra_page_classes'                => $settings['extra_page_classes'],
    'extra_article_classes'             => $settings['extra_article_classes'],
    'extra_comment_classes'             => $settings['extra_comment_classes'],
    'extra_block_classes'               => $settings['extra_block_classes'],
    'extra_menu_classes'                => $settings['extra_menu_classes'],
    'extra_item_list_classes'           => $settings['extra_item_list_classes'],
    'primary_links_tree'                => $settings['primary_links_tree'],
    'secondary_links_tree'              => $settings['secondary_links_tree'],
    'links_add_span_elements'           => $settings['links_add_span_elements'],
    'at_user_menu'                      => $settings['at_user_menu'],
    'block_edit_links'                  => $settings['block_edit_links'],
    'rebuild_registry'                  => $settings['rebuild_registry'],
    'layout_method'                     => $settings['layout_method'],
    'layout_width'                      => $settings['layout_width'],
    'layout_sidebar_first_width'        => $settings['layout_sidebar_first_width'],
    'layout_sidebar_last_width'         => $settings['layout_sidebar_last_width'],
    'layout_enable_settings'            => $settings['layout_enable_settings'],
    'layout_enable_width'               => $settings['layout_enable_width'],
    'layout_enable_sidebars'            => $settings['layout_enable_sidebars'],
    'layout_enable_method'              => $settings['layout_enable_method'],
    'equal_heights_sidebars'            => $settings['equal_heights_sidebars'],
    'equal_heights_blocks'              => $settings['equal_heights_blocks'],
    'equal_heights_gpanels'             => $settings['equal_heights_gpanels'],
    'horizontal_login_block'            => $settings['horizontal_login_block'],
    'horizontal_login_block_overlabel'  => $settings['horizontal_login_block_overlabel'],
    'horizontal_login_block_enable'     => $settings['horizontal_login_block_enable'],
    'style_schemes'                     => $settings['style_schemes'],
    'style_enable_schemes'              => $settings['style_enable_schemes'],
  );
  // Output key value pairs formatted as settings
  foreach($exportable_settings as $key => $value) {
  	$value = filter_xss($value);
  	$output .= "settings[$key]=\"$value\"\n";
  }
  $exports = $output;

  // Create the form using Forms API: http://api.drupal.org/api/6
  // Layout settings
  $form['layout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  if ($settings['layout_enable_settings'] == 'on') {
    $image_path = drupal_get_path('theme', 'adaptivetheme') .'/css/core-images';
    $form['layout']['page_layout'] = array(
      '#type' => 'fieldset',
      '#title' => t('Page Layout'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t('Use these settings to customize the layout of your theme. These settings match with the Skinr block width settings - so you can build complex grid like layouts within sidebars and other regions.'),
    );
    if ($settings['layout_enable_width'] == 'on') {
      $form['layout']['page_layout']['layout_width'] = array(
        '#title' => t('Page width'),
        '#type' => 'select',
        '#prefix' => '<div class="page-width">',
        '#suffix' => '</div>',
        '#default_value' => $settings['layout_width'],
        '#options' => array(
          '720px' => t('720px'),
          '780px' => t('780px'),
          '840px' => t('840px'),
          '900px' => t('900px'),
          '960px' => t('960px'),
          '1020px' => t('1020px'),
          '1080px' => t('1080px'),
          '1140px' => t('1140px'),
          '1200px' => t('1200px'),
          '1260px' => t('1260px'),
          '75%' => t('75% Fluid'),
          '80%' => t('80% Fluid'),
          '85%' => t('85% Fluid'),
          '90%' => t('90% Fluid'),
          '95%' => t('95% Fluid'),
          '100%' => t('100% Fluid'),
        ),
        '#attributes' => array('class' => 'field-layout-width'),
      );
    } // endif width
    if ($settings['layout_enable_sidebars'] == 'on') {
      $form['layout']['page_layout']['layout_sidebar_first_width'] = array(
        '#type' => 'select',
        '#title' => t('Sidebar first width'),
        '#prefix' => '<div class="sidebar-width"><div class="sidebar-width-left">',
        '#suffix' => '</div>',
        '#default_value' => $settings['layout_sidebar_first_width'],
        '#options' => array(
          '60' => t('60px'),
          '120' => t('120px'),
          '160' => t('160px'),
          '180' => t('180px'),
          '240' => t('240px'),
          '300' => t('300px'),
          '320' => t('320px'),
          '360' => t('360px'),
          '420' => t('420px'),
          '480' => t('480px'),
          '540' => t('540px'),
          '600' => t('600px'),
          '660' => t('660px'),
          '720' => t('720px'),
          '780' => t('780px'),
          '840' => t('840px'),
          '900' => t('900px'),
          '960' => t('960px'),
        ),
        '#attributes' => array('class' => 'sidebar-width-select'),
      );
      $form['layout']['page_layout']['layout_sidebar_last_width'] = array(
        '#type' => 'select',
        '#title' => t('Sidebar last width'),
        '#prefix' => '<div class="sidebar-width-right">',
        '#suffix' => '</div></div>',
        '#default_value' => $settings['layout_sidebar_last_width'],
        '#options' => array(
          '60' => t('60px'),
          '120' => t('120px'),
          '160' => t('160px'),
          '180' => t('180px'),
          '240' => t('240px'),
          '300' => t('300px'),
          '320' => t('320px'),
          '360' => t('360px'),
          '420' => t('420px'),
          '480' => t('480px'),
          '540' => t('540px'),
          '600' => t('600px'),
          '660' => t('660px'),
          '720' => t('720px'),
          '780' => t('780px'),
          '840' => t('840px'),
          '900' => t('900px'),
          '960' => t('960px'),
        ),
        '#attributes' => array('class' => 'sidebar-width-select'),
      );
    } //endif layout sidebars
    if ($settings['layout_enable_method'] == 'on') {
      $form['layout']['page_layout']['layout_method'] = array(
        '#title' => t('Sidebar layout'),
        '#type' => 'radios',
        '#prefix' => '<div class="layout-method">',
        '#suffix' => '</div>',
        '#default_value' => $settings['layout_method'],
        '#options' => array(
          '0' => t('<strong>Layout #1</strong>') . ' ' . t('<span class="layout-type">Standard three column layout (left - content - right)</span>'),
          '1' => t('<strong>Layout #2</strong>') . ' ' . t('<span class="layout-type">Two columns on the right (content - left - right)</span>'),
          '2' => t('<strong>Layout #3</strong>') . ' ' . t('<span class="layout-type">Two columns on the left (left - right - content)</span>'),
        ),
       '#attributes' => array('class' => 'layouts'),
      );
      $form['layout']['page_layout']['layout_enable_settings'] = array(
        '#type' => 'hidden',
        '#value' => $settings['layout_enable_settings'],
      );
    } // endif layout method
  } // endif layout settings
  // Equal heights settings
  $form['layout']['equal_heights'] = array(
    '#type' => 'fieldset',
    '#title' => t('Equal Heights'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description'   => t('These settings allow you to set the sidebars and/or region blocks to be equal height.'),
  );
  // Equal height sidebars
  $form['layout']['equal_heights']['equal_heights_sidebars'] = array(
    '#type' => 'checkbox',
    '#title' => t('Equal Height Sidebars'),
    '#default_value' => $settings['equal_heights_sidebars'],
    '#description'   => t('This setting will make the sidebars and the main content column equal to the height of the tallest column.'),
  );
  // Equal height gpanels
  $form['layout']['equal_heights']['equal_heights_gpanels'] = array(
    '#type' => 'checkbox',
    '#title' => t('Equal Height Gpanels'),
    '#default_value' => $settings['equal_heights_gpanels'],
    '#description'   => t('This will make all Gpanel blocks equal to the height of the tallest block in any Gpanel, regardless of which Gpanel the blocks are in. Good for creating a grid type block layout, however it could be too generic if you have more than one Gpanel active in the page.'),
  );
  // Equal height blocks per region
  $equalized_blocks = array(
    'leaderboard' => t('Leaderboard region'),
    'header' => t('Header region'),
    'secondary-content' => t('Secondary Content region'),
    'content-top' => t('Content Top region'),
    'content-bottom' => t('Content Bottom region'),
    'tertiary-content' => t('Tertiary Content region'),
    'footer' => t('Footer region'),
  );
  $form['layout']['equal_heights']['equal_heights_blocks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Equal Height Blocks'),
  );
  $form['layout']['equal_heights']['equal_heights_blocks'] += array(
    '#prefix' => '<div id="div-equalize-collapse">',
    '#suffix' => '</div>',
    '#description' => t('<p>Equal height blocks only makes sense for blocks aligned horizontally so do not apply to sidebars. The equal height settings work well in conjunction with the Skinr block layout classes.</p>'),
  );
  foreach ($equalized_blocks as $name => $title) {
    $form['layout']['equal_heights']['equal_heights_blocks']['equalize_'. $name] = array(
      '#type' => 'checkbox',
      '#title' => $title,
      '#default_value' => $settings['equalize_'. $name],
    );
  }
  // Display Settings
  $form['display_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Skip Navigation
  $form['display_settings']['skip_navigation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Skip Navigation'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['display_settings']['skip_navigation']['skip_navigation_display'] = array(
    '#type' => 'radios',
    '#title'  => t('Modify the display of the skip navigation'),
    '#default_value' => $settings['skip_navigation_display'],
    '#options' => array(
      'show' => t('Show skip navigation'),
      'focus' => t('Show skip navigation when in focus, otherwise is hidden'),
      'hide' => t('Hide skip navigation'),
    ),
  );
  // Breadcrumbs
  $form['display_settings']['breadcrumb'] = array(
    '#type' => 'fieldset',
    '#title' => t('Breadcrumb'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['display_settings']['breadcrumb']['breadcrumb_display'] = array(
    '#type' => 'select',
    '#title' => t('Display breadcrumb'),
    '#default_value' => $settings['breadcrumb_display'],
    '#options' => array(
      'yes' => t('Yes'),
      'no' => t('No'),
      'admin' => t('Only in the admin section'),
    ),
  );
  $form['display_settings']['breadcrumb']['breadcrumb_separator'] = array(
    '#type'  => 'textfield',
    '#title' => t('Breadcrumb separator'),
    '#description' => t('Text only. Dont forget to include spaces.'),
    '#default_value' => $settings['breadcrumb_separator'],
    '#size' => 8,
    '#maxlength' => 10,
    '#prefix' => '<div id="div-breadcrumb-collapse">',
  );
  $form['display_settings']['breadcrumb']['breadcrumb_home'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the home page link in breadcrumbs'),
    '#default_value' => $settings['breadcrumb_home'],
    '#suffix' => '</div>',
  );
  // Search Settings
  $form['display_settings']['search'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Search forms
  $form['display_settings']['search']['search_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search forms'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['display_settings']['search']['search_form']['display_search_form_label'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display the search form label <em>"Search this site"</em>'),
    '#default_value' => $settings['display_search_form_label'],
  );
  // Search results
  $form['display_settings']['search']['search_results'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search results'),
    '#description' => t('What additional information should be displayed in your search results?'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['display_settings']['search']['search_results']['search_snippet'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display text snippet'),
    '#default_value' => $settings['search_snippet'],
  );
  $form['display_settings']['search']['search_results']['search_info_type'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display content type'),
    '#default_value' => $settings['search_info_type'],
  );
  $form['display_settings']['search']['search_results']['search_info_user'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display author name'),
    '#default_value' => $settings['search_info_user'],
  );
  $form['display_settings']['search']['search_results']['search_info_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display posted date'),
    '#default_value' => $settings['search_info_date'],
  );
  $form['display_settings']['search']['search_results']['search_info_comment'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display comment count'),
    '#default_value' => $settings['search_info_comment'],
  );
  $form['display_settings']['search']['search_results']['search_info_upload'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display attachment count'),
    '#default_value' => $settings['search_info_upload'],
  );
  // Search_info_separator
  $form['display_settings']['search']['search_results']['search_info_separator'] = array(
    '#type' => 'textfield',
    '#title' => t('Search info separator'),
    '#description' => t('Modify the separator. The default is a hypen with a space before and after.'),
    '#default_value' => $settings['search_info_separator'],
    '#size' => 8,
    '#maxlength' => 10,
  );
  // Login block
  if ($settings['slider_login_block_enable'] == 'on' || $settings['horizontal_login_block_enable'] == 'on') {
    $form['display_settings']['login_block'] = array(
      '#type' => 'fieldset',
      '#title' => t('Login Block'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    // Horizonatal login block
    if ($settings['horizontal_login_block_enable'] == 'on') {
      $form['display_settings']['login_block']['horizontal_login_block'] = array(
        '#type' => 'checkbox',
        '#title' => t('Horizontal Login Block'),
        '#default_value' => $settings['horizontal_login_block'],
        '#description' => t('Checking this setting will enable a horizontal style login block (all elements on one line). Note that if you are using OpenID this does not work well and you will need a more sophistocated approach than can be provided here.'),
      );
    } // endif horizontal block settings
    // Slider login block
    if ($settings['slider_login_block_enable'] == 'on') {
      $form['display_settings']['login_block']['slider_login_block'] = array(
        '#type' => 'checkbox',
        '#title' => t('Sliding Login Block'),
        '#default_value' => $settings['slider_login_block'],
        '#description' => t('Checking this setting will enable a Sliding style login block - the block will collapse and provide a toggle link to open and close the block (Twitter Style).'),
      );
    } // endif slider block settings
  }
  // Admin settings
  $form['admin_settings']['administration'] = array(
    '#type' => 'fieldset',
    '#title' => t('Administration'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Show user menu
  $form['admin_settings']['administration']['at_user_menu'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the built in User Menu.'),
    '#default_value' => $settings['at_user_menu'],
    '#description' => t('This will show or hide useful links in the header. NOTE that if the <a href="!link">Admin Menu</a> module is installed most links will not show up because they are included in the Admin Menu.', array('!link' => 'http://drupal.org/project/admin_menu')),
  );
  // Show block edit links
  $form['admin_settings']['administration']['block_edit_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show block editing and configuration links.'),
    '#default_value' => $settings['block_edit_links'],
    '#description' => t('When hovering over a block or viewing blocks in the blocks list page privileged users will see block editing and configuration links.'),
  );
  // Development settings
  $form['themedev']['dev'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development'),
    '#description' => t('WARNING: These settings are for the theme developer! Changing these settings may break your site. Make sure you really know what you are doing before changing these.'),
    '#collapsible' => TRUE,
    '#collapsed' => $settings['rebuild_registry'] ? FALSE : TRUE,
  );
  // Rebuild registry
  $form['themedev']['dev']['rebuild_registry'] = array(
    '#type' => 'checkbox',
    '#title' => t('Rebuild the theme registry on every page load'),
    '#default_value' => $settings['rebuild_registry'],
    '#description' => t('During theme development, it can be very useful to continuously <a href="!link">rebuild the theme registry</a>. WARNING! This is a performance penalty and must be turned off on production websites.', array('!link' => 'http://drupal.org/node/173880#theme-registry')),
  );
  // Add or remove extra classes
  $form['themedev']['dev']['classes'] = array(
    '#type' => 'fieldset',
    '#title' => t('CSS Classes'),
    '#description' => t('Adaptivetheme prints many heplful classes for templates by default - these settings allow you to expand on these by adding extra classes to pages, articles, comments, blocks, menus and item lists.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['themedev']['dev']['classes']['extra_page_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pages: ') . '<span class="description">' . t('add page-path, add/edit/delete (for workflow states), and a language class (i18n).') . '</span>',
    '#default_value' => $settings['extra_page_classes'],
  );
  $form['themedev']['dev']['classes']['extra_article_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Articles: ') . '<span class="description">' . t('add promoted, sticky, preview, language and odd/even classes.') . '</span>',
    '#default_value' => $settings['extra_article_classes'],
  );
  $form['themedev']['dev']['classes']['extra_comment_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Comments: ') . '<span class="description">' . t('add anonymous, author, viewer, new, and odd/even classes.') . '</span>',
    '#default_value' => $settings['extra_comment_classes'],
  );
  $form['themedev']['dev']['classes']['extra_block_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Blocks: ') . '<span class="description">' . t('add odd/even, block region and block count classes.') . '</span>',
    '#default_value' => $settings['extra_block_classes'],
  );
  $form['themedev']['dev']['classes']['extra_menu_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Menus: ') . '<span class="description">' . t('add an extra class based on the link text.') . '</span>',
    '#default_value' => $settings['extra_block_classes'],
  );
  $form['themedev']['dev']['classes']['extra_item_list_classes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Item-lists: ') . '<span class="description">' . t('add first, last and odd/even classes.') . '</span>',
    '#default_value' => $settings['extra_item_list_classes'],
  );
  // Primary and Secondary Links Settings
  $form['themedev']['dev']['primary_secondary_links'] = array(
    '#type' => 'fieldset',
    '#title' => t('Modify Links'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['themedev']['dev']['primary_secondary_links']['primary_links_tree'] = array(
    '#type' => 'checkbox',
    '#title' => 'Output Primary links as standard Drupal menus',
    '#default_value' => $settings['primary_links_tree'],
  );
  $form['themedev']['dev']['primary_secondary_links']['secondary_links_tree'] = array(
    '#type' => 'checkbox',
    '#title' => 'Output Secondary links as standard Drupal menus',
    '#default_value' => $settings['secondary_links_tree'],
  );
  // Add spans to theme_links
  $form['themedev']['dev']['primary_secondary_links']['links_add_span_elements'] = array(
    '#type' => 'checkbox',
    '#title' => check_plain(t('Add <span></span> tags around Primary and Secondary links anchor text')),
    '#default_value' => $settings['links_add_span_elements'],
  );
  // Theme Settings Export
  $form['themedev']['dev']['export'] = array(
    '#type' => 'fieldset',
    '#title' => t('Export'),
    '#description' => t('<p>Copy and paste these settings to a plain text file for backup or paste to your themes .info file.</p><p>WARNING! If you are using a WYSIWYG editor it must be disabled for this text area, otherwise all special characters are likely to be converted to HTML entities. If your editor has a \'view source\' feature try that first.</p>'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['themedev']['dev']['export']['exported_settings'] = array(
    '#type' => 'textarea',
    '#default_value' => $exports,
    '#resizable' => FALSE,
    '#cols' => 60,
    '#rows' => 25,
  );
  return $form;
}