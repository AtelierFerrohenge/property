#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class PropertyLimiter : public Resource {
    GDCLASS(PropertyLimiter, Resource)

public:
    PropertyLimiter() = default;
    ~PropertyLimiter() override = default;

    void set_valid_hints(int p_valid_hints);
    int get_valid_hints() const;

protected:
    static void _bind_methods();

private:
    int valid_hints;

    static String get_hints_hint();
};