cmake_minimum_required(VERSION 3.31)
project(Cmania C)

set(CMAKE_C_STANDARD 11)

add_executable(Cmania main.c
        network/system_network.h
        network/system_network.c
        essentials/systemEssentials.c
        terminal_runner/terminal_utils.c
        terminal_runner/terminal_utils.h
        game_offline/game_events/investment/investment.c
        game_offline/game_events/investment/investment.h
        menus/start_menu.c
        menus/start_menu.h
        game_offline/game_offline_main.c
        game_offline/game_offline_main.h
        game_online/game_online_main.c
        game_online/game_online_main.h
        game_offline/menus/offline_start/offline_start_menu.c
        game_offline/menus/offline_start/offline_start_menu.h
        game_online/menus/online_start_menu.c
        game_online/menus/online_start_menu.h
        game_offline/menus/offline_settings/offline_settings_menu.c
        game_offline/menus/offline_settings/offline_settings_menu.h
        globals.c
        globals.h
        game_offline/menus/offline_new_game/offline_new_game_menu.c
        game_offline/menus/offline_new_game/offline_new_game_menu.h
        game_offline/menus/offline_new_game/offline_character/offline_character_management.c
        game_offline/menus/offline_new_game/offline_character/offline_character_management.h
        game_offline/menus/offline_new_game/offline_handle_new_game/offline_handle_new_game_management.c
        game_offline/menus/offline_new_game/offline_handle_new_game/offline_handle_new_game_management.h
)
