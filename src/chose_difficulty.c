/*
** my_minesweeper
** File description:
** chose_difficulty.c
*/

#include "../my.h"

void lunch_difficulty(sfRenderWindow *window, int game, creator_t *buttons)
{
    if (game == 1){
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    if (game == 2) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
}