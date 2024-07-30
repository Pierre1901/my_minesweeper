/*
** my_minesweeper
** File description:
** chose_difficulty.c
*/

#include "../my.h"


int lunch_difficulty(sfRenderWindow *window, int *game, creator_t *buttons)
{
    if (*game == 1) {
        int close = 1;
        int menu = 0;

        sfTexture *number_text[9];
        if (init_number_text(number_text) == 1)
            return 1;
        sfRenderWindow_clear(window, sfBlack);
        if (start_easy(window, &close, number_text, &menu) == 1)
            return 1;
        if (!close)
            *game = 100;
        if (menu) {
            *game = 0;
            return 0;
    }
        for (int i = 0; i < 5; i ++){
            sfTexture_destroy(number_text[i]);
        }
    }
    if (*game == 2) {
        int close = 1;
        int menu = 0;

        sfTexture *number_text[9];
        if (init_number_text(number_text) == 1)
            return 1;
        sfRenderWindow_clear(window, sfBlack);
        if (start_hard(window, &close, number_text, &menu) == 1)
            return 1;
        if (menu) {
            *game = 0;
            return 0;
        }
        if (!close)
            *game = 100;
        for (int i = 0; i < 5; i ++){
            sfTexture_destroy(number_text[i]);
        }
    }

    return 0;
}