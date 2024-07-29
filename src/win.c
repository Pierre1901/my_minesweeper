/*
** my_minesweeper
** File description:
** win.c
*/

#include "../my.h"

void show_win_easy_screen(sfRenderWindow *window, int *win, sfEvent event, int *in_game, int *close)
{
    if (*win) {
        sfFont *font = sfFont_createFromFile("ressources/Championship.ttf");
        sfText *text = sfText_create();
        sfText_setPosition(text, (sfVector2f){600,200});
        sfText_setFont(text, font);
        sfText_setString(text, "\tYOU WIN !\n\nRESTART --> [R]\n\nQUIT --> [Q]");
        sfText_setCharacterSize(text, 86);
        while (*win) {
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawText(window, text, NULL);
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyR) {
                    *win = 0;
                    *in_game = 0;
                }
                if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ || event.type == sfEvtClosed) {
                    *close = 0;
                    *win = 0;
                }
            }
            sfRenderWindow_display(window);
        }
        sfFont_destroy(font);
        sfText_destroy(text);
    }
}