#include "tic_tac_toe.h"
#include <iostream>
#include "players.h"
#include <fmt/core.h>


tic_tac_toe_t::tic_tac_toe_t(base_player_t *first_player, base_player_t *second_player) {
    this->first_player = first_player;
    this->second_player = second_player;
}

tic_tac_toe_t::~tic_tac_toe_t() {
    delete first_player;
    delete second_player;
}

/*
 * Main method which runs the game.
 */
//void tic_tac_toe_t::next_turn(const base_player_t & first_player, const base_player_t & second_player) {
void tic_tac_toe_t::next_turn() {
    int cell_num = 0;
    while (!(1 <= cell_num && cell_num <= 9)) {
        if (current_player == FIRST_PLAYER) {
            std::cout << "First player's turn:" << std::endl;
            cell_num = first_player->choose_cell(board);
        } else {
            std::cout << "Second player's turn:" << std::endl;
            cell_num = second_player->choose_cell(board);
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

    current_player = (current_player == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER;

    std::cout << board.to_string() << std::endl;
}

/*
 * Method for handling wrong inputs from player.
 */
void tic_tac_toe_t::handle_error(const std::string & message) {
    std::cout << message << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << board.to_string() << std::endl;
}

/*
 * Returns FIRST_PLAYER_WON if the first player has won.
 * Returns SECOND_PLAYER_WON if the second player has won.
 * Returns TIE if there are no free cells left and neither of the players has won.
 * Returns PLAYING if there are free cells left and neither of the players has won.
 */
int tic_tac_toe_t::check_state() {
    return board.check_state();
}

/*
 * Print explanation for the controls.
 */
void tic_tac_toe_t::print_rules() {
    std::cout << fmt::format("|{}|{}|{}|\n|{}|{}|{}|\n|{}|{}|{}|\n", 1, 2, 3, 4, 5, 6, 7, 8, 9);
    std::cout << "Enter a number from 1 to 9 to choose a corresponding cell on the board." << std::endl << std::endl;
}