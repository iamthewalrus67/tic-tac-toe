//
// Created by iamthewalrus on 3/12/22.
//

#include "game_manager.h"
#include <iostream>
#include "players.h"

void game_manager_t::game_loop() {
    int state;
    std::cout << board.to_string() << std::endl;

    human_player_t first_player;
    computer_random_player_t second_player;

    while ((state = check_state()) == PLAYING) {
        std::cout << "Your turn. Choose a cell on the grid." << std::endl;
        int cell_num = 0;
        while (!(1 <= cell_num && cell_num <= 9)) {
            if (current_player == FIRST_PLAYER) {
                cell_num = first_player.choose_cell(board);
            } else {
                cell_num = second_player.choose_cell(board);
            }

            if (!(1 <= cell_num && cell_num <= 9) || std::cin.fail()) {
                handle_error("Wrong input! The cell should be in range from 1 to 9.");
                continue;
            }

            if (!board.is_cell_free(cell_num)) {
                handle_error("This cell is already taken. Try again.");
                cell_num = 0;
                continue;
            }
        }

        board.set_cell(cell_num, current_player);

        if (current_player == FIRST_PLAYER) {
            current_player = SECOND_PLAYER;
        } else {
            current_player = FIRST_PLAYER;
        }

        std::cout << board.to_string() << std::endl;
    }

    if (state == FIRST_PLAYER_WON) {
        std::cout << "First player has won!" << std::endl;
    } else {
        std::cout << "Second player has won!" << std::endl;
    }
}

int game_manager_t::check_state() {
    if (board.is_full()) {
        return TIE;
    }

    // Check column
    for (int i = 0; i < 3; ++i) {
        int player = board.get_cell(i, 0);
        if (player == EMPTY) {
            continue;
        }

        for (int j = 1; j < 3; ++j) {
            if (player != board.get_cell(i, j)) {
                break;
            }

            if (j == 2) {
                if (player == FIRST_PLAYER) {
                    return FIRST_PLAYER_WON;
                } else {
                    return SECOND_PLAYER_WON;
                }
            }
        }
    }

    // Check row
    for (int i = 0; i < 3; ++i) {
        int player = board.get_cell(0, i);
        if (player == EMPTY) {
            continue;
        }

        for (int j = 1; j < 3; ++j) {
            if (player != board.get_cell(j, i)) {
                break;
            }

            if (j == 2) {
                if (player == FIRST_PLAYER) {
                    return FIRST_PLAYER_WON;
                } else {
                    return SECOND_PLAYER_WON;
                }
            }
        }
    }

    // Check diag
    int player = EMPTY;
    if ((player = board.get_cell(0, 0)) != EMPTY) {
        if (board.get_cell(1, 1) == player && board.get_cell(2, 2) == player) {
            if (player == FIRST_PLAYER) {
                return FIRST_PLAYER_WON;
            } else {
                return SECOND_PLAYER_WON;
            }
        }
    }

    if ((player = board.get_cell(0, 2)) != EMPTY) {
        if (board.get_cell(1, 1) == player && board.get_cell(2, 0) == player) {
            if (player == FIRST_PLAYER) {
                return FIRST_PLAYER_WON;
            } else {
                return SECOND_PLAYER_WON;
            }
        }
    }

    return PLAYING;
}

void game_manager_t::handle_error(const std::string & message) {
    std::cout << "This cell is already taken. Try again." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << board.to_string() << std::endl;
}