#ifndef TIC_TAC_TOE_PLAYERS_H
#define TIC_TAC_TOE_PLAYERS_H

#include "game_board.h"

/*
 * Base class for all player classes.
 */
class base_player_t {
protected:
    explicit base_player_t(int player_num);

    int player_num;
public:
    base_player_t() = delete;

    virtual int choose_cell(const game_board_t & board) const;
};

class human_player_t: public base_player_t {
public:
    human_player_t() = delete;
    explicit human_player_t(int player_num);

    int choose_cell(const game_board_t & board) const override;
};

class computer_random_player_t: public base_player_t {
public:
    computer_random_player_t() = delete;
    explicit computer_random_player_t(int player_num);

    int choose_cell(const game_board_t & board) const override;
};

class computer_minimax_player_t: public base_player_t {
public:
    computer_minimax_player_t() = delete;
    explicit computer_minimax_player_t(int player_num);

    int choose_cell(const game_board_t & board) const override;
private:
    int minimax(game_board_t* board, bool is_maximizing) const;
};

#endif //TIC_TAC_TOE_PLAYERS_H
