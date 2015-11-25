
jQuery(window).ready(function(){
  
  jQuery('.wami').each(function(index, element){
    
    var swfUrl = jQuery(element).attr("swfUrl");
    var id = jQuery(element).attr("id");
    
    Wami.setup({
      id: id,
      swfUrl: swfUrl,
      onReady: setupGUI
    });
    
    function setupGUI() {
      
      var buttonUrl = jQuery('#'+id).attr("buttonUrl");
      var recordUrl = jQuery('#'+id).attr("recordUrl");
      var playUrl = jQuery('#'+id).attr("playUrl");
      
      // Load the GUI
      var gui = new Wami.GUI({
        id: id,
        buttonUrl: buttonUrl,
        recordUrl: recordUrl,
        playUrl: playUrl
      });

      // Nothing recorded yet, so turn off play button
      gui.setPlayEnabled(false);
      
    }
    
  });
  
  
});
