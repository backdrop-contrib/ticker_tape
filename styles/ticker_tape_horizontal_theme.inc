<?php

use CarlosRios\PHP_CSS;

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_ticker_tape_horizontal_plugin_style(&$variables) {

  template_preprocess_views_view_unformatted($variables);

  // The css file you are loading is current empty?
  backdrop_add_css(backdrop_get_path('module', 'ticker_tape') . '/styles/ticker_tape_horizontal.css');
  backdrop_add_css(backdrop_get_path('module', 'ticker_tape') . '/css/ticker_tape.css');

  $view = $variables['view'];
  $style = $view->style_plugin;
  $options = $style->options;

  // Padding for the each selection of the results and for each field.
  // The row/selection is then combined into one line.
  $ticker_padding_item = $options['ticker_padding_item'];
  $ticker_padding_field = $options['ticker_padding_field'];

  // Duration in seconds
  $ticker_duration = $options['ticker_duration'];

  // Height of the ticker wrapper
  $ticker_height = $options['ticker_height'];


  //Add CSS for this View
  $viewname = str_replace('_', '-', $view->name);
  $module_path = backdrop_get_path('module', 'ticker_tape');

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

  // I believe it's best to save this css file to thye public directory.
  file_put_contents('public://tickertape.css', $css->css_output());
  backdrop_add_css('public://tickertape.css');
}
