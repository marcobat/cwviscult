<?php // $Id: panels-pane.tpl.php,v 1.2.2.2 2010/10/14 05:38:00 jmburnz Exp $

/**
 * @file
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<?php
if (!empty($skinr)) {
  $skinr_classes = array();
  $skinr_classes[] = $skinr;
  $skinr_classes[] = 'skinr-pane';
  $skinr_pane_classes = implode(' ', $skinr_classes);
}
?>
<div class="<?php print $classes;?><?php print $skinr_pane_classes ? ' ' . $skinr_pane_classes : ''; ?>" <?php print $id; ?>>
  <div class="pane-inner">
    <?php if ($admin_links): ?>
      <div class="admin-links panel-hide"><?php print $admin_links; ?></div>
    <?php endif; ?>
    <?php if ($title): ?>
      <h2 class="pane-title"><?php print $title; ?></h2>
    <?php endif; ?>
    <?php if ($feeds): ?>
      <div class="feed"><?php print $feeds; ?></div>
    <?php endif; ?>
    <div class="pane-content"><?php print $content; ?></div>
    <?php if ($links): ?>
      <div class="links"><?php print $links; ?></div>
    <?php endif; ?>
    <?php if ($more): ?>
      <div class="more-link"><?php print $more; ?></div>
    <?php endif; ?>
  </div>
</div>
