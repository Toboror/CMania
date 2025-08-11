#!/bin/bash

# Compile the program
gcc main.c essentials/systemEssentials.c terminal_runner/terminal_utils.c menus/start_menu.c game_offline/menus/offline_start/offline_start_menu.c game_online/menus/online_start_menu.c game_online/game_online_main.c game_offline/game_offline_main.c network/system_network.c cJSON/cJSON.c globals.c game_offline/menus/offline_settings/offline_settings_menu.c -I./cJSON -lcurl -o program

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "Compilation succeeded. Yippieee!"

    # Open a new Terminal window and run the program
    open -a Terminal ./program
else
    echo "Compilation failed. Bohooo :( Please check the errors above."
    exit 1
fi