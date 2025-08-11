//
// Created by tobia on 11.08.2025.
//

#include "offline_character_management.h"

#include <stdio.h>
#include <string.h>

#include "../../../../globals.h"

void character_creation(char player_name_array[], int chosen_difficulty) {

    struct player player_character;
    strcpy(player_character.player_name, player_name_array);

    // This is for easy difficulty.
    switch (chosen_difficulty) {
        case 1:
            player_character.player_starting_damage = 20;
            player_character.player_starting_hp = 50;
            player_character.player_starting_money = 500;
            break;
        case 2:
            player_character.player_starting_damage = 10;
            player_character.player_starting_hp = 50;
            player_character.player_starting_money = 500;
            break;
        case 3:
            player_character.player_starting_damage = 5;
            player_character.player_starting_hp = 50;
            player_character.player_starting_money = 500;
            break;
            default:
            printf("%sInvalid input.", RED_TEXT);
            break;
    }

}

