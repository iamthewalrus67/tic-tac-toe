cmake_minimum_required(VERSION 3.21)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(tic_tac_toe main.cpp game_board/game_board.cpp game_board/game_board.h tic_tac_toe/tic_tac_toe.cpp tic_tac_toe/tic_tac_toe.h players/players.cpp players/players.h include/exit_codes.h)

find_package(fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)

target_include_directories(${PROJECT_NAME} PRIVATE game_board tic_tac_toe players include)