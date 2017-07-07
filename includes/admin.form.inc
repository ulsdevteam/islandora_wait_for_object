<?php

/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_wait_for_object_admin() {
  $form = array(
    'islandora_wait_for_object_max_seconds' => array(
      '#type' => 'textfield',
      '#title' => t("Maximum wait time for datastream object"),
      '#default_value' => variable_get('islandora_wait_for_object_max_seconds', 30),
      '#description' => t('Higher values may result in greater stability during ingest but slower overall ingest time while lower values may terminate ingests that could actually still have good objects (eventually).'),
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    ),
  );
  return $form;
}

/**
 * Form submit.
 */
function islandora_wait_for_object_admin_submit($form, &$form_state) {
  $id = $form_state['triggering_element']['#id'];
  switch ($id) {
    case 'edit-submit':
      variable_set('islandora_wait_for_object_max_seconds', $form_state['values']['islandora_wait_for_object_max_seconds']);
  }
  drupal_set_message(t('The settings have been updated!'));
}

