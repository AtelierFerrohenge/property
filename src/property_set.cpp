#include "property_set.h"

void PropertySet::set_properties(const TypedArray<PropertyDef> &p_properties) {
    properties.clear();
    // Review if this needs type validation
    for(Variant property : p_properties) {
        properties.push_back(property);
    }
}

TypedArray<PropertyDef> PropertySet::get_properties() const {
    TypedArray<PropertyDef> result;
    for(Ref<PropertyDef> property : properties) {
        result.push_back(property);
    }
    return result;
}

void PropertySet::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_properties", "properties"), &PropertySet::set_properties);
    ClassDB::bind_method(D_METHOD("get_properties"), &PropertySet::get_properties);

    // Figure out if I can use MAKE_RESOURCE_TYPE_HINT
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "properties", PROPERTY_HINT_ARRAY_TYPE, "PropertyDef"), "set_properties", "get_properties");
}