//
// Created by iamthewalrus on 3/12/22.
//

#include "players.h"
#include <iostream>
#include <random>


int player_t::choose_cell(const game_board_t & board) {
    return 0;
}

int human_player_t::choose_cell(const game_board_t & board) {
    int cell_num = 0;
    std::cin >> cell_num;
    return cell_num;
}

int computer_random_player_t::choose_cell(const game_board_t &board) {
    std::random_device rand_device;
    std::mt19937 gen(rand_device());
    std::uniform_int_distribution<> distribution(1, 10);

    int cell_num;
    while (!board.is_cell_free(cell_num = distribution(gen)));
    return cell_num;
}