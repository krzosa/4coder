/*
4coder_custom.cpp
*/

// TOP

export b32
get_version(i32 maj, i32 min, i32 patch){
    return(maj == MAJOR && min == MINOR && patch == PATCH);
}

export Custom_Layer_Init_Type*
init_apis(API_VTable_custom *custom_vtable, API_VTable_system *system_vtable){
    custom_api_read_vtable(custom_vtable);
    system_api_read_vtable(system_vtable);
    return(custom_layer_init);
}

// BOTTOM

