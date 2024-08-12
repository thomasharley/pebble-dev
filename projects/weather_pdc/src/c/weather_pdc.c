#include <pebble.h>

static Window *s_main_window;

static GDrawCommandImage *s_command_image;

static Layer *s_canvas_layer;

static void update_proc(Layer *layer, GContext *ctx) {
  // Set the origin offset from the context for drawing the image
  GPoint origin = GPoint(10, 20);

  // Draw the GDrawCommandImage to the GContext
  gdraw_command_image_draw(ctx, s_command_image, origin);
}

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // Create the canvas Layer
  s_canvas_layer = layer_create(GRect(30, 30, bounds.size.w, bounds.size.h));

  // Set the LayerUpdateProc
  layer_set_update_proc(s_canvas_layer, update_proc);

  // Add to parent Window
  layer_add_child(window_layer, s_canvas_layer);
}

static void main_window_unload(Window *window) {

  layer_destroy(s_canvas_layer);
  gdraw_command_image_destroy(s_command_image);
}

static void init() {
  s_main_window = window_create();
  window_set_background_color(s_main_window, GColorBlueMoon);

  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });

  // Create the object from resource file
  s_command_image = gdraw_command_image_create_with_resource(RESOURCE_ID_WEATHER_IMAGE);

  window_stack_push(s_main_window, true);

}

static void deinit() {
  window_destroy(s_main_window);
}

int main() {
  init();
  app_event_loop();
  deinit();
}
