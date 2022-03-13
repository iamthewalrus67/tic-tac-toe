#include <iostream>
#include "game_board.h"
#include "tic_tac_toe.h"
#include "exit_codes.h"

/*
 * Set player equal to some player chosen by the user.
 */
base_player_t* choose_player(int player_num) {
    std::cout << "h - human, cr - computer, using random, cm - computer, using minimax." << std::endl;
    std::cout << "Choose player " << player_num << ":" << std::endl;

    base_player_t* player = nullptr;

    while (true) {
        std::string player_choice;
        std::cin >> player_choice;

        if (player_choice == "h") {
            player = new (std::nothrow) human_player_t(player_num);
        } else if (player_choice == "cr") {
            player = new (std::nothrow) computer_random_player_t(player_num);
        } else if (player_choice == "cm") {
            player = new (std::nothrow) computer_minimax_player_t(player_num);
        } else {
            std::cout << "Choose a valid option. h - human, cr - computer, using random, cm - computer, using minimax." << std::endl;
            continue;
        }

        break;
    }

    if (!player) {
        std::cerr << "Couldn't allocate memory." << std::endl;
        exit(MEMORY_ALLOCATION_ERROR);
    }

    return player;
}

int main() {
    base_player_t* first_player = choose_player(FIRST_PLAYER);
    base_player_t* second_player = choose_player(SECOND_PLAYER);

    tic_tac_toe_t game(first_player, second_player);

    game.print_rules();

    int state;
    while ((state = game.check_state()) == PLAYING) {
        game.next_turn();
    }

    if (state == FIRST_PLAYER_WON) {
        std::cout << "First player has won!" << std::endl;
    } else if (state == SECOND_PLAYER) {
        std::cout << "Second player has won!" << std::endl;
    } else {
        std::cout << "Tie!" << std::endl;
    }

    return 0;
}
