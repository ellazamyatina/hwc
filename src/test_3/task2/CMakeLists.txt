add_library(replaceByMin replaceByMin.c)

add_executable(main main.c)

target_link_libraries(main PUBLIC replaceByMin)