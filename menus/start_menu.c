//
// Created by Tobias Rønningen on 09/08/2025.
//

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_TEXT "\033[0m"

#include <stdbool.h>
#include <stdio.h>
#include "start_menu.h"
#include "../network/system_network.h"

void display_start_menu(){

    printf(GREEN_TEXT "Welcome to CMania!""\n");

    online_or_offline();    // Nesting B)

}

void online_or_offline(){
    printf("Do you want to play online or offline?\n"
       "1. Online\n"
       "2. Offline\n");

    int answer;
    bool answered = false;
    scanf("%d",&answer);
    while (!answered) {
        if(answer == 1) {
            printf("Switching to online...");
            answered = true;
            online_or_offline_flag = true;
        } else if (answer == 2) {
            printf("Switching to offline...");
            answered = true;
            online_or_offline_flag = false;
        }
    }
}