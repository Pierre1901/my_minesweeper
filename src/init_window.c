/*
** init window
** File description:
** init window
*/

#include "../my.h"

int init_window(creator_t *button)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create
            (mode, "my_minesweeper", sfResize | sfClose, NULL);
    sfEvent event;
    if (!window)
        return 1;
    create_all_buttons(button);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_button(button, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
