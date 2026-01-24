#include "property_limiter.h"

void PropertyLimiter::set_valid_hints(int p_valid_hints) {
    valid_hints = p_valid_hints;
}

int PropertyLimiter::get_valid_hints() const {
    return valid_hints;
}

void PropertyLimiter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_valid_hints", "valid_hints"), &PropertyLimiter::set_valid_hints);
    ClassDB::bind_method(D_METHOD("get_valid_hints"), &PropertyLimiter::get_valid_hints);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_hints", PROPERTY_HINT_FLAGS, get_hints_hint()), "set_valid_hints", "get_valid_hints");
}

String PropertyLimiter::get_hints_hint() {
    PackedStringArray values = {
        "None",
        "Range",
        "Enum",
        "Enum Suggestion",
        "Exp Easing",
        "Link",
        "Flags",
        "Layers 2D Render",
        "Layers 2D Physics",
        "Layers 2D Navigation",
        "Layers 3D Render",
        "Layers 3D Physics",
        "Layers 3D Navigation",
        "Layers Avoidance",
        "File",
        "Dir",
        "Global File",
        "Global Dir",
        "Resource Type",
        "Multiline Text",
        "Expression",
        "Placeholder Text",
        "Color No Alpha",
        "Object ID",
        "Type String",
        "Node Path to Edited Node",
        "Object Too Big",
        "Node Path Valid Types",
        "Save File",
        "Global Save File",
        "Int is ObjectID",
        "Int is Pointer",
        "Array Type",
        "Dictionary Type",
        "Locale ID",
        "Localizable String",
        "Node Type",
        "Hide Quaternion Edit",
        "Password",
        "Tool Button",
        "Oneshot",
        "Group Enable",
        "Input Name",
        "File Path",
    };
    return String(",").join(values);
}