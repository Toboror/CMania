#include "terminal_utils.h"
#include <stdio.h>
#include <stdlib.h>
#define RESET_TEXT "\033[0m"

#ifdef _WIN32
#include <windows.h>
#endif

void clear_screen(void) {
    system(CLEAR_CMD);
}

void wait_for_enter(void) {
#ifdef _WIN32
    printf("Press any key to continue...");
    _getch();
#else
    printf(RESET_TEXT "\nPress Enter to continue...\n");
    while (getchar() != '\n'); // Clear leftover input
    getchar();
#endif
}

void enable_ansi_colors(void) {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}
