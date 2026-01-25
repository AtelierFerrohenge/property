#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class PropertyLimiter : public Resource {
    GDCLASS(PropertyLimiter, Resource)

public:
    PropertyLimiter() = default;
    ~PropertyLimiter() override = default;

    void set_valid_value_types(int p_types);
    int get_valid_value_types() const;
    void set_valid_container_types(int p_types);
    int get_valid_container_types() const;

    void set_valid_string_hints(int p_hints);
    int get_valid_string_hints() const;
    void set_valid_standalone_hints(int p_hints);
    int get_valid_standalone_hints() const;

    void set_valid_usages(int p_usages);
    int get_valid_usages() const;

    String get_types_enum_hint() const;
    String get_hints_enum_hint() const;
    String get_usages_flags_hint() const;

protected:
    static void _bind_methods();

private:
    int valid_value_types;
    int valid_container_types;
    int valid_string_hints;
    int valid_standalone_hints;
    int valid_usages;

    static String get_flags_hint(PackedStringArray defs);

    static PackedStringArray get_value_type_defs();
    static PackedStringArray get_container_type_defs();
    static PackedStringArray get_string_hint_defs();
    static PackedStringArray get_standalone_hint_defs();
    static PackedStringArray get_usage_defs();
};