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

TypedArray<String> PropertyDef::get_valid_types() const {
    TypedArray<String> ret;
    if(GDVIRTUAL_CALL(_get_valid_types, ret)) {
        return ret;
    }
    ret.push_back("Nil:0");
    return ret;
}

TypedArray<String> PropertyDef::get_valid_hints() const {
    TypedArray<String> ret;
    if(GDVIRTUAL_CALL(_get_valid_hints, ret)) {
        return ret;
    }
    ret.push_back("None:0");
    return ret;
}

void PropertyDef::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_name", "name"), &PropertyDef::set_name);
    ClassDB::bind_method(D_METHOD("get_name"), &PropertyDef::get_name);
    ClassDB::bind_method(D_METHOD("set_class_name", "class_name"), &PropertyDef::set_class_name);
    ClassDB::bind_method(D_METHOD("get_class_name"), &PropertyDef::get_class_name);
    ClassDB::bind_method(D_METHOD("set_hint_string", "hint_string"), &PropertyDef::set_hint_string);
    ClassDB::bind_method(D_METHOD("get_hint_string"), &PropertyDef::get_hint_string);
    ClassDB::bind_method(D_METHOD("set_usage", "usage"), &PropertyDef::set_usage);
    ClassDB::bind_method(D_METHOD("get_usage"), &PropertyDef::get_usage);

    GDVIRTUAL_BIND(_get_valid_types);
    GDVIRTUAL_BIND(_get_valid_hints);

    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "name"), "set_name", "get_name");
    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "class_name"), "set_class_name", "get_class_name");
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "hint_string"), "set_hint_string", "get_hint_string");
    // Determine if I can remove duplicates too
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "usage", PROPERTY_HINT_ARRAY_TYPE, vformat("%s/%s:%s", Variant::INT, PROPERTY_HINT_ENUM, "To,Do,Later")), "set_usage", "get_usage");
}

bool PropertyDef::_set(const StringName &p_name, const Variant &p_value) {
    // Potentially turn this into a switch
    if(p_name == StringName("type")) {
        set_type(static_cast<Variant::Type>(static_cast<int>(p_value)));
    } else if(p_name == StringName("hint")) {
        set_hint(static_cast<PropertyHint>(static_cast<int>(p_value)));
    } else {
        return false;
    }
    return true;
}

bool PropertyDef::_get(const StringName &p_name, Variant &r_ret) const {
    if(p_name == StringName("type")) {
        r_ret = get_type();
    } else if(p_name == StringName("hint")) {
        r_ret = get_hint();
    } else {
        return false;
    }
    return true;
}

void PropertyDef::_get_property_list(List<PropertyInfo> *p_list) const {
    // Review if a bunch of push_backs is the right way to do this
    p_list->push_back(PropertyInfo(Variant::INT, "type", PROPERTY_HINT_ENUM, get_enum_hint(get_valid_types())));
    p_list->push_back(PropertyInfo(Variant::INT, "hint", PROPERTY_HINT_ENUM, get_enum_hint(get_valid_hints())));
}

String PropertyDef::get_enum_hint(TypedArray<String> options) const {
    return String(",").join(options);
}