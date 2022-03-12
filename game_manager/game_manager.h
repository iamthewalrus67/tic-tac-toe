//
// Created by iamthewalrus on 3/12/22.
//

#ifndef TIC_TAC_TOE_GAME_MANAGER_H
#define TIC_TAC_TOE_GAME_MANAGER_H

#include "game_board.h"


class game_manager_t {
public:
    game_manager_t() = default;

    game_manager_t(const game_manager_t&) = default;
    game_manager_t& operator=(const game_manager_t&) = delete;
    game_manager_t(game_manager_t&&) = default;
    game_manager_t& operator=(game_manager_t&&) = delete;
    ~game_manager_t() = default;

    void game_loop();
    void handle_error(const std::string & message);
private:
    int current_player = FIRST_PLAYER;
    game_board_t board;
};

#endif //TIC_TAC_TOE_GAME_MANAGER_H
