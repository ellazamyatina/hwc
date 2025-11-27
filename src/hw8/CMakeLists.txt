add_library(binary binary.c)

add_executable(main main.c)

target_link_libraries(main PUBLIC binary)
