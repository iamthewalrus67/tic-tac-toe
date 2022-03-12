//
// Created by iamthewalrus on 3/12/22.
//

#include "game_manager.h"
#include <iostream>
#include "players.h"

void game_manager_t::game_loop() {
    int state;
    std::cout << board.to_string() << std::endl;

    human_player_t first_player(FIRST_PLAYER);
    computer_minimax_player_t second_player(SECOND_PLAYER);

    while ((state = board.check_state()) == PLAYING) {
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
    } else if (state == SECOND_PLAYER) {
        std::cout << "Second player has won!" << std::endl;
    } else {
        std::cout << "Tie!" << std::endl;
    }
}

void game_manager_t::handle_error(const std::string & message) {
    std::cout << "This cell is already taken. Try again." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << board.to_string() << std::endl;
}