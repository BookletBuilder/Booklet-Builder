<?php

// Database settings:
$databases = array(
  'default' => array(
    'default' => array(
      'database' => 'YOUR_DATABASE',
      'username' => 'YOUR_USERNAME',
      'password' => 'YOUR_PASSWORD',
      'host' => 'YOUR_DATABASE_HOST',
      'port' => '3306', // <-- THE DEFAULT IS 3306
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

// Access control for update.php script.
$update_free_access = FALSE;

// Salt for one-time login links and cancel links, form tokens, etc.
$drupal_hash_salt = 'CHANGE_ME_TO_A_UNIQUE_VALUE';

// Base URL (optional).
# $base_url = 'http://www.example.com';  // NO trailing slash!

// PHP settings:
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);
# ini_set('pcre.backtrack_limit', 200000);
# ini_set('pcre.recursion_limit', 200000);

// Cookie domain override:
# $cookie_domain = '.example.com';

// Variable overrides:
# $conf['site_name'] = 'My Drupal site';
# $conf['theme_default'] = 'garland';
# $conf['anonymous'] = 'Visitor';

// See http://drupal.stackexchange.com/questions/63226/drupal-7-20-image-styles-return-a-url-with-access-denied
$conf['image_allow_insecure_derivatives'] = TRUE;

// A custom theme can be set for the offline page.
# $conf['maintenance_theme'] = 'bartik';



/**
 * Reverse Proxy Configuration:
 */
 
# $conf['reverse_proxy'] = TRUE;
# $conf['reverse_proxy_addresses'] = array('a.b.c.d', ...);
# $conf['reverse_proxy_header'] = 'HTTP_X_CLUSTER_CLIENT_IP';



/**
 * Page caching:
 */
 
# $conf['omit_vary_cookie'] = TRUE;



/**
 * CSS/JS aggregated file gzip compression:
 */
 
# $conf['css_gzip_compression'] = FALSE;
# $conf['js_gzip_compression'] = FALSE;



/**
 * String overrides:
 */
 
# $conf['locale_custom_strings_en'][''] = array(
#   'forum'      => 'Discussion board',
#   '@count min' => '@count minutes',
# );



/**
 * IP blocking:
 */
 
# $conf['blocked_ips'] = array(
#   'a.b.c.d',
# );



/**
 * Fast 404 pages:
 */ 
 
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';
# drupal_fast_404();



/**
 * Authorized file system operations:
 */
 
# $conf['allow_authorize_operations'] = FALSE;
