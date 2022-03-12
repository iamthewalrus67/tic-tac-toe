//
// Created by iamthewalrus on 3/12/22.
//

#ifndef TIC_TAC_TOE_PLAYERS_H
#define TIC_TAC_TOE_PLAYERS_H

#include "game_board.h"

class player_t {
protected:
    player_t() = default;
public:
    player_t(const player_t&) = default;
    player_t& operator=(const player_t&) = delete;
    player_t(player_t&&) = default;
    player_t& operator=(player_t&&) = delete;
    ~player_t() = default;

    virtual int choose_cell(const game_board_t & board);
};

class human_player_t: public player_t {
public:
    human_player_t() = default;

    human_player_t(const human_player_t&) = default;
    human_player_t& operator=(const human_player_t&) = delete;
    human_player_t(human_player_t&&) = default;
    human_player_t& operator=(human_player_t&&) = delete;
    ~human_player_t() = default;

    int choose_cell(const game_board_t & board) override;
};

class computer_random_player_t: public player_t {
public:
    int choose_cell(const game_board_t & board);
};

#endif //TIC_TAC_TOE_PLAYERS_H
