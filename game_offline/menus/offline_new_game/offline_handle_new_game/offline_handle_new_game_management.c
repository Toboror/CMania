//
// Created by tobia on 11.08.2025.
//

#include "offline_handle_new_game_management.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../../../globals.h"

void starting_new_game() {

    printf("%s\nWelcome to a new game!"
           "\nPlease, choose your preferred difficulty."
           "\n1. Easy"
           "\n2. Medium"
           "\n3. Hard"
           , GREEN_TEXT);

    choose_difficulty();


}

void choose_difficulty() {
    int *answer = malloc(sizeof(int));

    if (!answer) {
        return;
    }

    scanf("%d", answer);

    switch (*answer) {
        case 1:
            GAME_DIFFICULTY = answer;
            printf("%sYou have chosen the following difficulty: Easy", GREEN_TEXT);
            break;
        case 2:
            GAME_DIFFICULTY = answer;
            printf("%sYou have chosen the following difficulty: Medium", GREEN_TEXT);
            break;
        case 3:
            GAME_DIFFICULTY = answer;
            printf("%sYou have chosen the following difficulty: Hard", GREEN_TEXT);
            break;
            default:
            printf("%sInvalid input.", RED_TEXT);
            free(answer);
    }
}

