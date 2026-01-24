#include "property_limiter.h"

void PropertyLimiter::set_valid_hints(int p_valid_hints) {
    valid_hints = p_valid_hints;
}

int PropertyLimiter::get_valid_hints() const {
    return valid_hints;
}

String PropertyLimiter::get_hints_enum_hint() const {
    return "To Do";
}

void PropertyLimiter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_valid_hints", "valid_hints"), &PropertyLimiter::set_valid_hints);
    ClassDB::bind_method(D_METHOD("get_valid_hints"), &PropertyLimiter::get_valid_hints);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_hints", PROPERTY_HINT_FLAGS, get_hints_flags_hint()), "set_valid_hints", "get_valid_hints");
}

String PropertyLimiter::get_hints_flags_hint() {
    PackedStringArray values;
    for(const String &value : get_hint_defs()) {
        values.push_back(value.get_slice(":", 0));
    }
    return String(",").join(values);
}

// See if I can use constant references here instead
PackedStringArray PropertyLimiter::get_hint_defs() {
    return {
        "None:0",
        "Range:1",
        "Enum:2",
        "Enum Suggestion:3",
        "Exp Easing:4",
        "Link:5",
        "Flags:6",
        "Layers 2D Render:7",
        "Layers 2D Physics:8",
        "Layers 2D Navigation:9",
        "Layers 3D Render:10",
        "Layers 3D Physics:11",
        "Layers 3D Navigation:12",
        "Layers Avoidance:37",
        "File:13",
        "Dir:14",
        "Global File:15",
        "Global Dir:16",
        "Resource Type:17",
        "Multiline Text:18",
        "Expression:19",
        "Placeholder Text:20",
        "Color No Alpha:21",
        "Object ID:22",
        "Type String:23",
        "Node Path to Edited Node:24",
        "Object Too Big:25",
        "Node Path Valid Types:26",
        "Save File:27",
        "Global Save File:28",
        "Int is ObjectID:29",
        "Int is Pointer:30",
        "Array Type:31",
        "Dictionary Type:38",
        "Locale ID:32",
        "Localizable String:33",
        "Node Type:34",
        "Hide Quaternion Edit:35",
        "Password:36",
        "Tool Button:39",
        "Oneshot:40",
        "Group Enable:42",
        "Input Name:43",
        "File Path:44",
    };
}