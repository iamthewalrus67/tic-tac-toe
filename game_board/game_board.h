//
// Created by iamthewalrus on 3/12/22.
//

#ifndef TIC_TAC_TOE_GAME_BOARD_H
#define TIC_TAC_TOE_GAME_BOARD_H

#include <string>
#include <unordered_map>

enum GRID {
    EMPTY,
    FIRST_PLAYER,
    SECOND_PLAYER
};

class game_board_t {
public:
    game_board_t() = default;

    game_board_t(const game_board_t&) = default;
    game_board_t& operator=(const game_board_t&) = delete;
    game_board_t(game_board_t&&) = default;
    game_board_t& operator=(game_board_t&&) = delete;
    ~game_board_t() = default;

    std::string to_string();
    void set_cell(int index, int player);
    int get_cell(int index);
    int get_cell(int x, int y);
    bool is_cell_free(int index);
    bool is_full();
private:
    int board[3][3] = {};
    std::unordered_map<int, std::string> symbols {{ EMPTY, "_" }, { FIRST_PLAYER, "X" }, { SECOND_PLAYER, "O" }};
    int free_cells = 9;
};

#endif //TIC_TAC_TOE_GAME_BOARD_H
