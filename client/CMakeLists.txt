add_executable (Client "src/main.cpp" "include/main.h")
target_include_directories(Client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

cmake_policy(SET CMP0079 NEW)
target_link_libraries(Client PRIVATE SDL3::SDL3)

add_custom_command(
  TARGET Client POST_BUILD COMMAND
  cmake -E copy_if_different
      $<TARGET_FILE:SDL3::SDL3>
      $<TARGET_FILE_DIR:Client>
  VERBATIM
)