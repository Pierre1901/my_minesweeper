/*
** my_minesweeper
** File description:
** start_screen.c
*/

#include "../my.h"

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

void lunch_difficulty(sfRenderWindow *window, int game)
{
    if (game == 1)
        puts("bou");
    if (game == 2)
        puts("salut");
}

int start_screen(sfRenderWindow *window, creator_t *button)
{
    draw_button(button, window);
    return 0;
}
