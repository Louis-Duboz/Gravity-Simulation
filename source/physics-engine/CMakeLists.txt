add_library(PhysicsEngine STATIC "source/pch.cpp" "source/Simulation.cpp" "source/Systems.cpp")

target_include_directories(PhysicsEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_precompile_headers(PhysicsEngine PRIVATE "include/pch.h")

cmake_policy(SET CMP0079 NEW)
target_link_libraries(PhysicsEngine PRIVATE flecs::flecs_static)

add_custom_command(
  TARGET PhysicsEngine POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:SDL3::SDL3>
      $<TARGET_FILE_DIR:PhysicsEngine>
  VERBATIM
)