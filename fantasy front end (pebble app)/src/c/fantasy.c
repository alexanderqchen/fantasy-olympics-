#include "pebble.h"

#define NUM_MENU_SECTIONS 5
#define NUM_FIRST_MENU_ITEMS 6
#define NUM_SECOND_MENU_ITEMS 6
#define NUM_THIRD_MENU_ITEMS 6


static Window *s_main_window;
static SimpleMenuLayer *s_simple_menu_layer;
static SimpleMenuSection s_menu_sections[NUM_MENU_SECTIONS];
static SimpleMenuItem s_first_menu_items[NUM_FIRST_MENU_ITEMS];
static SimpleMenuItem s_second_menu_items[NUM_SECOND_MENU_ITEMS];
static SimpleMenuItem s_third_menu_items[NUM_THIRD_MENU_ITEMS];
static SimpleMenuItem s_open_menu_items[1];
static SimpleMenuItem s_stat_menu_items[1];


static bool s_special_flag = false;
static int s_hit_count = 0;

static void menu_select_callback1(int index, void *ctx) {
  
  s_first_menu_items[index].subtitle = "Vote recorded!";
  layer_mark_dirty(simple_menu_layer_get_layer(s_simple_menu_layer));
}

static void menu_select_callback2(int index, void *ctx) {
  
  s_second_menu_items[index].subtitle = "Vote recorded!";
  layer_mark_dirty(simple_menu_layer_get_layer(s_simple_menu_layer));
}

static void menu_select_callback3(int index, void *ctx) {
  
  s_third_menu_items[index].subtitle = "Vote recorded!";
  layer_mark_dirty(simple_menu_layer_get_layer(s_simple_menu_layer));
}

static void menu_select_open(int index, void *ctx) {
  
  s_open_menu_items[index].subtitle = "Opened!";
  layer_mark_dirty(simple_menu_layer_get_layer(s_simple_menu_layer));
}

static void menu_select_stat(int index, void *ctx) {
  
  s_stat_menu_items[index].subtitle = "Opened!";
  layer_mark_dirty(simple_menu_layer_get_layer(s_simple_menu_layer));
}

static void special_select_callback(int index, void *ctx) {
  // Of course, you can do more complicated things in a menu item select callback
  // Here, we have a simple toggle
  s_special_flag = !s_special_flag;

  SimpleMenuItem *menu_item = &s_first_menu_items[index];

  if (s_special_flag) {
    menu_item->subtitle = "Okay, it's not so special.";
  } else {
    menu_item->subtitle = "Well, maybe a little.";
  }

  if (++s_hit_count > 5) {
    menu_item->title = "Very Special Item";
  }

  layer_mark_dirty(simple_menu_layer_get_layer(s_simple_menu_layer));
}

static void main_window_load(Window *window) {
  // Although we already defined NUM_FIRST_MENU_ITEMS, you can define
  // an int as such to easily change the order of menu items later
  
  int num_open_items = 0;
  
  s_open_menu_items[num_open_items++] = (SimpleMenuItem) {
    .title = "click",
    .callback = menu_select_open,
  };
  
  s_menu_sections[0] = (SimpleMenuSection) {
    .title="Open LA 2024",
    .num_items = 1,
    .items = s_open_menu_items,
  };
  
  int num_stat_items = 0;
  
  s_stat_menu_items[num_stat_items++] = (SimpleMenuItem) {
    .title = "click",
    .callback = menu_select_stat,
  };
  
  s_menu_sections[1] = (SimpleMenuSection) {
    .title="Show Statisitics of USA Gold",
    .num_items = 1,
    .items = s_stat_menu_items,
  };
  
  int num_a_items = 0;

  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "USA",
    .callback = menu_select_callback1,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Canada",
    .callback = menu_select_callback1,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "China",
    .callback = menu_select_callback1,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Japan",
    .callback = menu_select_callback1,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Brazil",
    .callback = menu_select_callback1,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "India",
    .callback = menu_select_callback1,
  };

  s_menu_sections[2] = (SimpleMenuSection) {
    .title="Boxing",
    .num_items = NUM_FIRST_MENU_ITEMS,
    .items = s_first_menu_items,
  };
  
  int num_b_items = 0;

  s_second_menu_items[num_b_items++] = (SimpleMenuItem) {
    .title = "USA",
    .callback = menu_select_callback2,
  };
  s_second_menu_items[num_b_items++] = (SimpleMenuItem) {
    .title = "Canada",
    .callback = menu_select_callback2,
  };
  s_second_menu_items[num_b_items++] = (SimpleMenuItem) {
    .title = "China",
    .callback = menu_select_callback2,
  };
  s_second_menu_items[num_b_items++] = (SimpleMenuItem) {
    .title = "Japan",
    .callback = menu_select_callback2,
  };
  s_second_menu_items[num_b_items++] = (SimpleMenuItem) {
    .title = "Brazil",
    .callback = menu_select_callback2,
  };
  s_second_menu_items[num_b_items++] = (SimpleMenuItem) {
    .title = "India",
    .callback = menu_select_callback2,
  };

  s_menu_sections[3] = (SimpleMenuSection) {
    .title="Gymnastics",
    .num_items = NUM_SECOND_MENU_ITEMS,
    .items = s_second_menu_items,
  };
  
  int num_c_items = 0;
  
  s_third_menu_items[num_c_items++] = (SimpleMenuItem) {
    .title = "USA",
    .callback = menu_select_callback3,
  };
  s_third_menu_items[num_c_items++] = (SimpleMenuItem) {
    .title = "Canada",
    .callback = menu_select_callback3,
  };
  s_third_menu_items[num_c_items++] = (SimpleMenuItem) {
    .title = "China",
    .callback = menu_select_callback3,
  };
  s_third_menu_items[num_c_items++] = (SimpleMenuItem) {
    .title = "Japan",
    .callback = menu_select_callback3,
  };
  s_third_menu_items[num_c_items++] = (SimpleMenuItem) {
    .title = "Brazil",
    .callback = menu_select_callback3,
  };
  s_third_menu_items[num_c_items++] = (SimpleMenuItem) {
    .title = "India",
    .callback = menu_select_callback3,
  };

  s_menu_sections[4] = (SimpleMenuSection) {
    .title="SOCCER",
    .num_items = NUM_THIRD_MENU_ITEMS,
    .items = s_third_menu_items,
  };

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  s_simple_menu_layer = simple_menu_layer_create(bounds, window, s_menu_sections, NUM_MENU_SECTIONS, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(s_simple_menu_layer));
}

void main_window_unload(Window *window) {
  simple_menu_layer_destroy(s_simple_menu_layer);
}

static void init() {
  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  window_stack_push(s_main_window, true);
}

static void deinit() {
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}