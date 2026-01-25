#include "property_limiter.h"

// Doesn't seem to update parent resources, figure out how to propagate up
void PropertyLimiter::set_valid_value_types(int p_types) {
    valid_value_types = p_types;
}

int PropertyLimiter::get_valid_value_types() const {
    return valid_value_types;
}

// Doesn't seem to update parent resources, figure out how to
void PropertyLimiter::set_valid_container_types(int p_types) {
    valid_container_types = p_types;
}

int PropertyLimiter::get_valid_container_types() const {
    return valid_container_types;
}

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

// Doesn't seem to update parent resources, figure out how to
void PropertyLimiter::set_valid_usages(int p_usages) {
    valid_usages = p_usages;
}

int PropertyLimiter::get_valid_usages() const {
    return valid_usages;
}

// Clean this code later - definitely make a helper function
// Maybe bind too
String PropertyLimiter::get_types_enum_hint() const {
    // Use a reference if possible
    PackedStringArray values = get_value_type_defs();
    PackedStringArray result = {"null:0"};
    // Guard against invalid values for valid hints
    int flags = valid_value_types;
    int index = 0;
    while(flags != 0) {
        int bit = 1 << index;
        if(flags & bit) {
            result.push_back(values[index]);
            flags &= ~bit;
        }
        ++index;
    }
    values = get_container_type_defs();
    flags = valid_container_types;
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

// Clean this code later - definitely make a helper function
// Maybe bind too
// Will want to reveal or hide hint string field in usage depending on which source has used flags
String PropertyLimiter::get_hints_enum_hint() const {
    // Use a reference if possible
    PackedStringArray values = get_string_hint_defs();
    PackedStringArray result = {"None:0"};
    // Guard against invalid values for valid hints
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

// Clean this code later - definitely make a helper function
// Maybe bind too
String PropertyLimiter::get_usages_flags_hint() const {
    // Use a reference if possible
    PackedStringArray values = get_usage_defs();
    // Perhaps need defaults, like None and Default
    PackedStringArray result = {"None:0", "Default:6"};
    // Guard against invalid values for valid hints
    int flags = valid_usages;
    int index = 0;
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
    ClassDB::bind_method(D_METHOD("set_valid_value_types", "types"), &PropertyLimiter::set_valid_value_types);
    ClassDB::bind_method(D_METHOD("get_valid_value_types"), &PropertyLimiter::get_valid_value_types);
    ClassDB::bind_method(D_METHOD("set_valid_container_types", "types"), &PropertyLimiter::set_valid_container_types);
    ClassDB::bind_method(D_METHOD("get_valid_container_types"), &PropertyLimiter::get_valid_container_types);

    ClassDB::bind_method(D_METHOD("set_valid_string_hints", "hints"), &PropertyLimiter::set_valid_string_hints);
    ClassDB::bind_method(D_METHOD("get_valid_string_hints"), &PropertyLimiter::get_valid_string_hints);
    ClassDB::bind_method(D_METHOD("set_valid_standalone_hints", "hints"), &PropertyLimiter::set_valid_standalone_hints);
    ClassDB::bind_method(D_METHOD("get_valid_standalone_hints"), &PropertyLimiter::get_valid_standalone_hints);

    ClassDB::bind_method(D_METHOD("set_valid_usages", "usages"), &PropertyLimiter::set_valid_usages);
    ClassDB::bind_method(D_METHOD("get_valid_usages"), &PropertyLimiter::get_valid_usages);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_value_types", PROPERTY_HINT_FLAGS, get_flags_hint(get_value_type_defs())), "set_valid_value_types", "get_valid_value_types");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_container_types", PROPERTY_HINT_FLAGS, get_flags_hint(get_container_type_defs())), "set_valid_container_types", "get_valid_container_types");

    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_string_hints", PROPERTY_HINT_FLAGS, get_flags_hint(get_string_hint_defs())), "set_valid_string_hints", "get_valid_string_hints");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_standalone_hints", PROPERTY_HINT_FLAGS, get_flags_hint(get_standalone_hint_defs())), "set_valid_standalone_hints", "get_valid_standalone_hints");

    ADD_PROPERTY(PropertyInfo(Variant::INT, "valid_usages", PROPERTY_HINT_FLAGS, get_flags_hint(get_usage_defs())), "set_valid_usages", "get_valid_usages");
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
PackedStringArray PropertyLimiter::get_value_type_defs() {
    return {
        "bool:1",
        "int:2",
        "float:3",
        "String:4",
        "Vector2:5",
        "Vector2i:6",
        "Rect2:7",
        "Rect2i:8",
        "Vector3:9",
        "Vector3i:10",
        "Transform2D:11",
        "Vector4:12",
        "Vector4i:13",
        "Plane:14",
        "Quaternion:15",
        "AABB:16",
        "Basis:17",
        "Transform3D:18",
        "Projection:19",
        "Color:20",
        "StringName:21",
        "NodePath:22",
        "RID:23",
        "Object:24",
        "Callable:25",
        "Signal:26",
    };
}

// See if I can use constant references here instead
PackedStringArray PropertyLimiter::get_container_type_defs() {
    return {
        "Dictionary:27",
        "Array:28",
        "PackedByteArray:29",
        "PackedInt32Array:30",
        "PackedInt64Array:31",
        "PackedFloat32Array:32",
        "PackedFloat64Array:33",
        "PackedStringArray:34",
        "PackedVector2Array:35",
        "PackedVector3Array:36",
        "PackedColorArray:37",
        "PackedVector4Array:38",
    };
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
        "Int Is Pointer:30",
        "Locale ID:32",
        "Localizable String:33",
        "Hide Quaternion Edit:35",
        "Password:36",
        "Oneshot:40",
    };
}

// See if I can use constant references here instead
PackedStringArray PropertyLimiter::get_usage_defs() {
    return {
        "Storage:2",
        "Editor:4",
        "Internal:8",
        "Checkable:16",
        "Checked:32",
        "Group:64",
        "Category:128",
        "Subgroup:256",
        "Class Is Bitfield:512",
        "No Instance State:1024",
        "Restart If Changed:2048",
        "Script Variable:4096",
        "Store If Null:8192",
        "Update All If Modified:16384",
        "Class Is Enum:65536",
        "Nil Is Variant:131072",
        "Array:262144",
        "Always Duplicate:524288",
        "Never Duplicate:1048576",
        "High End GFX:2097152",
        "Node Path From Scene Root:4194304",
        "Resource Not Persistent:8388608",
        "Keying Increments:16777216",
        "Editor Instantiate Object:67108864",
        "Editor Basic Setting:134217728",
        "Read Only:268435456",
        "Secret:536870912",
        "No Editor:2",
    };
}