add_library(queue_lib list.c queue.c)

add_executable(main main.c)

target_link_libraries(main PUBLIC queue_lib)
