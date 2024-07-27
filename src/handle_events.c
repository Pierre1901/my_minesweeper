/*
** my_minesweeper
** File description:
** handle_events.c
*/

#include "../my.h"

void handle_event_in_menu(sfEvent *event, creator_t *button_creator, sfRenderWindow *window, int *game)
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

void handle_events_in_easy_game(sfRenderWindow *window, int *close, int *lose, int *in_game, grid_t grid[EASY_SIZE][EASY_SIZE], sfEvent *event)
{
    int x;
    int y;
    int view_x;
    int view_y;

    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtClosed || (event->type == sfEvtKeyPressed && event->key.code == sfKeyQ))
            *close = 0;
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyS)
            *lose = 1;
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyR)
            *in_game = 0;
        if (event->type == sfEvtMouseButtonPressed) {
            sfVector2u window_size = sfRenderWindow_getSize(window);
            sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
            view_x = (window_size.x - EASY_SIZE * 40.0f) / 2.0f;
            view_y = (window_size.y - EASY_SIZE * 40.0f) / 2.0f;
             x = (mouse_pos.x - view_x) / 40;
             y = (mouse_pos.y - view_y) / 40;
            if (x >= 0 && x < EASY_SIZE && y >= 0 && y < EASY_SIZE) {
                if (event->mouseButton.button == sfMouseRight && !grid[x][y].is_revealed)
                    grid[x][y].is_flagged = !grid[x][y].is_flagged;
                if (event->mouseButton.button == sfMouseLeft) {
                    if (!grid[x][y].is_flagged)
                        reveal_case(grid, x, y);
                }
            }
        }
        sfFloatRect visibleArea =
                {0.f, 0.f, (float)event->size.width, (float)event->size.height};
        if (event->type == sfEvtResized)
            sfRenderWindow_setView(window, sfView_createFromRect(visibleArea));
    }
}