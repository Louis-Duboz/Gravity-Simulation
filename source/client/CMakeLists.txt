add_executable(Client WIN32 "source/main.cpp" "source/pch.cpp")

target_precompile_headers(Client PRIVATE "include/pch.h")

if(WIN32)
  set_target_properties(Client PROPERTIES
    WIN32_EXECUTABLE TRUE
  )
endif()

target_include_directories(Client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Client PUBLIC ${SDL3_INCLUDE_DIRS})

cmake_policy(SET CMP0079 NEW)
target_link_libraries(Client PRIVATE SDL3::SDL3)
target_link_libraries(Client PRIVATE flecs::flecs_static)

add_custom_command(
  TARGET Client POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:SDL3::SDL3>
      $<TARGET_FILE_DIR:Client>
  VERBATIM
)