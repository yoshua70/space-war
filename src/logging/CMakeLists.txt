set(HEADER_LIST "${SpaceWar_SOURCE_DIR}/include/logging/Logger.hpp")

add_library(logging Logger.cpp ${HEADER_LIST})

target_include_directories(logging PUBLIC ../../include/)
target_compile_features(logging PUBLIC cxx_std_17)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
