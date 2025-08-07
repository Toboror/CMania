//
// Created by tobia on 07.08.2025.
//

#include <stdio.h>
#include "systemEssentials.h"

#include <stdbool.h>

#include "unistd.h"

void check_for_updates() {
    bool foundUpdate = false;
    printf("Checking for updates...\n");
    for (int i = 0; i < 3; i++) {
        sleep(1);
        printf("...");
    }
    if (foundUpdate) {
        printf("Found update! Updating now.");
    } else {
        printf("Did not find update. Continuing.");
    }
}