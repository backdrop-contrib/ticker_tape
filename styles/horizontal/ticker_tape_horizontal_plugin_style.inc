<?php
/**
 * @file
 * Contains the ticker_tape_horizontal style plugin.
 */

class ticker_tape_horizontal_plugin_style extends views_plugin_style {

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['ticker_padding_item'] = array('default' => "0em 2em");
    $options['ticker_padding_field'] = array('default' => "0em 1em");
    $options['ticker_duration'] = array('default' => 30);
    $options['ticker_height'] = array('default' => "150px");


    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['layout_info'] = array(
      '#markup' => '<h4>' . t('Layout tips') . '</h4><p>' . t('Select the padding and duration.  Duration is how long the ticker will take to do one full scroll.') . '</p>',
    );
    $form['ticker_padding_item'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS Padding between items.'),
      '#size' => 25,
      '#maxlength' => 25,
      '#default_value' => $this->options['ticker_padding_item'],
      '#description' => t('Enter the required padding around each data item.  Can be em px rem etc...'),
    );
    $form['ticker_padding_field'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS Padding between fields.'),
      '#size' => 25,
      '#maxlength' => 25,
      '#default_value' => $this->options['ticker_padding'],
      '#description' => t('Enter the required padding around each field.  Can be em px rem etc...'),
    );
    $form['ticker_height'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS Height of the wrapper.'),
      '#size' => 25,
      '#maxlength' => 25,
      '#default_value' => $this->options['ticker_height'],
      '#description' => t('Enter the required height of the ticker tape.  Can be em px rem etc...'),
    );
    $form['ticker_duration'] = array(
      '#type' => 'number',
      '#title' => t('Duration in seconds.'),
      '#size' => 20,
      '#maxlength' => 4,
      '#min' => 1,
      '#max' => 9999,
      '#default_value' => $this->options['ticker_duration'],
      '#description' => t('Enter the required duration for one loop of the text to take.'),
    );
  }
}

