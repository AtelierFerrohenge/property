#include "property_def.h"

void PropertyDef::set_name(StringName p_name) {
    name = p_name;
}

StringName PropertyDef::get_name() const {
    return name;
}

void PropertyDef::set_class_name(StringName p_class_name) {
    class_name = p_class_name;
}

StringName PropertyDef::get_class_name() const {
    return class_name;
}

void PropertyDef::set_type(Variant::Type p_type) {
    type = p_type;
}

Variant::Type PropertyDef::get_type() const {
    return type;
}

void PropertyDef::set_hint(PropertyHint p_hint) {
    hint = p_hint;
}

PropertyHint PropertyDef::get_hint() const {
    return hint;
}

void PropertyDef::set_hint_string(String p_hint_string) {
    hint_string = p_hint_string;
}

String PropertyDef::get_hint_string() const {
    return hint_string;
}

void PropertyDef::set_usage(TypedArray<PropertyUsageFlags> p_usage) {
    usage = p_usage;
}

TypedArray<PropertyUsageFlags> PropertyDef::get_usage() const {
    return usage;
}

void PropertyDef::_bind_methods() {
}