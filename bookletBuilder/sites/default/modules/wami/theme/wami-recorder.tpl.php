<?php 
/**
 * Variables:
 *   $record_url - Endpoint for sending WAMI recordings
 *   $play_url - Endpoint for playing WAMI audio
 *   $wami_session_key - WAMI session key
 */
global $base_url; 
?>
<div 
  class="wami"
  id="<?php echo $widget_id ?>"
  swfUrl = "<?php echo $base_url ?>/sites/all/libraries/wami/Wami.swf"
  buttonUrl = "<?php echo $base_url ?>/sites/all/libraries/wami/buttons.png"
  recordUrl = "<?php echo $record_url ?>"
  playUrl = "<?php echo $play_url ?>"
><noscript>...</noscript></div>
