; This Drush make script assembles a development version of the Acquia Commons distribution.
; To package Commons using this script, install Drush make (http://drupal.org/project/drush_make).
; Packaging with the --working-copy flag is recommended for developers since
; it reduces the effort necessary to roll a patch against Commons components
; that live at http://drupal.org/project/commons .

core = 6.x
api = 2

projects[drupal][version] = "6.25"

projects[drupal_commons][type] = "profile"
projects[drupal_commons][download][type] = "git"
projects[drupal_commons][download][url] = "http://git.drupal.org/project/commons.git"
projects[drupal_commons][download][revision] = "6.x-2.x"