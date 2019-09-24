cmake_minimum_required(VERSION 3.14)
project(C_improve C)

set(CMAKE_C_STANDARD 99)

add_executable(find_stracks String_/find_tracks.c )
add_executable(reverse_strings String_/reverse_strings.c)
add_executable(fill_chars String_/fill_chars.c)
add_executable(GPS create_tools/GPS/geo2json.c)
add_executable(secret_message create_tools/secret_message_/secret_message.c)
add_executable(use_library create_tools/use_library_/use_library.c)
add_executable(test test.c)