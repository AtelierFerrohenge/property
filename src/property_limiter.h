#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class PropertyLimiter : public Resource {
    GDCLASS(PropertyLimiter, Resource)

public:
    PropertyLimiter() = default;
    ~PropertyLimiter() override = default;

    void set_valid_string_hints(int p_hints);
    int get_valid_string_hints() const;
    void set_valid_standalone_hints(int p_hints);
    int get_valid_standalone_hints() const;

    String get_hints_enum_hint() const;

protected:
    static void _bind_methods();

private:
    int valid_string_hints;
    int valid_standalone_hints;

    static String get_flags_hint(PackedStringArray defs);

    static PackedStringArray get_string_hint_defs();
    static PackedStringArray get_standalone_hint_defs();
};