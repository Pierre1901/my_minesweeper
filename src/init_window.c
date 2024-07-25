/*
** init window
** File description:
** init window
*/

#include "../my.h"

int draw_menu(sfRenderWindow *window, int game, creator_t *button, sfClock *clock)
{
    if (game == 0) {
        sfRenderWindow_clear(window, sfBlack);
        if (start_screen(window, button, clock) == 1)
            return 1;
        sfRenderWindow_display(window);
    }
    return 0;
}

int init_window(creator_t *button)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create
            (mode, "my_minesweeper", sfResize | sfClose, NULL);
    int game = 0;
    sfEvent event;
    sfClock *clock = sfClock_create();

    if (!window)
        return 1;
    create_all_buttons(button);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            handle_event(&event, button, window, &game);
        }
        if (draw_menu(window, game, button, clock) == 1)
            return 1;
        lunch_difficulty(window, &game, button);
        if (game == 100)
            break;
    }
    sfRenderWindow_destroy(window);
    destroy_button(button);
    sfClock_destroy(clock);
    return 0;
}
