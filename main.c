#include <stdbool.h>
#include <stdio.h>
#include "systemEssentials.h"

int main(void) {

    bool running = true;

    while (running) {

        printf("\nWelcome to my game!\n"
               "Do you want to check for updates?\n");

        check_for_updates();

        printf("\n");

        running = false;

    }

    return 0;
}