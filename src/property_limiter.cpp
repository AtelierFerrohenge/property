#include "property_limiter.h"

// Doesn't seem to update parent resources, figure out how to propagate up
void PropertyLimiter::set_valid_string_hints(int p_hints) {
    valid_string_hints = p_hints;
}

int PropertyLimiter::get_valid_string_hints() const {
    return valid_string_hints;
}

// Doesn't seem to update parent resources, figure out how to
void PropertyLimiter::set_valid_standalone_hints(int p_hints) {
    valid_standalone_hints = p_hints;
}

int PropertyLimiter::get_valid_standalone_hints() const {
    return valid_standalone_hints;
}

// Will want to reveal or hide hint string field in usage depending on which source has used flags
String PropertyLimiter::get_hints_enum_hint() const {
    // Use a reference if possible
    PackedStringArray values = get_string_hint_defs();
    PackedStringArray result = {"None:0"};
    // Guard against invalid values for valid_hints
    int flags = valid_string_hints;
    int index = 0;
    while(flags != 0) {
        int bit = 1 << index;
        if(flags & bit) {
            result.push_back(values[index]);
            flags &= ~bit;
        }
        ++index;
    }
    values = get_standalone_hint_defs();
    flags = valid_standalone_hints;
    index = 0;
    while(flags != 0) {
        int bit = 1 << index;
        if(flags & bit) {
            result.push_back(values[index]);
            flags &= ~bit;
        }
        ++index;
    }
    return String(",").join(result);
}

void PropertyLimiter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_valid_string_hints", "hints"), &PropertyLimiter::set_valid_string_hints);
    ClassDB::bind_method(D_METHOD("get_valid_string_hints"), &PropertyLimiter::get_valid_string_hints);
    ClassDB::bind_method(D_METHOD("set_valid_standalone_hints", "hints"), &PropertyLimiter::set_valid_standalone_hints);
    ClassDB::bind_method(D_METHOD("get_valid_standalone_hints"), &PropertyLimiter::get_valid_standalone_hints);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_string_hints", PROPERTY_HINT_FLAGS, get_flags_hint(get_string_hint_defs())), "set_valid_string_hints", "get_valid_string_hints");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_standalone_hints", PROPERTY_HINT_FLAGS, get_flags_hint(get_standalone_hint_defs())), "set_valid_standalone_hints", "get_valid_standalone_hints");
}

// Probably use reference here
String PropertyLimiter::get_flags_hint(PackedStringArray defs) {
    PackedStringArray values;
    for(const String &value : defs) {
        values.push_back(value.get_slice(":", 0));
    }
    return String(",").join(values);
}

// See if I can use constant references here instead
PackedStringArray PropertyLimiter::get_string_hint_defs() {
    return {
        "Range:1",
        "Enum:2",
        "Enum Suggestion:3",
        "Exp Easing:4",
        "Flags:6",
        "File:13",
        "Global File:15",
        "Resource Type:17",
        // Can be "monospace" or "no_wrap" in latest
        "Multiline Text:18",
        "Placeholder Text:20",
        "Object ID:22",
        "Type String:23",
        "Node Path Valid Types:26",
        "Save File:27",
        "Global Save File:28",
        "Array Type:31",
        "Dictionary Type:38",
        "Node Type:34",
        "Tool Button:39",
        "Group Enable:42",
        "Input Name:43",
        "File Path:44",
    };
}

// See if I can use constant references here instead
PackedStringArray PropertyLimiter::get_standalone_hint_defs() {
    return {
        "Link:5",
        "Layers 2D Render:7",
        "Layers 2D Physics:8",
        "Layers 2D Navigation:9",
        "Layers 3D Render:10",
        "Layers 3D Physics:11",
        "Layers 3D Navigation:12",
        "Layers Avoidance:37",
        "Dir:14",
        "Global Dir:16",
        "Expression:19",
        "Color No Alpha:21",
        "Object Too Big:25",
        "Int is Pointer:30",
        "Locale ID:32",
        "Localizable String:33",
        "Hide Quaternion Edit:35",
        "Password:36",
        "Oneshot:40",
    };
}