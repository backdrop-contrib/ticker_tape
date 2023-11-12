<?php
/**
 * @file
 * Default view template to display content using ticker_tape layout_type.
 */
 ?>

<div class="ticker-wrap">
  <div class="ticker">
    <?php foreach ($rows as $id => $row) : ?>
      <div class="<?php print 'ticker__item ' . implode(' ', $row_classes[$id]); ?>">
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
