cmake_minimum_required(VERSION 3.31.3)

project(
  SpaceWar
  VERSION 0.1
  LANGUAGES CXX
  DESCRIPTION "A Space War clone in C++")

# Your LSP might need this to locate header files and provide proper support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add Catch2 modules to assist in development
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Only do this if it is the main project, and not if it is included through
# `add_subdirectory`
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Add support for folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app.
  include(CTest)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

# For managing external dependencies
include(FetchContent)

# External dependencies. Each folder inside of this directory refers to an
# external dependency. External dependency directory shall contain only a single
# CMakeLists.txt file
add_subdirectory(deps)
# Source code for our own reusable libraries throughout the project
add_subdirectory(src)
# Source code for executables
add_subdirectory(apps)

# Testing is only available if this is the main app. Provides an emergency
# override GAME_ENGINE_BUILD_TESTING as well
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME
   OR GAME_ENGINE_BUILD_TESTING
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
