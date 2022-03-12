//
// Created by iamthewalrus on 3/12/22.
//

#include "game_board.h"
#include <fmt/core.h>

std::string game_board_t::to_string() {
    std::string board_string = fmt::format("|{}|{}|{}|\n|{}|{}|{}|\n|{}|{}|{}|\n",
                                           this->symbols.at(this->board[0][0]),
                                           this->symbols.at(this->board[0][1]),
                                           this->symbols.at(this->board[0][2]),
                                           this->symbols.at(this->board[1][0]),
                                           this->symbols.at(this->board[1][1]),
                                           this->symbols.at(this->board[1][2]),
                                           this->symbols.at(this->board[2][0]),
                                           this->symbols.at(this->board[2][1]),
                                           this->symbols.at(this->board[2][2]));

    return board_string;;
}

void game_board_t::set_cell(int index, int player) {
    --free_cells;
    this->board[(index-1)/3][(index-1)%3] = player;
}

int game_board_t::get_cell(int index) const {
    return this->board[(index-1)/3][(index-1)%3];
}

int game_board_t::get_cell(int x, int y) const {
    return this->board[x][y];
}

bool game_board_t::is_cell_free(int index) const {
    return this->board[(index-1)/3][(index-1)%3] == EMPTY;
}

bool game_board_t::is_full() const {
    return free_cells == 0;
}