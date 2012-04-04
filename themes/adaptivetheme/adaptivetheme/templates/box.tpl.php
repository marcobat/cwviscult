<?php // $Id: box.tpl.php,v 1.2.2.1 2010/09/14 20:13:12 jmburnz Exp $

/**
 * @file
 * Theme implementation to display a box.
 *
 * Available variables:
 * - $title: Box title.
 * - $content: Box content.
 *
 * @see template_preprocess()
 */
?>
<div class="box"><div class="box-inner">
  <?php if ($title): ?>
    <h2 class="box-title title"><?php print $title ?></h2>
  <?php endif; ?>
  <?php print $content ?>
</div></div>
