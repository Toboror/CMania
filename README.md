For compiling on MacOS: 

    gcc main.c systemEssentials.c cJSON/cJSON.c \
        -I./cJSON \
        -lcurl \
        -o myprogram

For compiling on Windows:

    gcc main.c systemEssentials.c \
    cJSON/cJSON.c \
    -I./cJSON \
    -I./curl-8.15.0_4-win64-mingw/include \
    -L./curl-8.15.0_4-win64-mingw/lib \
    -lcurl \
    -o myprogram

PS! Linux is the only one that is currently updated.

For compiling on Linux:

    gcc main.c essentials/systemEssentials.c terminal_runner/terminal_utils.c menus/start_menu.c game_offline/menus/offline_start/offline_start_menu.c game_online/menus
    /online_start_menu.c game_online/game_online_main.c game_offline/game_offline_main.c network/system_network.c cJSON/cJSON.c globals.c game_offline/menus/offline_settings/offline_settings_menu.c game_offline/menus/offline_new_game/offline_handle_new_game/offline_handle_new_game_management.c game_offline/menus/offline_new_game/offline_new_game_menu.h  -I./cJSON -lcurl -o program

PS! Remember to get cJSON and curl libraries and place them in the correct directories. Will probably automate it later.