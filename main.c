#include <stdbool.h>
#include <stdio.h>

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"
#define GLOBALS_H

#include "essentials/systemEssentials.h"
#include "terminal_runner/terminal_utils.h"
#include "menus/start_menu.h"
#include "network/system_network.h"
#include "game_online/game_online_main.h"
#include "game_offline/game_offline_main.h"

#ifdef _WIN32
    #include <conio.h> // For _getch()
    #define CLEAR_CMD "cls"
#else
    #include <unistd.h>
    #define CLEAR_CMD "clear"
#endif

int main(void) {
    enable_ansi_colors();

    bool running = true;

    while (running) {
        clear_screen();

        printf(RED_TEXT "\nWelcome to my game!\n"
               "Do you want to check for updates?\n"
               "1. Yes\n"
               "2. No\n");

        int answer;
        scanf("%d", &answer);

        while (true) {
            switch (answer) {
            case 1:
                check_for_updates();
                break;
            case 2:
                printf("Did not check for updates.");
                break;
            default:
                printf("Invalid input.");
            }
            break;
        }

        wait_for_enter();

        display_start_menu();

        if (online_or_offline_flag) {
            online_main();
        } else if (!online_or_offline_flag) {
            offline_main();
        }

        wait_for_enter();

        running = false;
    }

    return 0;
}
