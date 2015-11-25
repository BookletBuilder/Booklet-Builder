<?php

/**
 * Implements hook_field_widget_info().
 */
function wami_field_widget_info() {
  return array(
    'wami_widget' => array(
      'label' => t('WAMI Flash audio recorder'),
      'field types' => array('file'),
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}

function wami_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element){

  // Call parent handler
  $field['settings']['display_field'] = 0; // Required by file_field_widget_form()
  $elements = file_field_widget_form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);

  foreach (element_children($elements) as $delta) {
    if (TRUE) {
      // Modify parent widget
      $elements[$delta]['#process'] []= '_wami_field_widget_process';
      $elements[$delta]['#value_callback'] = '_wami_field_widget_value';
    }
    else {
      // Use default
    }
  }
  
  return $elements;
  
}

/**
 * Per-widget field element processing (returns $element structure)
 */
function _wami_field_widget_process($element, &$form_state, $form) {
  
  // Run parent handler
  $element = file_field_widget_process($element, $form_state, $form);
  
  if (_wami_file_missing($element)) {
    $wami_session_key = $form['form_build_id']['#value'].'-'.implode('-', $element['#parents']);
    $element['wami_widget'] = array(
    	'#markup' => theme('wami_recorder', array(
        'widget_id' => implode('-', $element['#parents']),
    	  'record_url' => url('wami-endpoint', array('absolute' => TRUE, 'query' => array('name' => $wami_session_key))),
        'play_url' => url('wami-endpoint', array('absolute' => TRUE, 'query' => array('name' => $wami_session_key))),
        'wami_session_key' => $wami_session_key
      )),
    );
    unset($element['#description']);
    $element['upload']['#access'] = FALSE;
    $element['upload_button']['#access'] = FALSE;
  }
  else {
    // File already available, use default formatting
  }

  return $element;
  
}

/**
 * Set the $input['fid']
 */
function _wami_field_widget_value (&$element, $input = FALSE, $form_state = NULL) {
  
  // Call parent handler
  $result = file_field_widget_value($element, $input, $form_state);
  $fid = $result['fid'];
  
  $wami_session_key = $form_state['complete form']['#build_id'].'-'.implode('-', $element['#parents']);
  $wami_file = wami_jam_session_get($wami_session_key);
  if ($wami_file) {
    $file = _wami_file_copy($wami_file, $element);
    file_usage_add($file, 'user', 'user', $GLOBALS['user']->uid);
    if ($file !== NULL) {
      $file->status = 0;
      $file = file_save($file);
      file_delete($wami_file);
      wami_jam_session_unset($wami_session_key);
      return array('fid' => $file->fid);
    }
    else {
      return array('fid' => 0);
    }
  }
  
  return $result;
 
}

function _wami_file_copy ($wami_file, $element) {
  $destination = isset($element['#upload_location']) ? $element['#upload_location'] : NULL;
  if (!isset($destination) || file_prepare_directory($destination, FILE_CREATE_DIRECTORY)) {
    $file = file_copy($wami_file, $destination);
    if ($file) {
      return $file;
    }
    else {
      watchdog('wami', 'Problem copying file.');
      form_set_error($upload_name, t('The file in the !name field was unable to be copied from WAMI.', array('!name' => $element['#title'])));
      return FALSE;
    }
  }
  else {
    watchdog('file', 'The upload directory %directory for the file field !name could not be created or is not accessible. A newly uploaded file could not be saved in this directory as a consequence, and the upload was canceled.', array('%directory' => $destination, '!name' => $element['#field_name']));
    form_set_error($upload_name, t('The file could not be uploaded.'));
    return FALSE;
  }
}

/**
 * Implements hook_field_is_empty().
 */
function wami_field_is_empty($item, $field) {
  // Run parent handler
  return file_field_is_empty($item, $field);
}

function _wami_file_missing($element) {
  $fid = isset($element['#value']['fid']) ? $element['#value']['fid'] : 0;
  return !$fid || !$element['#file'];
}
