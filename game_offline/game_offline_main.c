//
// Created by Tobias Rønningen on 09/08/2025.
//

#include "game_offline_main.h"
#include "../terminal_runner/terminal_utils.h"
#include <stdbool.h>

#include "menus/offline_start/offline_start_menu.h"

void offline_main(){

    bool running = true;

    while (running) {
        offline_display_start_menu();

        wait_for_enter();

        running = false;

    }


}
