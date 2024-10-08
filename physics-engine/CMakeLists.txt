add_library(PhysicsEngine STATIC src/main.cpp src/pch.cpp include/pch.h include/framework.h)
target_include_directories(PhysicsEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)