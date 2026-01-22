#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class PropertyDef : public Resource {
    GDCLASS(PropertyDef, Resource)

public:
    PropertyDef() = default;
    ~PropertyDef() override = default;

    // Review if this should be a reference
    void set_name(StringName p_name);
    StringName get_name() const;
    void set_class_name(StringName p_class_name);
    StringName get_class_name() const;
    void set_type(Variant::Type p_type);
    Variant::Type get_type() const;
    void set_hint(PropertyHint p_hint);
    PropertyHint get_hint() const;
    void set_hint_string(String p_hint_string);
    String get_hint_string() const;
    // Review if this should be a reference
    void set_usage(TypedArray<PropertyUsageFlags> p_usage);
    TypedArray<PropertyUsageFlags> get_usage() const;

protected:
    static void _bind_methods();

private:
    StringName name;
    StringName class_name;
    Variant::Type type;
    PropertyHint hint;
    String hint_string;
    // Review if this should be a type of Vector instead
    TypedArray<PropertyUsageFlags> usage;
};