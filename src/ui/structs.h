#ifndef EEZ_LVGL_UI_STRUCTS_H
#define EEZ_LVGL_UI_STRUCTS_H

#include <eez/flow/flow.h>
#include <stdint.h>
#include <stdbool.h>

#include "vars.h"

using namespace eez;

enum FlowStructures {
    FLOW_STRUCTURE_USER = 16384
};

enum FlowArrayOfStructures {
    FLOW_ARRAY_OF_STRUCTURE_USER = 81920
};

enum UserFlowStructureFields {
    FLOW_STRUCTURE_USER_FIELD_NAME = 0,
    FLOW_STRUCTURE_USER_FIELD_ROLE = 1,
    FLOW_STRUCTURE_USER_NUM_FIELDS
};

struct UserValue {
    Value value;
    
    UserValue() {
        value = Value::makeArrayRef(FLOW_STRUCTURE_USER_NUM_FIELDS, FLOW_STRUCTURE_USER, 0);
    }
    
    UserValue(Value value) : value(value) {}
    
    operator Value() const { return value; }
    
    operator bool() const { return value.isArray(); }
    
    const char *name() {
        return value.getArray()->values[FLOW_STRUCTURE_USER_FIELD_NAME].getString();
    }
    void name(const char *name) {
        value.getArray()->values[FLOW_STRUCTURE_USER_FIELD_NAME] = StringValue(name);
    }
    
    UserRole role() {
        return (UserRole)value.getArray()->values[FLOW_STRUCTURE_USER_FIELD_ROLE].getInt();
    }
    void role(UserRole role) {
        value.getArray()->values[FLOW_STRUCTURE_USER_FIELD_ROLE] = IntegerValue((int)role);
    }
};

typedef ArrayOf<UserValue, FLOW_ARRAY_OF_STRUCTURE_USER> ArrayOfUserValue;


#endif /*EEZ_LVGL_UI_STRUCTS_H*/
