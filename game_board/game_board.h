#ifndef TIC_TAC_TOE_GAME_BOARD_H
#define TIC_TAC_TOE_GAME_BOARD_H

#include <string>
#include <unordered_map>

enum GRID {
    EMPTY,
    FIRST_PLAYER,
    SECOND_PLAYER
};

enum STATE {
    PLAYING,
    FIRST_PLAYER_WON,
    SECOND_PLAYER_WON,
    TIE
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
    void set_cell(int x, int y, int player);
    int get_cell(int index) const;
    int get_cell(int x, int y) const;

    bool is_cell_free(int index) const;
    bool is_cell_free(int x, int y) const;
    bool is_full() const;

    int check_state() const;
private:
    int board[3][3] = {};
    std::unordered_map<int, std::string> symbols {
        { EMPTY, "_" },
        { FIRST_PLAYER, "X" },
        { SECOND_PLAYER, "O" }
    };
    int free_cells = 9;
};

#endif //TIC_TAC_TOE_GAME_BOARD_H
