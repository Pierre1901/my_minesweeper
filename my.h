/*
** EPITECH PROJECT, 2024
** B-MUL-200-LIL-2-1-mypaint-rafael.vandaepel
** File description:
** my.h
*/

#include "stdlib.h"
#include "stdio.h"
#include "SFML/Graphics.h"
#include "unistd.h"
#include "time.h"

#ifndef MY_H
    #define MY_H

#define MAX 20
#define EASY_SIZE 10
#define MAX_EASY 10
#define HARD_SIZE 25
#define MAX_HARD 75


typedef struct grid_t {
    int is_mine;
    int is_flagged;
    int is_revealed;
    int nearly_mine;
} grid_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent);
    sfTexture *texture;
    int is_actif;
    int view;
} button_s;

typedef struct mine_game_t {
    int in_game;
    int lose;
    int win;
    int close;
    int menu;
} mine_game_t;

typedef struct creator_t {
    button_s *button[MAX];
    int count;
} creator_t;

//init_window.c
int init_window(creator_t *button);

//button_creator.c
int create_all_buttons(creator_t *button_creator);
creator_t *init_button(void);
void draw_button(creator_t *button_creator, sfRenderWindow *window);
void destroy_button(creator_t *button_creator);

//start_screen.c
int start_screen(sfRenderWindow *window, creator_t *button, sfClock *clock);

//handle_events.c
void handle_event_in_menu(sfEvent *event, creator_t *button_creator, sfRenderWindow *window, int *game);
void handle_events_in_easy_game(sfRenderWindow *window, grid_t grid[EASY_SIZE][EASY_SIZE], sfEvent *event, mine_game_t *mine, creator_t *button);
void handle_events_in_hard_game(sfRenderWindow *window, grid_t grid[HARD_SIZE][HARD_SIZE], sfEvent *event, mine_game_t *mine);

//chose_difficulty.c
int lunch_difficulty(sfRenderWindow *window, int *game, creator_t *buttons);

//easy_game.c
int start_easy(sfRenderWindow *window, sfTexture *number_text[], mine_game_t *mine, creator_t *button);
void reveal_case(grid_t grid[EASY_SIZE][EASY_SIZE], int x, int y);

//game_over.c
void show_game_over_screen(sfRenderWindow *window, sfEvent event, mine_game_t *mine);
void show_game_over_screen_in_hard(sfRenderWindow *window, int *lose, sfEvent event, int *in_game, int *close);

//init_number_text.c
int init_number_text(sfTexture *number_text[]);

//init_easy_grid.c
void init_grid(grid_t grid[EASY_SIZE][EASY_SIZE]);

//win.c
void show_win_easy_screen(sfRenderWindow *window, sfEvent event, mine_game_t *mine);

//init_hard_grid.c
void init_grid_in_hard(grid_t grid[HARD_SIZE][HARD_SIZE]);

//hard_game.c
void reveal_case_in_hard(grid_t grid[HARD_SIZE][HARD_SIZE], int x, int y);
int start_hard(sfRenderWindow *window, sfTexture *number_text[], mine_game_t *mine);

//button_state.c
void button_state_menu_to_game(creator_t *button);
void button_state_game_to_menu(creator_t *button);
void init_button_state(creator_t *button);


#endif
