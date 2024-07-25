/*
** my_minesweeper
** File description:
** game_over.c
*/

#include "../my.h"

void show_game_over_screen(sfRenderWindow *window, int *lose, sfEvent event, int *in_game)
{
    while (*lose) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
                *lose = 0;
            }
        }
        sfRenderWindow_display(window);
    }
}

