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
        while (true) {
            switch (answer) {
                case 1:
                    check_for_updates();
                    break;
                case 2:
                    printf("Did not check for updates.\n");
                    break;
                default:
                    printf("Invalid input.");
            }
            break;
        }

        system("read -p 'Press enter to continue...' var");

        running = false;

    }

    return 0;
}