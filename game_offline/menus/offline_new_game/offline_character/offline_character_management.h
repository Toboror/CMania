//
// Created by tobia on 11.08.2025.
//

#ifndef OFFLINE_CHARACTER_MANAGEMENT_H
#define OFFLINE_CHARACTER_MANAGEMENT_H

struct player {
    char player_name[32];
    int player_starting_hp;
    int player_starting_money;
    int player_starting_damage;
};

void character_creation();

#endif //OFFLINE_CHARACTER_MANAGEMENT_H
