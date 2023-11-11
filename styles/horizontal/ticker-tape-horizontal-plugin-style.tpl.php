<?php

/**
 * @file
 * Default view template to display content using ticker_tape layout_type.
 */

 // Padding for the each selection of the results and for each field.
 // The row/selection is then combined into one line.
$ticker_padding_item = $options['ticker_padding_item'];
$ticker_padding_field = $options['ticker_padding_field'];

// Duration in seconds
$ticker_duration = $options['ticker_duration'];

// Height of the ticker wrapper
$ticker_height = $options['ticker_height'];

// Pre and Post CSS.
$div_class = '';
$div_class = '<div class="ticker-wrap"><div class="ticker" ' . $css_style;

print $div_class . '>';

foreach ($rows as $id => $row) {
  if ($row_classes[$id]) {
    print '<div class="ticker__item ' . implode(' ', $row_classes[$id]) . '">' . $row . '</div>';
  }
}

print '</div></div>';

//Add CSS for this View
$viewname = $view->name;
$viewname = str_replace('_', '-', $viewname);
$module_path = backdrop_get_path('module', 'ticker_tape');
require_once $module_path . '/libraries/class-php-css.php';

use CarlosRios\PHP_CSS;
$css = new PHP_CSS();

$css->set_selector( '.view-' . $viewname );
$css->add_property( 'overflow', 'hidden');

$css->set_selector( '.ticker-wrap' );
$css->add_property( 'height', $ticker_height );

$css->set_selector( '.ticker' );
$css->add_property( 'animation-duration', $ticker_duration . 's;' );

$css->set_selector( '.ticker__item' );
$css->add_property( 'padding', $ticker_padding_item );

$css->set_selector( '.views-field' );
$css->add_property( 'padding', $ticker_padding_field );


file_put_contents( $module_path . '/css/tickertape.css', $css->css_output() );
backdrop_add_css( $module_path . '/css/tickertape.css');