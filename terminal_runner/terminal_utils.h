#ifndef TERMINAL_UTILS_H
#define TERMINAL_UTILS_H

#ifdef _WIN32
    #include <conio.h>   // For _getch()
    #define CLEAR_CMD "cls"
#else
    #include <unistd.h>
    #define CLEAR_CMD "clear"
#endif

// Clears the terminal screen
void clear_screen(void);

// Waits for the user to press Enter (or any key on Windows)
void wait_for_enter(void);

// Enables ANSI escape sequences for colors on Windows (does nothing on macOS/Linux)
void enable_ansi_colors(void);

#endif
