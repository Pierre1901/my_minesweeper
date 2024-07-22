/*
** my_minesweeper
** File description:
** easy_game.c
*/

#include "../my.h"

int start_easy(sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile("ressources/Championship.ttf");
    if (font == NULL)
        return 1;
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, "BONJOUR");
    sfText_setPosition(text, (sfVector2f){400, 200});
    sfRenderWindow_drawText(window, text, NULL);
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rect, sfGreen);
    sfRectangleShape_setSize(rect, (sfVector2f){200,200});
    sfRectangleShape_setPosition(rect, (sfVector2f){300,300});
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
    sfFont_destroy(font);
    sfText_destroy(text);
    return 0;
}