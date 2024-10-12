add_executable(Console "source/main.cpp" "source/pch.cpp")

target_include_directories(Console PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(Console PUBLIC ${CORE_INCLUDE_DIRS})
target_precompile_headers(Console PRIVATE "include/pch.h")

cmake_policy(SET CMP0079 NEW)
target_link_libraries(Console PRIVATE flecs::flecs_static)
target_link_libraries(Console PRIVATE PhysicsEngine)