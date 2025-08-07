#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "systemEssentials.h"

int main(void) {

    bool running = true;

    while (running) {

        printf("\nWelcome to my game!\n"
               "Do you want to check for updates?\n"
               "1. Yes\n"
               "2. No\n");
        int answer;
        scanf("%d", &answer);
        if (answer == 1) {
            check_for_updates();
        }

        printf("Did not check for updates.\n");

        running = false;

    }

    return 0;
}