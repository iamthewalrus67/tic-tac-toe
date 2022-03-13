#include <iostream>
#include "game_board.h"
#include "tic_tac_toe.h"
#include "exit_codes.h"

/*
 * Set player equal to some player chosen by the user.
 * P.S. Couldn't think of a better way to create an object depending on user input :(
 */
void choose_player(base_player_t* & player, int player_num) {
    std::cout << "h - human, cr - computer, using random, cm - computer, using minimax." << std::endl;
    std::cout << "Choose player " << player_num << ":" << std::endl;

    while (true) {
        std::string player_choice;
        std::cin >> player_choice;

        if (player_choice == "h") {
            player = new human_player_t(player_num);
        } else if (player_choice == "cr") {
            player = new computer_random_player_t(player_num);
        } else if (player_choice == "cm") {
            player = new computer_minimax_player_t(player_num);
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
}

int main() {
    base_player_t* first_player = nullptr;
    base_player_t* second_player = nullptr;

    choose_player(first_player, FIRST_PLAYER);
    choose_player(second_player, SECOND_PLAYER);

    tic_tac_toe_t game;

    game.print_rules();

    int state;
    while ((state = game.check_state()) == PLAYING) {
        game.next_turn(*first_player, *second_player);
    }

    delete first_player;
    delete second_player;

    if (state == FIRST_PLAYER_WON) {
        std::cout << "First player has won!" << std::endl;
    } else if (state == SECOND_PLAYER) {
        std::cout << "Second player has won!" << std::endl;
    } else {
        std::cout << "Tie!" << std::endl;
    }

    return 0;
}
