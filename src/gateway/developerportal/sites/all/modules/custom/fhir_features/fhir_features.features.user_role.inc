<?php
/**
 * @file
 * fhir_features.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function fhir_features_user_default_roles() {
  $roles = array();

  // Exported role: healthcare_site_user.
  $roles['healthcare_site_user'] = array(
    'name' => 'healthcare_site_user',
    'weight' => 3,
  );

  return $roles;
}
