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

#ifndef MY_H
    #define MY_H

#define MAX 20

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
void handle_event(sfEvent *event, creator_t *button_creator, sfRenderWindow *window, int *game);

//chose_difficulty.c
void lunch_difficulty(sfRenderWindow *window, int game, creator_t *buttons);

//easy_game.c
int start_easy(sfRenderWindow *window);


#endif
