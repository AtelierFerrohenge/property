#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class PropertySet : public Resource {
    GDCLASS(PropertySet, Resource)

public:
    PropertySet() = default;
    ~PropertySet() override = default;

protected:
    static void _bind_methods();
};