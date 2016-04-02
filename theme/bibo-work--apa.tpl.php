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
  <?php print $author; ?> (<?php print $publication_status; ?>). <strong><?php print $title; ?>.</strong>
</div>