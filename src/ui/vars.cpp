#include <stdio.h>
#include <lvgl/lvgl.h>

#include "vars.h"
#include "screens.h"
#include "structs.h"
#include "ui.h"

void init_vars() {
    // initialize flow "users" flow variable, which is of type "array:User", i.e. array of Users
    ArrayOfUserValue users(4);

    {   
        // initialize single User struct value
        UserValue user;
        user.name("guest");
        user.role(UserRole_Guest);
        
        // set at position 0 in array
        users.at(0, user);
    }

    {   
        UserValue user;
        user.name("member1");
        user.role(UserRole_Member);
        users.at(1, user);
    }

    {   
        UserValue user;
        user.name("member2");
        user.role(UserRole_Member);
        users.at(2, user);
    }

    {   
        UserValue user;
        user.name("admin");
        user.role(UserRole_Guest);
        users.at(3, user);
    }

    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_USERS, users);    
}

void tick_vars() {
    // nothing here, you can add some code here to watch var changes
}

extern const char *get_var_greeting_str() {
    // get "users" variable
    ArrayOfUserValue users = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_USERS);

    // get "selected_user_index" variable
    int selected_user_index = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SELECTED_USER_INDEX).getInt();

    // get user name at position "selected_user_index"
    const char *user_name = users.at(selected_user_index).name();

    // return greeting message
    static char user_info[256];
    snprintf(user_info, sizeof(user_info), "Hello, %s!", user_name);
    return user_info;    
}

extern void set_var_greeting_str(const char *value) {
    // not implement, user_info is read only
}

int32_t counter = 0;
int32_t selected_item_index = 0;

int32_t get_var_selected_item_index() {
    return selected_item_index;
}

void set_var_selected_item_index(int32_t value) {
    selected_item_index = value;
}

const char *get_var_selected_item_info() {
    static char selected_item_info[256];
    snprintf(selected_item_info, sizeof(selected_item_info), "Selected item index is %d", selected_item_index);
    return selected_item_info;
}

extern void set_var_selected_item_info(const char *value) {
    // not implement, user_info is read only
}

const char *get_var_counter_info() {
    static char counter_info[256];
    snprintf(counter_info, sizeof(counter_info), "Counter is %d", counter);
    return counter_info;
}

extern void set_var_counter_info(const char *value) {
    // not implement, user_info is read only
}