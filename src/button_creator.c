/*
** my_minesweeper
** File description:
** button_creator.c
*/


#include "../my.h"

creator_t *init_button(void)
{
    creator_t *button_creator = malloc(sizeof(creator_t));

    if (button_creator == NULL)
        return NULL;
    button_creator->count = 0;
    return button_creator;
}

sfBool is_button_clicked(button_s *button, sfMouseButtonEvent event)
{
    sfVector2f mouse = {event.x, event.y};
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->rect);

    return sfFloatRect_contains(&button_bounds, mouse.x, mouse.y);
}

sfBool is_button_hover(button_s *button, sfMouseMoveEvent event)
{
    sfVector2f mouse = {event.x, event.y};
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->rect);

    return sfFloatRect_contains(&button_bounds, mouse.x, mouse.y);
}

void add_button(creator_t *button_creator, button_s *button)
{
    if (button_creator->count < MAX) {
        button_creator->button[button_creator->count] = button;
        button_creator->count++;
    }
}

void draw_button(creator_t *button_creator, sfRenderWindow *window)
{
    for (int i = 0; i < button_creator->count; i++) {
        if (button_creator->button[i]->view == 1)
            sfRenderWindow_drawRectangleShape
                    (window, button_creator->button[i]->rect, NULL);
    }
}

void create_and_add_button(creator_t *button_creator,
                           sfVector2f position, sfVector2f size)
{
    button_s *new_button = malloc(sizeof(button_s));

    if (!new_button) {
        return;
    }
    //sfTexture *texture = sfTexture_createFromFile("graphic/flamingo/play.jpg", NULL);

//    if (!texture)
//        return;
    new_button->rect = sfRectangleShape_create();
    new_button->is_clicked = is_button_clicked;
    new_button->is_hover = is_button_hover;
    new_button->is_actif = 0;
    new_button->view = 1;
    sfRectangleShape_setSize(new_button->rect, size);
    sfRectangleShape_setPosition(new_button->rect, position);
    sfRectangleShape_setOutlineThickness(new_button->rect, 1.0f);
    sfRectangleShape_setOutlineColor(new_button->rect, sfBlack);
    sfRectangleShape_setFillColor(new_button->rect, sfWhite);
    add_button(button_creator, new_button);
    //sfRectangleShape_setTexture(button_creator->button[0]->rect, texture, sfTrue);
}

int create_all_buttons(creator_t *button_creator)
{
    create_and_add_button(button_creator,
                          (sfVector2f){700, 80}, (sfVector2f){500, 100});
    create_and_add_button(button_creator,
                          (sfVector2f){700, 200}, (sfVector2f){500, 100});


    return 0;
}
