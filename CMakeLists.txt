cmake_minimum_required (VERSION 3.8)

project (gravity-simulation VERSION 0.0.1)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
	
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

# Install SDL 3
FETCHCONTENT_DECLARE(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG preview-3.1.3
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(SDL3)

# Install Flecs ECS
FETCHCONTENT_DECLARE(
  flecs
  GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
  GIT_TAG v4.0.2
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(flecs)

# Adding projects

add_subdirectory("source/client")
add_subdirectory("source/console")
add_subdirectory("source/physics-engine")

if (CMAKE_VERSION VERSION_GREATER 3.25)
  set_property(TARGET Client PROPERTY CXX_STANDARD 26)
  set_property(TARGET Console PROPERTY CXX_STANDARD 26)
  set_property(TARGET PhysicsEngine PROPERTY CXX_STANDARD 26)
endif()