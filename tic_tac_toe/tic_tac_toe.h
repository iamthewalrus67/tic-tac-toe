#ifndef TIC_TAC_TOE_TIC_TAC_TOE_H
#define TIC_TAC_TOE_TIC_TAC_TOE_H

#include "game_board.h"
#include "players.h"


class tic_tac_toe_t {
public:
    tic_tac_toe_t() = delete;
    tic_tac_toe_t(base_player_t* first_player, base_player_t* second_player);


    tic_tac_toe_t(const tic_tac_toe_t&) = default;
    tic_tac_toe_t& operator=(const tic_tac_toe_t&) = delete;
    tic_tac_toe_t(tic_tac_toe_t&&) = default;
    tic_tac_toe_t& operator=(tic_tac_toe_t&&) = delete;
    ~tic_tac_toe_t();

    void next_turn();
    int check_state();
    void handle_error(const std::string & message);
    void print_rules();
private:
    int current_player = FIRST_PLAYER;
    game_board_t board;
    base_player_t* first_player;
    base_player_t* second_player;
};

#endif //TIC_TAC_TOE_TIC_TAC_TOE_H
