/*
 * Helpers for parsing jump location strings.
 */

// TOP

#if !defined(FCODER_JUMP_PARSING_H)
#define FCODER_JUMP_PARSING_H

#include "4coder_helper/4coder_helper.h"
#include "4coder_helper/4coder_long_seek.h"

#include "4coder_lib/4coder_mem.h"

struct ID_Pos_Jump_Location{
    Buffer_ID buffer_id;
    int32_t pos;
};

struct Name_Based_Jump_Location{
    String file;
    int32_t line;
    int32_t column;
};

static bool32
ms_style_verify(String line, int32_t left_paren_pos, int32_t right_paren_pos){
    int32_t result = false;
    String line_part = substr_tail(line, right_paren_pos);
    if (match_part_sc(line_part, ") : ")){
        result = true;
    }
    else if (match_part_sc(line_part, "): ")){
        result = true;
    }
    if (result){
        String number = substr(line, left_paren_pos, right_paren_pos - left_paren_pos);
        if (!str_is_int_s(number)){
            result = false;
        }
    }
    return(result);
}

static bool32
parse_jump_location(String line, Name_Based_Jump_Location *location, int32_t *colon_char, bool32 *is_sub_error){
    bool32 result = false;
    *is_sub_error = (line.str[0] == ' ');
    
    int32_t whitespace_length = 0;
    line = skip_chop_whitespace(line, &whitespace_length);
    
    int32_t colon_pos = 0;
    bool32 is_ms_style = false;
    
    int32_t left_paren_pos = find_s_char(line, 0, '(');
    int32_t right_paren_pos = find_s_char(line, left_paren_pos, ')');
    while (!is_ms_style && right_paren_pos < line.size){
        if (ms_style_verify(line, left_paren_pos, right_paren_pos)){
            is_ms_style = true;
            colon_pos = find_s_char(line, right_paren_pos, ':');
            if (colon_pos < line.size){
                String location_str = substr(line, 0, colon_pos);
                
                location_str = skip_chop_whitespace(location_str);
                
                int32_t close_pos = right_paren_pos;
                int32_t open_pos = left_paren_pos;
                
                if (0 < open_pos && open_pos < location_str.size){
                    String file = substr(location_str, 0, open_pos);
                    file = skip_chop_whitespace(file);
                    
                    if (file.size > 0){
                        String line_number = substr(location_str,
                                                    open_pos+1,
                                                    close_pos-open_pos-1);
                        line_number = skip_chop_whitespace(line_number);
                        
                        if (line_number.size > 0){
                            location->file = file;
                            
                            int32_t comma_pos = find_s_char(line_number, 0, ',');
                            if (comma_pos < line_number.size){
                                int32_t start = comma_pos+1;
                                String column_number = substr(line_number, start, line_number.size-start);
                                line_number = substr(line_number, 0, comma_pos);
                                
                                location->line = str_to_int_s(line_number);
                                location->column = str_to_int_s(column_number);
                            }
                            else{
                                location->line = str_to_int_s(line_number);
                                location->column = 1;
                            }
                            
                            *colon_char = colon_pos + whitespace_length;
                            result = true;
                        }
                    }
                }
            }
        }
        else{
            left_paren_pos = find_s_char(line, left_paren_pos + 1, '(');
            right_paren_pos = find_s_char(line, left_paren_pos, ')');
        }
    }
    
    if (!is_ms_style){
        int32_t colon_pos1 = find_s_char(line, 0, ':');
        if (line.size > colon_pos1+1){
            if (char_is_slash(line.str[colon_pos1+1])){
                colon_pos1 = find_s_char(line, colon_pos1+1, ':');
            }
        }
        
        int32_t colon_pos2 = find_s_char(line, colon_pos1+1, ':');
        int32_t colon_pos3 = find_s_char(line, colon_pos2+1, ':');
        
        if (colon_pos3+1 <= line.size){
            String filename = substr(line, 0, colon_pos1);
            String line_number = substr(line, colon_pos1+1, colon_pos2 - colon_pos1 - 1);
            String column_number = substr(line, colon_pos2+1, colon_pos3 - colon_pos2 - 1);
            
            if (filename.size > 0 &&
                line_number.size > 0 &&
                column_number.size > 0){
                location->file = filename;
                location->line = str_to_int_s(line_number);
                location->column = str_to_int_s(column_number);
                *colon_char = colon_pos3 + whitespace_length;
                result = true;
            }
        }
        else{
            if (colon_pos2+1 <= line.size){
                String filename = substr(line, 0, colon_pos1);
                String line_number = substr(line, colon_pos1+1, colon_pos2 - colon_pos1 - 1);
                
                if (str_is_int_s(line_number)){
                    if (filename.size > 0 && line_number.size > 0){
                        location->file = filename;
                        location->line = str_to_int_s(line_number);
                        location->column = 0;
                        *colon_char = colon_pos2 + whitespace_length;
                        result = true;
                    }
                }
            }
        }
    }
    
    if (!result){
        *is_sub_error = false;
    }
    
    return(result);
}

static bool32
parse_jump_location(String line, Name_Based_Jump_Location *location, bool32 skip_sub_error, int32_t *colon_char){
    bool32 is_sub_error = false;
    bool32 result = parse_jump_location(line, location, colon_char, &is_sub_error);
    if (is_sub_error && skip_sub_error){
        result = false;
    }
    return(result);
}

static int32_t
parse_jump_from_buffer_line(Application_Links *app, Partition *part, int32_t buffer_id, int32_t line, int32_t skip_sub_errors, Name_Based_Jump_Location *location){
    
    int32_t result = false;
    String line_str = {0};
    Buffer_Summary buffer = get_buffer(app, buffer_id, AccessAll);
    if (read_line(app, part, &buffer, line, &line_str)){
        int32_t colon_char = 0;
        if (parse_jump_location(line_str, location, skip_sub_errors, &colon_char)){
            result = true;
        }
    }
    
    return(result);
}

#endif

// BOTTOM

