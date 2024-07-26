/*
** my_minesweeper
** File description:
** init_easy_grid.c
*/

#include "../my.h"

static void place_mine_on_easy_grid(grid_t grid[EASY_SIZE][EASY_SIZE])
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

void count_mine_on_easy_grid(grid_t grid[EASY_SIZE][EASY_SIZE])
{
    int count;
    int a;
    int b;

    for (int i = 0; i < EASY_SIZE; ++i) {
        for (int j = 0; j < EASY_SIZE; ++j) {
            if (grid[i][j].is_mine)
                continue;
            count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    a = i + k;
                    b = j + l;
                    if (a >= 0 && a < EASY_SIZE && b >= 0 && b < EASY_SIZE && grid[a][b].is_mine) {
                        count++;
                    }
                }
            }
            grid[i][j].nearly_mine = count;
        }
    }
}

void init_grid(grid_t grid[EASY_SIZE][EASY_SIZE])
{
    for (int i = 0; i < EASY_SIZE; i++){
        for (int j = 0; j < EASY_SIZE; j++){
            grid[i][j].is_mine = 0;
            grid[i][j].is_flagged = 0;
            grid[i][j].is_revealed = 0;
            grid[i][j].nearly_mine = 0;
        }
    }
    place_mine_on_easy_grid(grid);
    count_mine_on_easy_grid(grid);
}

