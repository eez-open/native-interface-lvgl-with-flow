#include <lvgl/lvgl.h>

#include "actions.h"
#include "screens.h"
#include "ui.h"

extern int32_t counter;

void action_login(lv_event_t *e) {
    eez_flow_set_screen(SCREEN_ID_HOME, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0);
}

void action_inc_counter(lv_event_t *e) {
    counter++;
}

void action_dec_counter(lv_event_t *e) {
    counter--;
}
