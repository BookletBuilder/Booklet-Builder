<?php

function audiorecorderfield_wav_player($player_path, $audio_file) {
  return theme('audiorecorderfield_wav_player', array('player_path' => $player_path, 'audio_file' => $audio_file));
}

function theme_audiorecorderfield_wav_player($variables) {
  $player_path = $variables['player_path'];
  $audio_file = $variables['audio_file'];
  drupal_add_js(drupal_get_path('module', 'audiorecorderfield') . '/js/wav_player.js');
  $app_gui = isset($variables['app_gui']) ? $variables['app_gui'] : 'full';
  $app_width = isset($variables['app_width']) ? $variables['app_width'] : 300;
  $app_height = isset($variables['app_height']) ?  $variables['app_height'] : 20;
  $container_width = isset($variables['container_width']) ? $variables['container_width'] : 305;
  $container_height = isset($variables['container_height']) ? $variables['container_height'] : 21;
  $output = '<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
    width="'.$container_width.'"
    height="'.$container_height.'"
    id="haxe"
    align="middle">
<param name="movie" value="'.$player_path.'?gui='.$app_gui.'&h='.$app_height.'&w='.$app_width.'&sound='.$audio_file.'&"/>
<param name="allowScriptAccess" value="always" />
<param name="quality" value="high" />
<param name="scale" value="noscale" />
<param name="salign" value="lt" />
<param name="bgcolor" value="#dddddd"/>
<embed src="'.$player_path.'?gui='.$app_gui.'&h='.$app_height.'&w='.$app_width.'&sound='.$audio_file.'&"
       bgcolor="#dddddd"
       width="'.$container_width.'"
       height="'.$container_height.'"
       name="haxe"
       quality="high"
       align="middle"
       scale="noscale"
       allowScriptAccess="always"
       type="application/x-shockwave-flash"
       pluginspage="http://www.macromedia.com/go/getflashplayer"
/>
</object>';
   return $output;
}