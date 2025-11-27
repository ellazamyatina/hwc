add_library(double double.c)

add_executable(main main.c)

target_link_libraries(main PUBLIC double)