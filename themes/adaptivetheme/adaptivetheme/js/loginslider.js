// $Id: loginslider.js,v 1.1.2.1 2010/09/11 01:38:23 jmburnz Exp $
Drupal.behaviors.LoginSlider = function (context) {
  $("#slider-login:not(.slider-login-processed)", context).each(
    function() {
      $(this).addClass('slider-login-processed').hide();
      Drupal.loginslider_toggleblock();
    }
  );
};

Drupal.loginslider_toggleblock = function() {
  $("#slider-login-link").click(
    function () {
      $("#slider-login").slideToggle("fast");
      this.blur();
      return false;
    }
  );
};