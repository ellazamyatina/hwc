add_library(sortList sortList.c)

add_executable(main main.c)

target_link_libraries(main PUBLIC sortList)