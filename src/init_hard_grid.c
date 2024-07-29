/*
** my_minesweeper
** File description:
** init_grid_in_hard.c
*/

#include "../my.h"

static void place_mine_on_hard_grid(grid_t grid[HARD_SIZE][HARD_SIZE])
{
    int mine_placed = 0;
    int x = 0;
    int y = 0;

    srand(time(NULL));
    while(mine_placed < MAX_HARD){
        x = rand() % HARD_SIZE;
        y = rand() % HARD_SIZE;
        if (!grid[x][y].is_mine){
            grid[x][y].is_mine = 1;
            mine_placed++;
        }
    }
}

void count_mine_on_hard_grid(grid_t grid[HARD_SIZE][HARD_SIZE])
{
    int count;
    int a;
    int b;

    for (int i = 0; i < HARD_SIZE; ++i) {
        for (int j = 0; j < HARD_SIZE; ++j) {
            if (grid[i][j].is_mine)
                continue;
            count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    a = i + k;
                    b = j + l;
                    if (a >= 0 && a < HARD_SIZE && b >= 0 && b < HARD_SIZE && grid[a][b].is_mine) {
                        count++;
                    }
                }
            }
            grid[i][j].nearly_mine = count;
        }
    }
}

void init_grid_in_hard(grid_t grid[HARD_SIZE][HARD_SIZE])
{
    for (int i = 0; i < HARD_SIZE; i++){
        for (int j = 0; j < HARD_SIZE; j++){
            grid[i][j].is_mine = 0;
            grid[i][j].is_flagged = 0;
            grid[i][j].is_revealed = 0;
            grid[i][j].nearly_mine = 0;
        }
    }
    place_mine_on_hard_grid(grid);
    count_mine_on_hard_grid(grid);
}

