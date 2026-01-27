#pragma once

#include "godot_cpp/classes/resource.hpp"

#include "property_def.h"

using namespace godot;

class PropertySet : public Resource {
    GDCLASS(PropertySet, Resource)

public:
    PropertySet() = default;
    ~PropertySet() override = default;

    void set_properties(const TypedArray<PropertyDef> &p_properties);
    TypedArray<PropertyDef> get_properties() const;

    bool custom_set(const StringName &p_name, const Variant &p_value);
    bool custom_get(const StringName &p_name, Variant &r_ret) const;
    void custom_get_property_list(List<PropertyInfo> *p_list) const;

protected:
    static void _bind_methods();

private:
    Vector<Ref<PropertyDef>> properties;
};