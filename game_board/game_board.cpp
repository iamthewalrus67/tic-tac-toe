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
    if (player == EMPTY) {
        ++free_cells;
    } else {
        --free_cells;
    }
    this->board[(index-1)/3][(index-1)%3] = player;
}

void game_board_t::set_cell(int x, int y, int player) {
    if (player == EMPTY) {
        ++free_cells;
    } else {
        --free_cells;
    }
    this->board[x][y] = player;
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

int game_board_t::check_state() const {
    // Check column
    for (int i = 0; i < 3; ++i) {
        int player = get_cell(i, 0);
        if (player == EMPTY) {
            continue;
        }

        for (int j = 1; j < 3; ++j) {
            if (player != get_cell(i, j)) {
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
        int player = get_cell(0, i);
        if (player == EMPTY) {
            continue;
        }

        for (int j = 1; j < 3; ++j) {
            if (player != get_cell(j, i)) {
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
    int player;
    if ((player = get_cell(0, 0)) != EMPTY) {
        if (get_cell(1, 1) == player && get_cell(2, 2) == player) {
            if (player == FIRST_PLAYER) {
                return FIRST_PLAYER_WON;
            } else {
                return SECOND_PLAYER_WON;
            }
        }
    }

    if ((player = get_cell(0, 2)) != EMPTY) {
        if (get_cell(1, 1) == player && get_cell(2, 0) == player) {
            if (player == FIRST_PLAYER) {
                return FIRST_PLAYER_WON;
            } else {
                return SECOND_PLAYER_WON;
            }
        }
    }

    if (is_full()) {
        return TIE;
    }

    return PLAYING;
}