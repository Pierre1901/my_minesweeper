/*
** my_minesweeper
** File description:
** easy_game.c
*/

#include "../my.h"

#define EASY_SIZE 10

typedef struct grid_t {
    int is_mine;
    int is_flagged;
    int is_revealed;
} grid_t;



void init_grid(grid_t grid[EASY_SIZE][EASY_SIZE])
{
    for (int i = 0; i < EASY_SIZE; i++){
        for (int j = 0; j < EASY_SIZE; j++){
            grid[i][j].is_mine = 0;
            grid[i][j].is_flagged = 0;
            grid[i][j].is_revealed = 0;
        }
    }
}

int start_easy(sfRenderWindow *window, int *close)
{
    int in_game = 1;
    int lose = 0;

    grid_t grid[EASY_SIZE][EASY_SIZE];
    init_grid(grid);
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){38.0f, 38.0f});
    sfEvent event;

    while (in_game && *close){
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ)) {
               *close = 0;
            }
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
                    lose = 1;
        }
        if (*close == 0)
            break;
        show_game_over_screen(window, &lose, event, &in_game);
        for (int i = 0; i < EASY_SIZE; i++){
            for (int j = 0; j < EASY_SIZE; j++){
                sfRectangleShape_setPosition(rect, (sfVector2f){i * 40.0f + 1, j * 40.0f + 1});
                sfRenderWindow_drawRectangleShape(window, rect, NULL);
            }
        }
        sfRenderWindow_display(window);
    }
    sfRectangleShape_destroy(rect);



    return 0;
}
