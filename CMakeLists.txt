cmake_minimum_required(VERSION 3.21)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(tic_tac_toe main.cpp game_board/game_board.cpp game_board/game_board.h game_manager/game_manager.cpp game_manager/game_manager.h players/players.cpp players/players.h)

find_package(fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)

target_include_directories(${PROJECT_NAME} PRIVATE game_board game_manager players)