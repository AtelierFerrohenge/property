#pragma once

#include "godot_cpp/classes/resource.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

class PropertyDef : public Resource {
    GDCLASS(PropertyDef, Resource)

public:
    PropertyDef() = default;
    ~PropertyDef() override = default;

    // Review if this should be a reference
    void set_name(StringName p_name);
    StringName get_name() const;
    void set_hint_string(String p_hint_string);
    String get_hint_string() const;

    void set_class_name(StringName p_class_name);
    StringName get_class_name() const;
    void set_type(Variant::Type p_type);
    Variant::Type get_type() const;
    void set_hint(PropertyHint p_hint);
    PropertyHint get_hint() const;
    // Review if this should be a reference
    void set_usage(TypedArray<int> p_usage);
    TypedArray<int> get_usage() const;

    // Maybe could be PackedStringArrays?
    virtual TypedArray<String> get_valid_class_names() const;
    virtual TypedArray<String> get_valid_types() const;
    virtual TypedArray<String> get_valid_hints() const;
    virtual TypedArray<String> get_valid_usage_flags() const;

protected:
    static void _bind_methods();

    bool _set(const StringName &p_name, const Variant &p_value);
    bool _get(const StringName &p_name, Variant &r_ret) const;
    void _get_property_list(List<PropertyInfo> *p_list) const;

    GDVIRTUAL0RC(TypedArray<String>, _get_valid_class_names)
    GDVIRTUAL0RC(TypedArray<String>, _get_valid_types)
    GDVIRTUAL0RC(TypedArray<String>, _get_valid_hints)
    GDVIRTUAL0RC(TypedArray<String>, _get_valid_usage_flags)

private:
    StringName name;
    StringName class_name;
    Variant::Type type = Variant::NIL;
    PropertyHint hint = PROPERTY_HINT_NONE;
    String hint_string;
    // Review if this should be a type of Vector instead
    TypedArray<int> usage = {PROPERTY_USAGE_DEFAULT};

    // Maybe should be static
    // Might need to take reference too
    String get_enum_hint(TypedArray<String> options) const;
};