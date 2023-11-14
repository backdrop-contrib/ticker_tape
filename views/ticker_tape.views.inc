<?php
/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements hook_views_plugins().
 */
function ticker_tape_views_plugins() {
  $module_path = backdrop_get_path('module', 'ticker_tape');

  return array(
    'style' => array(
      'ticker_take_horizontal_plugin_style' => array(
        'title' => t('Horizontal Ticker Tape'),
        'help' => t('Smooth Horizontal Ticker Tape style scoller - Left to Right.'),
        'handler' => 'ticker_tape_horizontal_plugin_style',
        'theme' => 'ticker_tape_horizontal_plugin_style',
        'path' => $module_path . '/styles',
        'theme path' => $module_path . '/styles',
        'theme file' => 'ticker_tape_horizontal_theme.inc',
        'type' => 'normal',
        'parent' => 'default',
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
      ),
    ),
  );
}
