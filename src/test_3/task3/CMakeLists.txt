add_library(list list.c)

add_executable(main main.c)

target_link_libraries(main PUBLIC list)