/*
** my_minesweeper
** File description:
** start_screen.c
*/

#include "../my.h"

static int show_name_of_game(sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile("ressources/Championship.ttf");
    if (font == NULL)
        return 1;
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, "MINESWEEPER");
    sfText_setPosition(text, (sfVector2f){400, 200});
    sfRenderWindow_drawText(window, text, NULL);
    return 0;
}

void handle_event(sfEvent *event, creator_t *button_creator, sfRenderWindow *window, int *game)
{
    if (event->type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < button_creator->count; i++) {
            if (button_creator->button[0]->is_clicked(button_creator->button[0], event->mouseButton))
                *game = 1;
            if (button_creator->button[1]->is_clicked(button_creator->button[1], event->mouseButton))
                *game = 2;
        }
    }
    if (event->type == sfEvtMouseMoved) {
        for (int i = 0; i < button_creator->count; i++) {
            if (button_creator->button[i]->is_hover(button_creator->button[i], event->mouseMove))
                sfRectangleShape_setFillColor(button_creator->button[i]->rect, sfRed);
            else
                sfRectangleShape_setFillColor(button_creator->button[i]->rect, sfWhite);
        }
    }
    sfFloatRect visibleArea =
            {0.f, 0.f, (float)event->size.width, (float)event->size.height};
    if (event->type == sfEvtResized)
        sfRenderWindow_setView(window, sfView_createFromRect(visibleArea));
}

void lunch_difficulty(sfRenderWindow *window, int game, creator_t *buttons)
{
    if (game == 1){
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
        puts("bonjour");
    }
    if (game == 2) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
        puts("salut");
    }
}

int start_screen(sfRenderWindow *window, creator_t *button)
{
    draw_button(button, window);
    if (show_name_of_game(window) == 1)
        return 1;
    return 0;
}
