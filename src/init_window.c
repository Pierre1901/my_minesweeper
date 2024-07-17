/*
** init window
** File description:
** init window
*/

#include "../my.h"

int init_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create
            (mode, "my_minesweeper", sfResize | sfClose, NULL);
    sfEvent event;
    if (!window)
        return 1;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
