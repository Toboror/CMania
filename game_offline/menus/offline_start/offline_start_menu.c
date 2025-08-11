//
// Created by Tobias Rønningen on 09/08/2025.
//

#include "../offline_start/offline_start_menu.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../../globals.h"

#include "../../../terminal_runner/terminal_utils.h"
#include "../offline_settings/offline_settings_menu.h"

void offline_display_start_menu(){

printf("%s\n\n--------------------------"
           "\nWelcome to CMania Offline!"
           "\n--------------------------\n", GREEN_TEXT);

    printf("What do you want to do?\n"
           "1. New game\n"
           "2. Load game\n"
           "3. Settings\n"
           "4. Exit\n");

    while (true) {
        int answer;
        scanf(" %d", &answer);
        switch (answer) {
        case 1:
            printf("You started a new game");
            break;
        case 2:
            printf("You loaded a new game");
            break;
        case 3:
            printf("You entered settings");
                offline_settings_main();
            break;
        case 4:
            printf("Exiting... \n");
            exit(0);
        default:
            printf("Invalid answer");
                break;
        }
    }


    wait_for_enter();

}
