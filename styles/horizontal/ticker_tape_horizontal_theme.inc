<?php

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_ticker_tape_horizontal_plugin_style(&$vars) {

  backdrop_add_css( backdrop_get_path('module', 'ticker_tape') . '/styles/horizontal/ticker_tape_horizontal.css',
    array('type' => 'file',
      'preprocess' => TRUE,
      // Load very early so that it's very easy for other CSS to override it.
      'group' => CSS_SYSTEM,
      'weight' => -1000,
    )
  );

  // Run preprocess function for unformatted style.
  template_preprocess_views_view_unformatted($vars);

  // Get view options.
  $view = $vars['view'];
  $options = $vars['options'];
}