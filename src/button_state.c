/*
** my_minesweeper
** File description:
** button_state.c
*/

#include "../my.h"

void init_button_state(creator_t *button)
{
    button->button[2]->view = 0;
    button->button[2]->is_actif = 0;
}

void button_state_game_to_menu(creator_t *button)
{
    button->button[2]->is_actif = 0;
    button->button[2]->view = 0;
    button->button[0]->is_actif = 1;
    button->button[0]->view = 1;
    button->button[1]->is_actif = 1;
    button->button[1]->view = 1;
}

void button_state_menu_to_game(creator_t *button)
{
    button->button[0]->is_actif = 0;
    button->button[0]->view = 0;
    button->button[1]->is_actif = 0;
    button->button[1]->view = 0;
    button->button[2]->is_actif = 1;
    button->button[2]->view = 1;
    sfRectangleShape_setOutlineThickness(button->button[2]->rect, 0.0f);
}