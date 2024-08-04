/*
** my_minesweeper
** File description:
** chose_difficulty.c
*/

#include "../my.h"


int lunch_difficulty(sfRenderWindow *window, int *game, creator_t *button)
{
    if (*game == 1) {
        mine_game_t mine = {1,0,0,1,0};

        sfTexture *number_text[9];
        if (init_number_text(number_text) == 1)
            return 1;
        sfRenderWindow_clear(window, sfBlack);
        if (start_easy(window, number_text, &mine, button) == 1)
            return 1;
        if (!mine.close)
            *game = 100;
        if (mine.menu) {
            *game = 0;
            return 0;
    }
        for (int i = 0; i < 5; i ++)
            sfTexture_destroy(number_text[i]);
    }
    if (*game == 2) {
        mine_game_t mine = {1,0,0,1,0};

        sfTexture *number_text[9];
        if (init_number_text(number_text) == 1)
            return 1;
        sfRenderWindow_clear(window, sfBlack);
        if (start_hard(window, number_text, &mine, button) == 1)
            return 1;
        if (mine.menu) {
            *game = 0;
            return 0;
        }
        if (!mine.close)
            *game = 100;
        for (int i = 0; i < 5; i ++){
            sfTexture_destroy(number_text[i]);
        }
    }

    return 0;
}