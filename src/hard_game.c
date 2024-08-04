/*
** my_minesweeper
** File description:
** hard_game.c
*/

#include "../my.h"

static void draw_hard_map(sfRectangleShape *rect, sfTexture *flag_text, sfRenderWindow *window, grid_t grid[HARD_SIZE][HARD_SIZE], sfTexture *number_text[])
{

    int mines_around;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    int view_x = (window_size.x - HARD_SIZE * 40.0f) / 2.0f;
    int view_y = (window_size.y - HARD_SIZE * 40.0f) / 2.0f;

    for (int i = 0; i < HARD_SIZE; i++) {
        for (int j = 0; j < HARD_SIZE; j++) {
            sfRectangleShape_setPosition(rect, (sfVector2f){i * 40.0f + view_x, j * 40.0f + view_y});
            if (grid[i][j].is_flagged) {
                sfRectangleShape_setTexture(rect, flag_text, sfTrue);
            } else if (grid[i][j].is_revealed) {
                sfRectangleShape_setFillColor(rect, sfWhite);
                if (grid[i][j].is_mine) {
                    sfRectangleShape_setTexture(rect, NULL, sfFalse);
                    sfRectangleShape_setFillColor(rect, sfRed);
                } else {
                    mines_around = grid[i][j].nearly_mine;
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

void reveal_case_in_hard(grid_t grid[HARD_SIZE][HARD_SIZE], int x, int y)
{
    if (x < 0 || x >= HARD_SIZE || y < 0 || y >= HARD_SIZE || grid[x][y].is_revealed || grid[x][y].is_flagged) {
        return;
    }

    grid[x][y].is_revealed = 1;
    if (grid[x][y].nearly_mine == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (!grid[x][y].is_mine)
                    reveal_case_in_hard(grid, x + i, y + j);
            }
        }
    }
}

int lose_hard_game(grid_t grid[HARD_SIZE][HARD_SIZE], mine_game_t *mine)
{
    for (int i = 0; i < HARD_SIZE; i++){
        for (int j = 0; j < HARD_SIZE; j++){
            if (grid[i][j].is_revealed && grid[i][j].is_mine) {
                mine->lose = 1;
                mine->win = 0;
                return 1;
            }
        }
    }
    return 0;
}

void show_lose_in_hard(sfRectangleShape *rect, sfTexture *flag_text, sfRenderWindow *window, grid_t grid[HARD_SIZE][HARD_SIZE], sfTexture *number_text[], mine_game_t *mine)
{
    lose_hard_game(grid, mine);
    if (mine->lose) {
        draw_hard_map(rect, flag_text, window, grid, number_text);
        sfRenderWindow_display(window);
        sleep(2);
    }
}


int win_hard_game(grid_t grid[HARD_SIZE][HARD_SIZE])
{
    for (int i = 0; i < HARD_SIZE; i++) {
        for (int j = 0; j < HARD_SIZE; j++) {
            if (!grid[i][j].is_revealed && !grid[i][j].is_flagged)
                return 0;
            if (!grid[i][j].is_mine && grid[i][j].is_flagged)
                return 0;
        }
    }
    return 1;
}

int anim_background_in_hard(sfRenderWindow *window, sfClock *clock)
{
    int frame_width = 503;
    int frame_height = 369;
    int total_frames = 3;
    float time_per_frame = 0.2f;
    sfTexture *texture = sfTexture_createFromFile("ressources/waterfall.png", NULL);
    if (!texture)
        return 1;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    int current_frame = (int)(seconds / time_per_frame) % total_frames;
    sfIntRect frame_rect = {current_frame * frame_width, 0, frame_width, frame_height};
    sfSprite *sprite = sfSprite_create();
    if (!sprite) {
        sfTexture_destroy(texture);
        return 1;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, frame_rect);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setScale(sprite, (sfVector2f){4.0f, 3.0f});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return 0;
}

int start_hard(sfRenderWindow *window, sfTexture *number_text[], mine_game_t *mine, creator_t *button)
{
    grid_t grid[HARD_SIZE][HARD_SIZE];
    init_grid_in_hard(grid);
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){38.0f, 38.0f});
    sfEvent event;
    sfTexture *flag_text = sfTexture_createFromFile("ressources/flag.png", NULL);
    sfClock *clock = sfClock_create();
    button_state_menu_to_game(button);
    if (!flag_text)
        return 1;
    while (mine->in_game && mine->close){
        sfRenderWindow_clear(window, sfBlack);
        handle_events_in_hard_game(window, grid, &event, mine, button);
        if (mine->menu)
            break;
        if (mine->close == 0)
            break;
        if (win_hard_game(grid) == 1)
            mine->win = 1;
        if (anim_background_in_hard(window, clock) == 1)
            return 1;
        show_lose_in_hard(rect, flag_text, window, grid, number_text, mine);
        draw_hard_map(rect, flag_text, window, grid, number_text);
        show_game_over_screen(window, event, mine);
        show_win_easy_screen(window, event, mine);
        draw_button(button, window);
        sfRenderWindow_display(window);
    }
    sfRectangleShape_destroy(rect);
    sfTexture_destroy(flag_text);
    sfClock_destroy(clock);
    return 0;
}