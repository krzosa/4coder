api(custom) function b32 global_set_setting(Application_Links* app, Global_Setting_ID setting, i32 value);
api(custom) function b32 global_set_mapping(Application_Links* app, void* data, i32 size);
api(custom) function Rect_f32 global_get_screen_rectangle(Application_Links* app);
api(custom) function Thread_Context* get_thread_context(Application_Links* app);
api(custom) function b32 create_child_process(Application_Links* app, String_Const_u8 path, String_Const_u8 command, Child_Process_ID* child_process_id_out);
api(custom) function b32 child_process_set_target_buffer(Application_Links* app, Child_Process_ID child_process_id, Buffer_ID buffer_id, Child_Process_Set_Target_Flags flags);
api(custom) function Child_Process_ID buffer_get_attached_child_process(Application_Links* app, Buffer_ID buffer_id);
api(custom) function Buffer_ID child_process_get_attached_buffer(Application_Links* app, Child_Process_ID child_process_id);
api(custom) function Process_State child_process_get_state(Application_Links* app, Child_Process_ID child_process_id);
api(custom) function b32 clipboard_post(Application_Links* app, i32 clipboard_id, String_Const_u8 string);
api(custom) function i32 clipboard_count(Application_Links* app, i32 clipboard_id);
api(custom) function String_Const_u8 push_clipboard_index(Application_Links* app, Arena* arena, i32 clipboard_id, i32 item_index);
api(custom) function i32 get_buffer_count(Application_Links* app);
api(custom) function Buffer_ID get_buffer_next(Application_Links* app, Buffer_ID buffer_id, Access_Flag access);
api(custom) function Buffer_ID get_buffer_by_name(Application_Links* app, String_Const_u8 name, Access_Flag access);
api(custom) function Buffer_ID get_buffer_by_file_name(Application_Links* app, String_Const_u8 file_name, Access_Flag access);
api(custom) function b32 buffer_read_range(Application_Links* app, Buffer_ID buffer_id, Range_i64 range, char* out);
api(custom) function b32 buffer_replace_range(Application_Links* app, Buffer_ID buffer_id, Range_i64 range, String_Const_u8 string);
api(custom) function b32 buffer_batch_edit(Application_Links* app, Buffer_ID buffer_id, Batch_Edit* batch);
api(custom) function String_Match buffer_seek_string(Application_Links* app, Buffer_ID buffer, String_Const_u8 needle, Scan_Direction direction, i64 start_pos);
api(custom) function String_Match buffer_seek_character_class(Application_Links* app, Buffer_ID buffer, Character_Predicate* predicate, Scan_Direction direction, i64 start_pos);
api(custom) function f32 buffer_line_y_difference(Application_Links* app, Buffer_ID buffer_id, f32 width, Face_ID face_id, i64 line_a, i64 line_b);
api(custom) function Line_Shift_Vertical buffer_line_shift_y(Application_Links* app, Buffer_ID buffer_id, f32 width, Face_ID face_id, i64 line, f32 y_shift);
api(custom) function i64 buffer_pos_at_relative_xy(Application_Links* app, Buffer_ID buffer_id, f32 width, Face_ID face_id, i64 base_line, Vec2_f32 relative_xy);
api(custom) function Vec2_f32 buffer_relative_xy_of_pos(Application_Links* app, Buffer_ID buffer_id, f32 width, Face_ID face_id, i64 base_line, i64 pos);
api(custom) function i64 buffer_relative_character_from_pos(Application_Links* app, Buffer_ID buffer_id, f32 width, Face_ID face_id, i64 base_line, i64 pos);
api(custom) function i64 buffer_pos_from_relative_character(Application_Links* app, Buffer_ID buffer_id, f32 width, Face_ID face_id, i64 base_line, i64 relative_character);
api(custom) function f32 view_line_y_difference(Application_Links* app, View_ID view_id, i64 line_a, i64 line_b);
api(custom) function Line_Shift_Vertical view_line_shift_y(Application_Links* app, View_ID view_id, i64 line, f32 y_shift);
api(custom) function i64 view_pos_at_relative_xy(Application_Links* app, View_ID view_id, i64 base_line, Vec2_f32 relative_xy);
api(custom) function Vec2_f32 view_relative_xy_of_pos(Application_Links* app, View_ID view_id, i64 base_line, i64 pos);
api(custom) function i64 view_relative_character_from_pos(Application_Links* app, View_ID view_id, i64 base_line, i64 pos);
api(custom) function i64 view_pos_from_relative_character(Application_Links* app, View_ID view_id, i64 base_line, i64 character);
api(custom) function b32 buffer_exists(Application_Links* app, Buffer_ID buffer_id);
api(custom) function b32 buffer_ready(Application_Links* app, Buffer_ID buffer_id);
api(custom) function Access_Flag buffer_get_access_flags(Application_Links* app, Buffer_ID buffer_id);
api(custom) function i64 buffer_get_size(Application_Links* app, Buffer_ID buffer_id);
api(custom) function i64 buffer_get_line_count(Application_Links* app, Buffer_ID buffer_id);
api(custom) function String_Const_u8 push_buffer_base_name(Application_Links* app, Arena* arena, Buffer_ID buffer_id);
api(custom) function String_Const_u8 push_buffer_unique_name(Application_Links* app, Arena* out, Buffer_ID buffer_id);
api(custom) function String_Const_u8 push_buffer_file_name(Application_Links* app, Arena* arena, Buffer_ID buffer_id);
api(custom) function Dirty_State buffer_get_dirty_state(Application_Links* app, Buffer_ID buffer_id);
api(custom) function b32 buffer_set_dirty_state(Application_Links* app, Buffer_ID buffer_id, Dirty_State dirty_state);
api(custom) function b32 buffer_get_setting(Application_Links* app, Buffer_ID buffer_id, Buffer_Setting_ID setting, i32* value_out);
api(custom) function b32 buffer_set_setting(Application_Links* app, Buffer_ID buffer_id, Buffer_Setting_ID setting, i32 value);
api(custom) function Managed_Scope buffer_get_managed_scope(Application_Links* app, Buffer_ID buffer_id);
api(custom) function b32 buffer_send_end_signal(Application_Links* app, Buffer_ID buffer_id);
api(custom) function Buffer_ID create_buffer(Application_Links* app, String_Const_u8 file_name, Buffer_Create_Flag flags);
api(custom) function b32 buffer_save(Application_Links* app, Buffer_ID buffer_id, String_Const_u8 file_name, Buffer_Save_Flag flags);
api(custom) function Buffer_Kill_Result buffer_kill(Application_Links* app, Buffer_ID buffer_id, Buffer_Kill_Flag flags);
api(custom) function Buffer_Reopen_Result buffer_reopen(Application_Links* app, Buffer_ID buffer_id, Buffer_Reopen_Flag flags);
api(custom) function File_Attributes buffer_get_file_attributes(Application_Links* app, Buffer_ID buffer_id);
api(custom) function File_Attributes get_file_attributes(Application_Links* app, String_Const_u8 file_name);
api(custom) function View_ID get_view_next(Application_Links* app, View_ID view_id, Access_Flag access);
api(custom) function View_ID get_view_prev(Application_Links* app, View_ID view_id, Access_Flag access);
api(custom) function View_ID get_active_view(Application_Links* app, Access_Flag access);
api(custom) function Panel_ID get_active_panel(Application_Links* app);
api(custom) function b32 view_exists(Application_Links* app, View_ID view_id);
api(custom) function Buffer_ID view_get_buffer(Application_Links* app, View_ID view_id, Access_Flag access);
api(custom) function i64 view_get_cursor_pos(Application_Links* app, View_ID view_id);
api(custom) function i64 view_get_mark_pos(Application_Links* app, View_ID view_id);
api(custom) function f32 view_get_preferred_x(Application_Links* app, View_ID view_id);
api(custom) function b32 view_set_preferred_x(Application_Links* app, View_ID view_id, f32 x);
api(custom) function Rect_f32 view_get_screen_rect(Application_Links* app, View_ID view_id);
api(custom) function Panel_ID view_get_panel(Application_Links* app, View_ID view_id);
api(custom) function View_ID panel_get_view(Application_Links* app, Panel_ID panel_id);
api(custom) function b32 panel_is_split(Application_Links* app, Panel_ID panel_id);
api(custom) function b32 panel_is_leaf(Application_Links* app, Panel_ID panel_id);
api(custom) function b32 panel_split(Application_Links* app, Panel_ID panel_id, Panel_Split_Orientation orientation);
api(custom) function b32 panel_set_split(Application_Links* app, Panel_ID panel_id, Panel_Split_Kind kind, float t);
api(custom) function b32 panel_swap_children(Application_Links* app, Panel_ID panel_id, Panel_Split_Kind kind, float t);
api(custom) function Panel_ID panel_get_parent(Application_Links* app, Panel_ID panel_id);
api(custom) function Panel_ID panel_get_child(Application_Links* app, Panel_ID panel_id, Panel_Child which_child);
api(custom) function Panel_ID panel_get_max(Application_Links* app, Panel_ID panel_id);
api(custom) function Rect_i32 panel_get_margin(Application_Links* app, Panel_ID panel_id);
api(custom) function b32 view_close(Application_Links* app, View_ID view_id);
api(custom) function Rect_f32 view_get_buffer_region(Application_Links* app, View_ID view_id);
api(custom) function Buffer_Scroll view_get_buffer_scroll(Application_Links* app, View_ID view_id);
api(custom) function Basic_Scroll view_get_basic_scroll(Application_Links* app, View_ID view_id);
api(custom) function b32 view_set_active(Application_Links* app, View_ID view_id);
api(custom) function b32 view_get_setting(Application_Links* app, View_ID view_id, View_Setting_ID setting, i32* value_out);
api(custom) function b32 view_set_setting(Application_Links* app, View_ID view_id, View_Setting_ID setting, i32 value);
api(custom) function Managed_Scope view_get_managed_scope(Application_Links* app, View_ID view_id);
api(custom) function Buffer_Cursor buffer_compute_cursor(Application_Links* app, Buffer_ID buffer, Buffer_Seek seek);
api(custom) function Buffer_Cursor view_compute_cursor(Application_Links* app, View_ID view_id, Buffer_Seek seek);
api(custom) function b32 view_set_cursor(Application_Links* app, View_ID view_id, Buffer_Seek seek);
api(custom) function b32 view_set_buffer_scroll(Application_Links* app, View_ID view_id, Buffer_Scroll scroll);
api(custom) function b32 view_set_basic_scroll(Application_Links* app, View_ID view_id, Basic_Scroll scroll);
api(custom) function b32 view_set_mark(Application_Links* app, View_ID view_id, Buffer_Seek seek);
api(custom) function b32 view_set_buffer(Application_Links* app, View_ID view_id, Buffer_ID buffer_id, Set_Buffer_Flag flags);
api(custom) function b32 view_post_fade(Application_Links* app, View_ID view_id, f32 seconds, Range_i64 range, int_color color);
api(custom) function b32 view_begin_ui_mode(Application_Links* app, View_ID view_id);
api(custom) function b32 view_end_ui_mode(Application_Links* app, View_ID view_id);
api(custom) function b32 view_is_in_ui_mode(Application_Links* app, View_ID view_id);
api(custom) function b32 view_set_quit_ui_handler(Application_Links* app, View_ID view_id, UI_Quit_Function_Type* quit_function);
api(custom) function b32 view_get_quit_ui_handler(Application_Links* app, View_ID view_id, UI_Quit_Function_Type** quit_function_out);
api(custom) function Managed_Scope create_user_managed_scope(Application_Links* app);
api(custom) function b32 destroy_user_managed_scope(Application_Links* app, Managed_Scope scope);
api(custom) function Managed_Scope get_global_managed_scope(Application_Links* app);
api(custom) function Managed_Scope get_managed_scope_with_multiple_dependencies(Application_Links* app, Managed_Scope* scopes, i32 count);
api(custom) function b32 managed_scope_clear_contents(Application_Links* app, Managed_Scope scope);
api(custom) function b32 managed_scope_clear_self_all_dependent_scopes(Application_Links* app, Managed_Scope scope);
api(custom) function Base_Allocator* managed_scope_allocator(Application_Links* app, Managed_Scope scope);
api(custom) function Managed_ID managed_id_declare(Application_Links* app, String_Const_u8 name);
api(custom) function void* managed_scope_get_attachment(Application_Links* app, Managed_Scope scope, Managed_ID id, umem size);
api(custom) function void* managed_scope_attachment_erase(Application_Links* app, Managed_Scope scope, Managed_ID id);
api(custom) function Managed_Object alloc_managed_memory_in_scope(Application_Links* app, Managed_Scope scope, i32 item_size, i32 count);
api(custom) function Managed_Object alloc_buffer_markers_on_buffer(Application_Links* app, Buffer_ID buffer_id, i32 count, Managed_Scope* optional_extra_scope);
api(custom) function u32 managed_object_get_item_size(Application_Links* app, Managed_Object object);
api(custom) function u32 managed_object_get_item_count(Application_Links* app, Managed_Object object);
api(custom) function void* managed_object_get_pointer(Application_Links* app, Managed_Object object);
api(custom) function Managed_Object_Type managed_object_get_type(Application_Links* app, Managed_Object object);
api(custom) function Managed_Scope managed_object_get_containing_scope(Application_Links* app, Managed_Object object);
api(custom) function b32 managed_object_free(Application_Links* app, Managed_Object object);
api(custom) function b32 managed_object_store_data(Application_Links* app, Managed_Object object, u32 first_index, u32 count, void* mem);
api(custom) function b32 managed_object_load_data(Application_Links* app, Managed_Object object, u32 first_index, u32 count, void* mem_out);
api(custom) function User_Input get_user_input(Application_Links* app, Input_Type_Flag get_type, Input_Type_Flag abort_type);
api(custom) function User_Input get_command_input(Application_Links* app);
api(custom) function void set_command_input(Application_Links* app, Key_Event_Data key_data);
api(custom) function Mouse_State get_mouse_state(Application_Links* app);
api(custom) function b32 get_active_query_bars(Application_Links* app, View_ID view_id, i32 max_result_count, Query_Bar_Ptr_Array* array_out);
api(custom) function b32 start_query_bar(Application_Links* app, Query_Bar* bar, u32 flags);
api(custom) function void end_query_bar(Application_Links* app, Query_Bar* bar, u32 flags);
api(custom) function b32 print_message(Application_Links* app, String_Const_u8 message);
api(custom) function b32 log_string(Application_Links* app, String_Const_u8 str);
api(custom) function i32 thread_get_id(Application_Links* app);
api(custom) function Face_ID get_largest_face_id(Application_Links* app);
api(custom) function b32 set_global_face(Application_Links* app, Face_ID id, b32 apply_to_all_buffers);
api(custom) function History_Record_Index buffer_history_get_max_record_index(Application_Links* app, Buffer_ID buffer_id);
api(custom) function Record_Info buffer_history_get_record_info(Application_Links* app, Buffer_ID buffer_id, History_Record_Index index);
api(custom) function Record_Info buffer_history_get_group_sub_record(Application_Links* app, Buffer_ID buffer_id, History_Record_Index index, i32 sub_index);
api(custom) function History_Record_Index buffer_history_get_current_state_index(Application_Links* app, Buffer_ID buffer_id);
api(custom) function b32 buffer_history_set_current_state_index(Application_Links* app, Buffer_ID buffer_id, History_Record_Index index);
api(custom) function b32 buffer_history_merge_record_range(Application_Links* app, Buffer_ID buffer_id, History_Record_Index first_index, History_Record_Index last_index, Record_Merge_Flag flags);
api(custom) function b32 buffer_history_clear_after_current_state(Application_Links* app, Buffer_ID buffer_id);
api(custom) function void global_history_edit_group_begin(Application_Links* app);
api(custom) function void global_history_edit_group_end(Application_Links* app);
api(custom) function b32 buffer_set_face(Application_Links* app, Buffer_ID buffer_id, Face_ID id);
api(custom) function Face_Description get_face_description(Application_Links* app, Face_ID face_id);
api(custom) function Face_Metrics get_face_metrics(Application_Links* app, Face_ID face_id);
api(custom) function Face_ID get_face_id(Application_Links* app, Buffer_ID buffer_id);
api(custom) function Face_ID try_create_new_face(Application_Links* app, Face_Description* description);
api(custom) function b32 try_modify_face(Application_Links* app, Face_ID id, Face_Description* description);
api(custom) function b32 try_release_face(Application_Links* app, Face_ID id, Face_ID replacement_id);
api(custom) function void set_theme_colors(Application_Links* app, Theme_Color* colors, i32 count);
api(custom) function void get_theme_colors(Application_Links* app, Theme_Color* colors, i32 count);
api(custom) function argb_color finalize_color(Application_Links* app, int_color color);
api(custom) function String_Const_u8 push_hot_directory(Application_Links* app, Arena* arena);
api(custom) function b32 set_hot_directory(Application_Links* app, String_Const_u8 string);
api(custom) function File_List get_file_list(Application_Links* app, Arena* arena, String_Const_u8 directory);
api(custom) function void set_gui_up_down_keys(Application_Links* app, Key_Code up_key, Key_Modifier up_key_modifier, Key_Code down_key, Key_Modifier down_key_modifier);
api(custom) function void* memory_allocate(Application_Links* app, i32 size);
api(custom) function b32 memory_set_protection(Application_Links* app, void* ptr, i32 size, Memory_Protect_Flags flags);
api(custom) function void memory_free(Application_Links* app, void* ptr, i32 size);
api(custom) function String_Const_u8 push_4ed_path(Application_Links* app, Arena* arena);
api(custom) function void show_mouse_cursor(Application_Links* app, Mouse_Cursor_Show_Type show);
api(custom) function b32 set_edit_finished_hook_repeat_speed(Application_Links* app, u32 milliseconds);
api(custom) function b32 set_fullscreen(Application_Links* app, b32 full_screen);
api(custom) function b32 is_fullscreen(Application_Links* app);
api(custom) function void send_exit_signal(Application_Links* app);
api(custom) function b32 set_window_title(Application_Links* app, String_Const_u8 title);
api(custom) function Microsecond_Time_Stamp get_microseconds_timestamp(Application_Links* app);
api(custom) function Vec2 draw_string_oriented(Application_Links* app, Face_ID font_id, String_Const_u8 str, Vec2 point, int_color color, u32 flags, Vec2 delta);
api(custom) function f32 get_string_advance(Application_Links* app, Face_ID font_id, String_Const_u8 str);
api(custom) function void draw_rectangle(Application_Links* app, Rect_f32 rect, int_color color);
api(custom) function void draw_rectangle_outline(Application_Links* app, Rect_f32 rect, int_color color);
api(custom) function void draw_clip_push(Application_Links* app, Rect_f32 clip_box);
api(custom) function f32_Rect draw_clip_pop(Application_Links* app);
api(custom) function void draw_coordinate_center_push(Application_Links* app, Vec2 point);
api(custom) function Vec2 draw_coordinate_center_pop(Application_Links* app);
api(custom) function Text_Layout_ID text_layout_create(Application_Links* app, Buffer_ID buffer_id, Rect_f32 rect, Buffer_Point buffer_point);
api(custom) function b32 text_layout_get_buffer(Application_Links* app, Text_Layout_ID text_layout_id, Buffer_ID* buffer_id_out);
api(custom) function Interval_i64 text_layout_get_visible_range(Application_Links* app, Text_Layout_ID text_layout_id);
api(custom) function Rect_f32 text_layout_line_on_screen(Application_Links* app, Text_Layout_ID layout_id, i64 line_number);
api(custom) function Rect_f32 text_layout_character_on_screen(Application_Links* app, Text_Layout_ID layout_id, i64 pos);
api(custom) function void paint_text_color(Application_Links* app, Text_Layout_ID layout_id, Interval_i64 range, int_color color);
api(custom) function b32 text_layout_free(Application_Links* app, Text_Layout_ID text_layout_id);
api(custom) function void draw_text_layout(Application_Links* app, Text_Layout_ID layout_id);
api(custom) function void open_color_picker(Application_Links* app, Color_Picker* picker);
api(custom) function void animate_in_n_milliseconds(Application_Links* app, u32 n);
api(custom) function String_Match_List buffer_find_all_matches(Application_Links* app, Arena* arena, Buffer_ID buffer, i32 string_id, Range_i64 range, String_Const_u8 needle, Character_Predicate* predicate, Scan_Direction direction);