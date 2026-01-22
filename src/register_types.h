// Figure out why the template uses ifndef instead of pragma once
#ifndef EXAMPLE_REGISTER_TYPES_H
#define EXAMPLE_REGISTER_TYPES_H

// Figure out why the template has #include <godot_cpp/core/class_db.hpp> in the .cpp file instead
// Figure out why the template is missing using namespace godot here

void initialize_gdextension_types();
void uninitialize_gdextension_types();

#endif