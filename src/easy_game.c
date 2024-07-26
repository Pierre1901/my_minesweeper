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

void count_mine(grid_t grid[EASY_SIZE][EASY_SIZE])
{
    int count;
    int ni;
    int nj;

    for (int i = 0; i < EASY_SIZE; ++i) {
        for (int j = 0; j < EASY_SIZE; ++j) {
            if (grid[i][j].is_mine)
                continue;
            count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    ni = i + k;
                    nj = j + l;
                    if (ni >= 0 && ni < EASY_SIZE && nj >= 0 && nj < EASY_SIZE && grid[ni][nj].is_mine) {
                        count++;
                    }
                }
            }
            grid[i][j].nearly_mine = count;
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
            grid[i][j].nearly_mine = 0;
        }
    }
    place_mine_on_grid(grid);
    count_mine(grid);
}


static void draw_easy_map(sfRectangleShape *rect, sfTexture *flag_text, sfRenderWindow *window, grid_t grid[EASY_SIZE][EASY_SIZE], sfTexture *number_text[])
{
    for (int i = 0; i < EASY_SIZE; i++) {
        for (int j = 0; j < EASY_SIZE; j++) {
            sfRectangleShape_setPosition(rect, (sfVector2f){i * 40.0f + 1, j * 40.0f + 1});
            if (grid[i][j].is_flagged) {
                sfRectangleShape_setTexture(rect, flag_text, sfTrue);
            } else if (grid[i][j].is_revealed) {
                if (grid[i][j].is_mine) {
                    sfRectangleShape_setTexture(rect, NULL, sfFalse);
                    sfRectangleShape_setFillColor(rect, sfRed);
                } else {
                    int mines_around = grid[i][j].nearly_mine;
                    sfRectangleShape_setTexture(rect, number_text[mines_around], sfTrue);
                }
            } else {
                sfRectangleShape_setFillColor(rect, sfWhite);
                sfRectangleShape_setTexture(rect, NULL, sfFalse);
            }
            sfRenderWindow_drawRectangleShape(window, rect, NULL);
        }
    }
}

void reveal_case(grid_t grid[EASY_SIZE][EASY_SIZE], int x, int y)
{
    if (x < 0 || x >= EASY_SIZE || y < 0 || y >= EASY_SIZE || grid[x][y].is_revealed || grid[x][y].is_flagged) {
        return;
    }

    grid[x][y].is_revealed = 1;
    if (grid[x][y].nearly_mine == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (!grid[x][y].is_mine)
                    reveal_case(grid, x + i, y + j);
            }
        }
    }
}

int start_easy(sfRenderWindow *window, int *close)
{
    int in_game = 1;
    int lose = 0;

    sfTexture *number_text[9];
    for (int i = 0; i <= 3; ++i) {
        char filename[20];
        snprintf(filename, sizeof(filename), "ressources/%d.png", i);
        number_text[i] = sfTexture_createFromFile(filename, NULL);
        if (!number_text[i]) {
            return 1;
        }
    }

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
        draw_easy_map(rect, flag_text, window, grid, number_text);
        sfRenderWindow_display(window);
    }
    sfRectangleShape_destroy(rect);
    sfTexture_destroy(flag_text);
    return 0;
}
