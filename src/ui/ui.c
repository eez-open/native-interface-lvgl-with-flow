#include "ui.h"
#include "screens.h"
#include "images.h"
#include "flow_def.h"
#include "actions.h"
#include "vars.h"

ActionExecFunc actions[] = {
    action_login,
    action_inc_counter,
    action_dec_counter,
};


void ui_init() {
    eez_flow_init(assets, sizeof(assets), (lv_obj_t **)&objects, sizeof(objects), images, sizeof(images), actions);
    init_vars();
}

void ui_tick() {
    eez_flow_tick();
    tick_vars();
    tick_screen(g_currentScreen);
}
