Drupal.behaviors.vote_reset = function (context) {
  if (!$('.vud-widget').hasClass('vud-widget-processed')) {
    $('.vote-thumb').click(function(){
      if($(this).hasClass('up-active') || $(this).hasClass('down-active')){
        $(this).parents('.vud-widget').find('.vud-link-reset').click();
      }
    });
  }
};
