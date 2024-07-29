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

        sfTexture *number_text[9];
        if (init_number_text(number_text) == 1)
            return 1;
        sfRenderWindow_clear(window, sfBlack);
        if (start_easy(window, &close, number_text) == 1)
            return 1;
        if (!close)
            *game = 100;
    }
    if (*game == 2) {
        int close = 1;

        sfTexture *number_text[9];
        if (init_number_text(number_text) == 1)
            return 1;
        sfRenderWindow_clear(window, sfBlack);
        if (start_hard(window, &close, number_text) == 1)
            return 1;
        if (!close)
            *game = 100;
    }
    return 0;
}