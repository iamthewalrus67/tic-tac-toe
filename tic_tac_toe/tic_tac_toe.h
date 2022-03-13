#ifndef TIC_TAC_TOE_TIC_TAC_TOE_H
#define TIC_TAC_TOE_TIC_TAC_TOE_H

#include "game_board.h"
#include "players.h"


class tic_tac_toe_t {
public:
    tic_tac_toe_t() = default;

    tic_tac_toe_t(const tic_tac_toe_t&) = default;
    tic_tac_toe_t& operator=(const tic_tac_toe_t&) = delete;
    tic_tac_toe_t(tic_tac_toe_t&&) = default;
    tic_tac_toe_t& operator=(tic_tac_toe_t&&) = delete;
    ~tic_tac_toe_t() = default;

    void next_turn(const base_player_t & first_player, const base_player_t & second_player);
    int check_state();
    void handle_error(const std::string & message);
    void print_rules();
private:
    int current_player = FIRST_PLAYER;
    game_board_t board;
};

#endif //TIC_TAC_TOE_TIC_TAC_TOE_H
