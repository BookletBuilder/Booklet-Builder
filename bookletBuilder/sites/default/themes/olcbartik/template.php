<?php

/**
 * Override or insert variables into the page template.
 */
function olcbartik_process_page(&$variables) {
  
  // NOTE: Passing a variable to t() is discouraged.
  // We are doing it here as a special case.
  $variables['site_name'] = olclangreplace_replace($variables['site_name']);
  
}

function olcbartik_process_html(&$variables) {
  
  // NOTE: Passing a variable to t() is discouraged.
  // We are doing it here as a special case.
  $variables['head_title'] = olclangreplace_replace($variables['head_title']);
  
}