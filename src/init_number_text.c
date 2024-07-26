/*
** my_minesweeper
** File description:
** init_number_text.c
*/

#include "../my.h"

int init_number_text(sfTexture *number_text[])
{
    for (int i = 0; i <= 4; ++i) {
        char filename[20];
        snprintf(filename, sizeof(filename), "ressources/%d.png", i);
        number_text[i] = sfTexture_createFromFile(filename, NULL);
        if (!number_text[i]) {
            return 1;
        }
    }
    return 0;
}


