/*
** my_minesweeper
** File description:
** handle_events.c
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
                sfRectangleShape_setOutlineThickness(button_creator->button[i]->rect, 3.0f);
            else
                sfRectangleShape_setOutlineThickness(button_creator->button[i]->rect, 1.0f);
        }
    }
    sfFloatRect visibleArea =
            {0.f, 0.f, (float)event->size.width, (float)event->size.height};
    if (event->type == sfEvtResized)
        sfRenderWindow_setView(window, sfView_createFromRect(visibleArea));
}