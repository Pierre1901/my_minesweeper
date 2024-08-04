/*
** my_minesweeper
** File description:
** init_game_text.c
*/

#include "../my.h"

int init_texture(texture_t *texture)
{
    texture->easy_text = sfTexture_createFromFile("ressources/easy_button.png", NULL);
    texture->hard_text = sfTexture_createFromFile("ressources/hard_button.png", NULL);
    texture->arrow_text = sfTexture_createFromFile("ressources/return_arrow.png", NULL);
    if (!texture->easy_text || !texture->hard_text || !texture->arrow_text)
        return 1;
    return 0;
}

