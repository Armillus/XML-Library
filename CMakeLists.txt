cmake_minimum_required(VERSION 3.12)
project(XML_Library C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(include/my_libxml)

add_executable(XML_Library
        include/my_libxml/my_lib_xml.h
        include/get_next_line.h
        include/libmy.h
        lib/get_next_line.c
        lib/my_clean_str.c
        lib/my_putchar.c
        lib/my_putstr.c
        lib/my_special_strdup.c
        lib/my_str_isnum.c
        lib/my_str_ncut.c
        lib/my_str_to_wordtab.c
        lib/my_strcmp.c
        lib/my_strdup.c
        lib/my_strerr.c
        lib/my_strlen.c
        lib/my_strncpy.c
        my_libxml/check_xml_structure.c
        my_libxml/get_xml_infos.c
        my_libxml/my_strerr.c
        my_libxml/parse_xml_file.c)
