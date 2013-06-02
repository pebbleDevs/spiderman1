#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"
//#include "myPebbleFunctions.h"

// MACRO SECTION
#define MY_UUID { 0x9C, 0xED, 0xF6, 0x88, 0x14, 0xE3, 0x45, 0x61, 0x99, 0x65, 0x0E, 0x84, 0x63, 0x13, 0x8B, 0x34 }
PBL_APP_INFO(MY_UUID,
             "Spiderman 1", "mApps Lab",
             1, 0, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_WATCH_FACE);


// GLOBAL DECLARATION //
Window window;
//Bitmap area for logo
BmpContainer background_image;
Layer background_layer;

TextLayer text_time_layer;
TextLayer text_hr_layer;
TextLayer text_min_layer;
TextLayer text_ampm_layer;
TextLayer text_date_layer;
TextLayer text_month_layer;
TextLayer text_day_layer;

GFont font_russo;

TextLayer text_creditLine1_layer;
TextLayer text_creditLine2_layer;
TextLayer text_versionInfo_layer;

//////////////////////////////////////
////// CUSTOM FUNCTIONS //////////////
/////////////////////////////////////

void creditBanner()
{
 
 //initilizing the creditline layer
  text_layer_init(&text_creditLine1_layer, window.layer.frame);
  //setting the layer attributes
  text_layer_set_text_color(&text_creditLine1_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine1_layer, GColorClear);
  //positing attributes
  text_layer_set_text_alignment(&text_creditLine1_layer, GTextAlignmentRight);
  layer_set_frame(&text_creditLine1_layer.layer, GRect(0,65,144,30)); //GRect(X,Y, Width, Height)
  //Font attribute
  //gunplay_40 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_GUNPLAY_40));
  text_layer_set_font(&text_creditLine1_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  layer_add_child(&window.layer, &text_creditLine1_layer.layer);
  text_layer_set_text(&text_creditLine1_layer,"Developed By");
  
  //initilizing the layer  
  text_layer_init(&text_creditLine2_layer, window.layer.frame);
  //setting the layer attributes 
  text_layer_set_text_color(&text_creditLine2_layer, GColorBlack);
  text_layer_set_background_color(&text_creditLine2_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_creditLine2_layer, GTextAlignmentRight);
  layer_set_frame(&text_creditLine2_layer.layer, GRect(0,80,144,30));
  //Font attribute
  //gunplay_40 = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  text_layer_set_font(&text_creditLine2_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  layer_add_child(&window.layer, &text_creditLine2_layer.layer);
  text_layer_set_text(&text_creditLine2_layer,"alokc83");
  
      //initilizing the text_versionInfo_layer  
  text_layer_init(&text_versionInfo_layer, GRect(75,100,60,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_versionInfo_layer, GColorBlack);
  text_layer_set_background_color(&text_versionInfo_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_versionInfo_layer, GTextAlignmentRight);
  //Font attribute
  text_layer_set_font(&text_versionInfo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  layer_add_child(&window.layer, &text_versionInfo_layer.layer);
  text_layer_set_text(&text_versionInfo_layer, "v1.0");
}

/////////////////////////////////////////////////
///////// END OF CUSTOM FUNCTIONS///////////////
////////////////////////////////////////////////

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Spiderman");
  window_stack_push(&window, true /* Animated */);
  window_set_background_color(&window, GColorWhite);
  
  //Resource Map initialization
  resource_init_current_app(&APP_RESOURCES);
  
  // gfx layer init 
  layer_init(&background_layer, GRect(-20,0,88,168));
  bmp_init_container(RESOURCE_ID_SPIDERMAN_BOW, &background_image);
  layer_add_child(&window.layer, &background_image.layer.layer);
  // as init layer is not updating the cordinates, i have to redo it.
  layer_set_frame(&background_image.layer.layer, GRect(-20,0,88,168)); 

 
  //initilizing the text hr layer
  text_layer_init(&text_hr_layer, GRect(35,-5,144,80));
  text_layer_set_text_color(&text_hr_layer, GColorBlack);
  text_layer_set_background_color(&text_hr_layer, GColorClear);
  text_layer_set_text_alignment(&text_hr_layer, GTextAlignmentCenter);
  //Font atterbutes
  font_russo = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_RUSSO_42));
  text_layer_set_font(&text_hr_layer, font_russo);
  layer_add_child(&window.layer, &text_hr_layer.layer);
  
    //initilizing the text min layer
  text_layer_init(&text_min_layer, GRect(35,30,144,80));
  text_layer_set_text_color(&text_min_layer, GColorBlack);
  text_layer_set_background_color(&text_min_layer, GColorClear);
  text_layer_set_text_alignment(&text_min_layer, GTextAlignmentCenter);
  //Font atterbutes
  font_russo = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_RUSSO_42));
  text_layer_set_font(&text_min_layer, font_russo);
  layer_add_child(&window.layer, &text_min_layer.layer);
  
  //initilizing the AM_PM layer  
  text_layer_init(&text_ampm_layer, GRect(116,68,25,20));
  //text_layer_init(&text_ampm_layer, GRect(60,45,25,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_ampm_layer, GColorBlack);
  text_layer_set_background_color(&text_ampm_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_ampm_layer, GTextAlignmentRight);  
  //Font attribute
  text_layer_set_font(&text_ampm_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  layer_add_child(&window.layer, &text_ampm_layer.layer);

  
  //initilizing the day of week layer  
  //text_layer_init(&text_day_layer, window.layer.frame);
 //layer_set_frame(&text_day_layer.layer, GRect(10,143,30,148));
  text_layer_init(&text_day_layer, GRect(116,130,30,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_day_layer, GColorBlack);
  text_layer_set_background_color(&text_day_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_day_layer, GTextAlignmentLeft);
  //Font attribute
  text_layer_set_font(&text_day_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  layer_add_child(&window.layer, &text_day_layer.layer);

  //initilizing the Month layer  
  //text_layer_init(&text_month_layer, window.layer.frame);
 //layer_set_frame(&text_month_layer.layer, GRect(10,143,30,148));
  text_layer_init(&text_month_layer, GRect(98,143,25,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_month_layer, GColorBlack);
  text_layer_set_background_color(&text_month_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_month_layer, GTextAlignmentRight);
  //Font attribute
  text_layer_set_font(&text_month_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  layer_add_child(&window.layer, &text_month_layer.layer);
  
  
  //initilizing the date layer  
  //text_layer_init(&text_date_layer, window.layer.frame);
  //layer_set_frame(&text_date_layer.layer, GRect(60,143,65,148));
  //instead of above two line line below can be used.
  text_layer_init(&text_date_layer, GRect(125,143,16,20));
  //setting the layer attributes 
  text_layer_set_text_color(&text_date_layer, GColorBlack);
  text_layer_set_background_color(&text_date_layer, GColorClear);
  //positiong attribute
  text_layer_set_text_alignment(&text_date_layer, GTextAlignmentRight);
  
  //Font attribute
  text_layer_set_font(&text_date_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  layer_add_child(&window.layer, &text_date_layer.layer);
  
  creditBanner();
  
 // PblTm tick_time;
  //get_time(&tick_time);
}

void handle_minute_tick(AppContextRef ctx, PebbleTickEvent *t) {

  (void)ctx;
  
  //static char time_text[] = "00:00";
  static char hr_text[] = "00";
  static char min_text[] = "00";
  static char ampm_text[] = "XX";
  static char day_text[] = "XXX";
  static char new_day_text[] = "YYY";
  static char month_text[] = "XXX";
  static char date_text[] = "XX";
  static char new_date_text[] = "00";
  
  char *hr_format; // TODO for 12 or 24 hrs support
  PblTm current_time;
  get_time(&current_time);
 
 // Hiding the credit line layers
 psleep(1000);
 layer_set_hidden((Layer *)&text_creditLine1_layer, true);
 layer_set_hidden((Layer *)&text_creditLine2_layer, true);
 layer_set_hidden((Layer *)&text_versionInfo_layer, true);
 // repositioning gfx layer
 layer_set_frame(&background_image.layer.layer, GRect(0,0,88,168)); 
 
 if (clock_is_24h_style()) {
   hr_format = "%R";
  } else {
    hr_format = "%I";
    //setting am or pm 
    string_format_time(ampm_text,sizeof(ampm_text), "%p", &current_time);
    text_layer_set_text(&text_ampm_layer, ampm_text);
  }
 
 string_format_time(hr_text, sizeof(hr_text), hr_format, &current_time);
 text_layer_set_text(&text_hr_layer, hr_text);
 string_format_time(min_text, sizeof(min_text), "%M", &current_time);
 text_layer_set_text(&text_min_layer, min_text);

//populating day layer
//Not pupulating unless day is different
  string_format_time(new_day_text,sizeof(day_text), "%a", &current_time);
  if(strncmp(new_day_text, day_text, sizeof(day_text)) != 0)
  	{
  		strncpy(day_text, new_day_text, sizeof(day_text));
  		text_layer_set_text(&text_day_layer, day_text);
  	}
//populating month layer %b=Jun, %B = June
 string_format_time(month_text, sizeof(month_text), "%b", &current_time);
text_layer_set_text(&text_month_layer, month_text);

//populating date field 
//Not pupulating unless date is different
  string_format_time(new_date_text,sizeof(date_text), "%d", &current_time);
  if(strncmp(new_date_text, date_text, sizeof(date_text)) != 0)
  	{
  		strncpy(date_text, new_date_text, sizeof(date_text));
  		text_layer_set_text(&text_date_layer, date_text);
  	}

}

//dealloccation when watchface is close
void handle_deinit(AppContextRef ctx) {
        (void)ctx;
      vibes_short_pulse();
      bmp_deinit_container(&background_image);
      fonts_unload_custom_font(font_russo);
      //  fonts_unload_custom_font(batman_letters_20);
     //   fonts_unload_custom_font(batman_numbers_40);
     
}


/*
void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
} */ // main created by project creator

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,
    .deinit_handler = &handle_deinit,

    .tick_info = {
      .tick_handler = &handle_minute_tick,
      .tick_units = MINUTE_UNIT
    }

  };
  app_event_loop(params, &handlers);
}
