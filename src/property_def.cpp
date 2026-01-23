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
    // Limit to changes to and away from Variant::OBJECT
    notify_property_list_changed();
}

Variant::Type PropertyDef::get_type() const {
    return type;
}

void PropertyDef::set_hint(PropertyHint p_hint) {
    hint = p_hint;
    // Limit to changes to and away from PROPERTY_HINT_NONE and other stringless hints
    notify_property_list_changed();
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

Dictionary PropertyDef::get_dictionary() const {
    // Review if there's a way to do this with "{}"
    Dictionary result;
    result["name"] = name;
    result["class_name"] = class_name;
    result["type"] = type;
    result["hint"] = hint;
    result["hint_string"] = hint_string;
    // Review this
    int usage_value = 0;
    for(int flag : usage) {
        usage_value |= flag;
    }
    result["usage"] = usage_value;
    return result;
}

TypedArray<String> PropertyDef::get_valid_class_names() const {
    TypedArray<String> ret;
    GDVIRTUAL_CALL(_get_valid_class_names, ret);
    return ret;
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

TypedArray<String> PropertyDef::get_valid_usage_flags() const {
    TypedArray<String> ret;
    if(GDVIRTUAL_CALL(_get_valid_usage_flags, ret)) {
        return ret;
    }
    ret.push_back("None:0");
    ret.push_back("Default:6");
    return ret;
}

void PropertyDef::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_name", "name"), &PropertyDef::set_name);
    ClassDB::bind_method(D_METHOD("get_name"), &PropertyDef::get_name);

    ClassDB::bind_method(D_METHOD("get_dictionary"), &PropertyDef::get_dictionary);

    GDVIRTUAL_BIND(_get_valid_class_names);
    GDVIRTUAL_BIND(_get_valid_types);
    GDVIRTUAL_BIND(_get_valid_hints);
    GDVIRTUAL_BIND(_get_valid_usage_flags);

    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "name"), "set_name", "get_name");
}

bool PropertyDef::_set(const StringName &p_name, const Variant &p_value) {
    // Potentially turn this into a switch
    if(p_name == StringName("class_name")) {
        // Review if I should return false or not
        if(type != Variant::OBJECT) {
            return false;
        }
        set_class_name(p_value);
    } else if(p_name == StringName("type")) {
        set_type(static_cast<Variant::Type>(static_cast<int>(p_value)));
    } else if(p_name == StringName("hint")) {
        set_hint(static_cast<PropertyHint>(static_cast<int>(p_value)));
    } else if(p_name == StringName("hint_string")) {
        // Review if I should return false or not
        if(hint == PROPERTY_HINT_NONE) {
            return false;
        }
        set_hint_string(p_value);
    } else if(p_name == StringName("usage")) {
        set_usage(p_value);
    } else {
        return false;
    }
    return true;
}

bool PropertyDef::_get(const StringName &p_name, Variant &r_ret) const {
    // Potentially turn this into a switch
    if(p_name == StringName("class_name")) {
        // Review if I should return false or not
        if(type != Variant::OBJECT) {
            return false;
        }
        r_ret = get_class_name();
    } else if(p_name == StringName("type")) {
        r_ret = get_type();
    } else if(p_name == StringName("hint")) {
        r_ret = get_hint();
    } else if(p_name == StringName("hint_string")) {
        // Review if I should return false or not
        if(hint == PROPERTY_HINT_NONE) {
            return false;
        }
        r_ret = get_hint_string();
    } else if(p_name == StringName("usage")) {
        r_ret = get_usage();
    } else {
        return false;
    }
    return true;
}

void PropertyDef::_get_property_list(List<PropertyInfo> *p_list) const {
    // Review if a bunch of push_backs is the right way to do this
    if(type == Variant::OBJECT) {
        p_list->push_back(PropertyInfo(Variant::STRING_NAME, "class_name", PROPERTY_HINT_ENUM, get_enum_hint(get_valid_class_names())));
    }
    p_list->push_back(PropertyInfo(Variant::INT, "type", PROPERTY_HINT_ENUM, get_enum_hint(get_valid_types())));
    p_list->push_back(PropertyInfo(Variant::INT, "hint", PROPERTY_HINT_ENUM, get_enum_hint(get_valid_hints())));
    if(hint != PROPERTY_HINT_NONE) {
        p_list->push_back(PropertyInfo(Variant::STRING, "hint_string"));
    }
    // Determine if I can remove duplicates too
    p_list->push_back(PropertyInfo(Variant::ARRAY, "usage", PROPERTY_HINT_ARRAY_TYPE, vformat("%s/%s:%s", Variant::INT, PROPERTY_HINT_ENUM, get_enum_hint(get_valid_usage_flags()))));
}

String PropertyDef::get_enum_hint(TypedArray<String> options) const {
    return String(",").join(options);
}