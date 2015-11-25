<?php

function _wami_endpoint() {
  
  $result = array();
  
  if ($_SERVER['REQUEST_METHOD'] == 'GET') {
    $result += _wami_endpoint_play();
  }
  elseif ($_SERVER['REQUEST_METHOD'] == 'PUT' || $_SERVER['REQUEST_METHOD'] == 'POST') {
    $result += _wami_endpoint_record();
  }
  else {
    $result['status']['error'] []= 'Request method not handled.';
  }
  
  // Print results
  header ('Content-type: text/javascript');
  echo json_encode($result);
  module_invoke_all('exit');
  exit;
  
}

function _wami_endpoint_play () {
  
  $result = array();
  if (isset($_REQUEST['name'])) {
    $name = $_REQUEST['name'];
    $file = wami_jam_session_get($name);
    if ($file !== NULL) {
      $result['file'] = $file;
      $result['status']['success'] []= 'File loaded';
      
      header('Content-type: audio/wav');
      echo file_get_contents($file->uri);
      module_invoke_all('exit');
      exit;
      
    }
    else {
      $result['status']['error'] []= 'Problem loading file';
    }
  }
  else {
    $result['status']['error'] []= 'WAMI file name missing';
  }
  
  return $result;
  
}

function _wami_endpoint_record () {
  
  $result = array();
  
  // TODO: Replace file if session key already set...
  $content = file_get_contents('php://input');
  if ($content) {
    $destination = 'temporary://wami.wav';
    $file = file_save_data($content, $destination);
    $result['file'] = $file;
    if ($file !== FALSE) {
      $result['status']['success'] []= 'File saved';
      if (isset($_REQUEST['name'])) {
        wami_jam_session_set($_REQUEST['name'], $file);
        $result['status']['success'] []= 'File indexed in WAMI session';
      }
      else {
        $result['status']['error'] []= 'WAMI "name" missing';
      }
    }
    else {
      $result['status']['error'] []= 'Problem writing file';
    }
  }
  else {
    $result['status']['error'] []= 'Problem reading input';
  }
  
  return $result;
  
}
