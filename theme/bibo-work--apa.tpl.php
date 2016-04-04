<?php
/**
 * @file
 * Default APA theme implementation for work entity.
 *
 * Available variables:
 * - $title: The (sanitized) entity label.
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  (<?php print render($content['bibo_publication_status']); ?>).
  <span <?php print $title_attributes; ?>>
    <?php if ($url): ?>
      <a href="<?php print $url; ?>"><?php print $title; ?></a>
    <?php else: ?>
      <?php print $title; ?>
    <?php endif; ?>
  </span>
  <?php print render($content['bibo_publisher']); ?>: 
  <?php print render($content['bibo_place']); ?>
</div>