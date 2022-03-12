#include <iostream>
#include "game_board.h"
#include "game_manager.h"

int main() {
    game_manager_t manager;

    manager.game_loop();

    return 0;
}
