//
// Created by Tobias Rønningen on 09/08/2025.
//

#include "offline_start_menu.h"
#include <stdio.h>
#include <stdlib.h>

#include "../../terminal_runner/terminal_utils.h"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

void offline_display_start_menu(){

    printf(GREEN_TEXT "Welcome to CMania Offline!""\n");

    printf("What do you want to do?\n"
           "1. New game\n"
           "2. Load game\n"
           "3. Settings\n"
           "4. Exit\n");

    int answer;
    scanf(" %d", &answer);
    while (answer != 1 && answer != 2 && answer != 3 && answer != 4) {
        switch (answer) {
        case 1:
            printf("You started a new game");
            break;
        case 2:
            printf("You loaded a new game");
            break;
        case 3:
            printf("You entered settings");
            break;
        case 4:
            printf("Exiting...");
            exit(0);
        default:
            printf("Invalid answer");
        }
    }


    wait_for_enter();

}