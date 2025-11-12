add_library(stack ${CMAKE_CURRENT_SOURCE_DIR}/stack.c)

add_executable(advancedBracketBalance advancedBracketBalance.c)

target_link_libraries(advancedBracketBalance PUBLIC stack)