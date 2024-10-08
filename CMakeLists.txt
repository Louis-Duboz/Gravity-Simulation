cmake_minimum_required (VERSION 3.8)

project (gravity-simulation VERSION 0.0.1)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
	
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

# Fetch SDL3 from the pre-release version 3.1.3-preview
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG preview-3.1.3  # This points to the pre-release version tag
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
  OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(SDL3)

add_subdirectory("client")
add_subdirectory("console")
add_subdirectory("physics-engine")

if (CMAKE_VERSION VERSION_GREATER 3.25)
  set_property(TARGET Client PROPERTY CXX_STANDARD 26)
  set_property(TARGET Console PROPERTY CXX_STANDARD 26)
  set_property(TARGET PhysicsEngine PROPERTY CXX_STANDARD 26)
endif()