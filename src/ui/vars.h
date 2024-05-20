#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

typedef enum {
    UserRole_Guest = 0,
    UserRole_Member = 1,
    UserRole_Admin = 2
} UserRole;

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_USERS = 0,
    FLOW_GLOBAL_VARIABLE_USER_NAMES = 1,
    FLOW_GLOBAL_VARIABLE_USER_IDX = 2,
    FLOW_GLOBAL_VARIABLE_SELECTED_USER_INDEX = 3
};

// Native global variables

extern const char *get_var_greeting_str();
extern void set_var_greeting_str(const char *value);
extern const char *get_var_counter_info();
extern void set_var_counter_info(const char *value);
extern int32_t get_var_selected_item_index();
extern void set_var_selected_item_index(int32_t value);
extern const char *get_var_selected_item_info();
extern void set_var_selected_item_info(const char *value);


void init_vars();
void tick_vars();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/