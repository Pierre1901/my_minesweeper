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


typedef struct grid_t {
    int is_mine;
    int is_flagged;
    int is_revealed;
} grid_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent);
    sfTexture *texture;
    int is_actif;
    int view;
} button_s;


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
void handle_events_in_easy_game(sfRenderWindow *window, int *close, int *lose, int *in_game, grid_t grid[EASY_SIZE][EASY_SIZE], sfEvent *event);

//chose_difficulty.c
void lunch_difficulty(sfRenderWindow *window, int *game, creator_t *buttons);

//easy_game.c
int start_easy(sfRenderWindow *window, int *close);

//game_over.c
void show_game_over_screen(sfRenderWindow *window, int *lose, sfEvent event, int *in_game);


#endif
