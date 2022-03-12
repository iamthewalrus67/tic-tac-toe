//
// Created by iamthewalrus on 3/12/22.
//

#include "players.h"
#include <iostream>
#include <random>

player_t::player_t(int player_num) {
    this->player_num = player_num;
}

human_player_t::human_player_t(int player_num): player_t(player_num) {}

computer_random_player_t::computer_random_player_t(int player_num): player_t(player_num) {}

computer_minimax_player_t::computer_minimax_player_t(int player_num): player_t(player_num) {}

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

int computer_minimax_player_t::choose_cell(const game_board_t &board) {
    game_board_t board_copy{board};
    int best_score = std::numeric_limits<int>::min();
    int best_move = 0;

    for (int i = 1; i < 10; ++i) {
        if (board_copy.is_cell_free(i)) {
            board_copy.set_cell(i, player_num);
            auto score = minimax(board_copy, 0, false);
            board_copy.set_cell(i, EMPTY);

            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }

    return best_move;
}

int computer_minimax_player_t::minimax(game_board_t & board, int depth, bool is_maximizing) {
    auto state = board.check_state();

    if ((state == FIRST_PLAYER_WON && player_num == FIRST_PLAYER) || (state == SECOND_PLAYER_WON && player_num == SECOND_PLAYER)) {
        return 1;
    } else if ((state == FIRST_PLAYER_WON && player_num == SECOND_PLAYER) || (state == SECOND_PLAYER_WON && player_num == FIRST_PLAYER)) {
        return -1;
    } else if (state == TIE) {
        return 0;
    }

    if (is_maximizing) {
        int best_score = std::numeric_limits<int>::min();
        for (int i = 1; i < 10; ++i) {
            if (board.is_cell_free(i)) {
                board.set_cell(i, player_num);
                int score = minimax(board, depth+1, false);
                board.set_cell(i, EMPTY);
                if (score > best_score) {
                    best_score = score;
                }
            }
        }
        return best_score;
    } else {
        int best_score = std::numeric_limits<int>::max();
        for (int i = 1; i < 10; ++i) {
            if (board.is_cell_free(i)) {
                board.set_cell(i, (player_num == FIRST_PLAYER) ? SECOND_PLAYER : FIRST_PLAYER);
                int score = minimax(board, depth+1, true);
                board.set_cell(i, EMPTY);
                if (score < best_score) {
                    best_score = score;
                }
            }
        }
        return best_score;
    }
}