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
};