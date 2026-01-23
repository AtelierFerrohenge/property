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

void PropertyDef::set_usage(TypedArray<int> p_usage) {
    usage = p_usage;
}

TypedArray<int> PropertyDef::get_usage() const {
    return usage;
}

void PropertyDef::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_name", "name"), &PropertyDef::set_name);
    ClassDB::bind_method(D_METHOD("get_name"), &PropertyDef::get_name);
    ClassDB::bind_method(D_METHOD("set_class_name", "class_name"), &PropertyDef::set_class_name);
    ClassDB::bind_method(D_METHOD("get_class_name"), &PropertyDef::get_class_name);
    ClassDB::bind_method(D_METHOD("set_type", "type"), &PropertyDef::set_type);
    ClassDB::bind_method(D_METHOD("get_type"), &PropertyDef::get_type);
    ClassDB::bind_method(D_METHOD("set_hint", "hint"), &PropertyDef::set_hint);
    ClassDB::bind_method(D_METHOD("get_hint"), &PropertyDef::get_hint);
    ClassDB::bind_method(D_METHOD("set_hint_string", "hint_string"), &PropertyDef::set_hint_string);
    ClassDB::bind_method(D_METHOD("get_hint_string"), &PropertyDef::get_hint_string);
    ClassDB::bind_method(D_METHOD("set_usage", "usage"), &PropertyDef::set_usage);
    ClassDB::bind_method(D_METHOD("get_usage"), &PropertyDef::get_usage);

    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "name"), "set_name", "get_name");
    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "class_name"), "set_class_name", "get_class_name");
    // Turn this into an enum with every member of Variant::Type, limited by a virtual method
    // May need _get_property_list, may not if I can find a way with statics
    ADD_PROPERTY(PropertyInfo(Variant::INT, "type"), "set_type", "get_type");
    // Same as above
    ADD_PROPERTY(PropertyInfo(Variant::INT, "hint"), "set_hint", "get_hint");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "hint_string"), "set_hint_string", "get_hint_string");
    // Determine if I can remove duplicates too
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "usage", PROPERTY_HINT_ARRAY_TYPE, vformat("%s/%s:%s", Variant::INT, PROPERTY_HINT_ENUM, "To,Do,Later")), "set_usage", "get_usage");
}