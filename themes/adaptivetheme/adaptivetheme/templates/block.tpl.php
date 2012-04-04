<?php // $Id: block.tpl.php,v 1.2.2.2 2010/10/14 05:38:00 jmburnz Exp $

/**
 * @file
 * Theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $block->content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: This is a numeric id connected to each module.
 * - $block->region: The block region embedding the current block.
 *
 * Helper variables:
 * - $block_module_delta: Outputs a unique css id for each block.
 * - $classes: Outputs dynamic classes for advanced themeing.
 * - $edit_links: Outputs hover style links for block configuration and editing.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see genesis_preprocess_block()
 */
?>
<div id="<?php print $block_module_delta; ?>" class="<?php print $classes; ?>">
  <div class="block-inner">
    <?php if ($block->subject): ?>
      <h2 class="<?php print $title_classes; ?>"><?php print $block->subject; ?></h2>
    <?php endif; ?>
    <div class="<?php print $content_classes; ?>"><?php print $block->content ?></div>
    <?php print $edit_links; ?>
  </div>
</div>
