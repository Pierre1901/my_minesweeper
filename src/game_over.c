/*
** my_minesweeper
** File description:
** game_over.c
*/

#include "../my.h"

void show_game_over_screen(sfRenderWindow *window, int *lose, sfEvent event, int *in_game, int *close)
{
    if (*lose) {
        sfFont *font = sfFont_createFromFile("ressources/Championship.ttf");
        sfText *text = sfText_create();
        sfText_setPosition(text, (sfVector2f){600,200});
        sfText_setFont(text, font);
        sfText_setString(text, "\tGAME OVER\n\nRESTART --> [R]\n\nQUIT --> [Q]");
        sfText_setCharacterSize(text, 86);
        while (*lose) {
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawText(window, text, NULL);
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
                    *lose = 0;
                    *in_game = 0;

                }
                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ || event.type == sfEvtClosed) {
                    *close = 0;
                    *lose = 0;
                }
            }
            sfRenderWindow_display(window);
        }
        sfFont_destroy(font);
        sfText_destroy(text);
    }
}

