
(function ($) {

  Drupal.behaviors.amadeus_smartdocs = {
    attach: function (context, settings) {

      var app_api_key = Drupal.settings.app_api_key;

      $('#method_content .row .table-responsive tbody > tr ').each(function() {
        // cycle through td span - if match update td input value
        if ( $(this).find('td span').html() == 'apikey') {
          $(this).find('td input').val(app_api_key);
        }
      });

    },
    detach: function (context) {
    }
  }

}(jQuery));

































