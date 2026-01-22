#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class PropertyDef : public Resource {
    GDCLASS(PropertyDef, Resource)

public:
    PropertyDef() = default;
    ~PropertyDef() override = default;

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