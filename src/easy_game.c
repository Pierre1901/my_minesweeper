/*
** my_minesweeper
** File description:
** easy_game.c
*/

#include "../my.h"




static void place_mine_on_grid(grid_t grid[EASY_SIZE][EASY_SIZE])
{
    int mine_placed = 0;
    int x = 0;
    int y = 0;

    srand(time(NULL));
    while(mine_placed < MAX_EASY){
        x = rand() % EASY_SIZE;
        y = rand() % EASY_SIZE;
        if (!grid[x][y].is_mine){
            grid[x][y].is_mine = 1;
            mine_placed++;
        }
    }
}

static void init_grid(grid_t grid[EASY_SIZE][EASY_SIZE])
{
    for (int i = 0; i < EASY_SIZE; i++){
        for (int j = 0; j < EASY_SIZE; j++){
            grid[i][j].is_mine = 0;
            grid[i][j].is_flagged = 0;
            grid[i][j].is_revealed = 0;
        }
    }
    place_mine_on_grid(grid);
}

static void draw_easy_map(sfRectangleShape *rect, sfTexture *flag_text, sfRenderWindow *window, grid_t grid[EASY_SIZE][EASY_SIZE])
{
    for (int i = 0; i < EASY_SIZE; i++){
        for (int j = 0; j < EASY_SIZE; j++){
            sfRectangleShape_setPosition(rect, (sfVector2f){i * 40.0f + 1, j * 40.0f + 1});
            if (grid[i][j].is_flagged == 1) {
                sfRectangleShape_setTexture(rect, flag_text, sfTrue);
                sfRectangleShape_setFillColor(rect, sfWhite);
            }
            else if (grid[i][j].is_mine == 1) {
                sfRectangleShape_setTexture(rect, NULL, sfFalse);
                sfRectangleShape_setFillColor(rect, sfRed);
            }
            else {
                sfRectangleShape_setTexture(rect, NULL, sfFalse);
                sfRectangleShape_setFillColor(rect, sfWhite);
            }
            sfRenderWindow_drawRectangleShape(window, rect, NULL);
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
    sfTexture *flag_text = sfTexture_createFromFile("ressources/flag.png", NULL);

    if (!flag_text)
        return 1;
    while (in_game && *close){
        sfRenderWindow_clear(window, sfBlack);
        handle_events_in_easy_game(window, close, &lose, &in_game, grid, &event);
        if (*close == 0)
            break;
        show_game_over_screen(window, &lose, event, &in_game);
        draw_easy_map(rect, flag_text, window, grid);
        sfRenderWindow_display(window);
    }
    sfRectangleShape_destroy(rect);
    sfTexture_destroy(flag_text);
    return 0;
}
