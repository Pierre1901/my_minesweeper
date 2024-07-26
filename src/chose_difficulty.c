/*
** my_minesweeper
** File description:
** chose_difficulty.c
*/

#include "../my.h"

int lunch_difficulty(sfRenderWindow *window, int *game, creator_t *buttons)
{
    if (*game == 1){
        int close = 1;
        sfRenderWindow_clear(window, sfBlack);
        if (start_easy(window, &close) == 1)
            return 1;
        if (!close)
            *game = 100;
    }
    if (*game == 2) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
}