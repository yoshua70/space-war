set(HEADER_LIST "${SpaceWar_SOURCE_DIR}/include/game_lib/Game.hpp")

add_library(game_lib Game.cpp ${HEADER_LIST})

target_include_directories(game_lib PUBLIC ../../include/)
target_compile_features(game_lib PUBLIC cxx_std_17)
target_link_libraries(game_lib PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(game_lib PRIVATE logging)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
