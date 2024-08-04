/*
** my_minesweeper
** File description:
** start_screen.c
*/

#include "../my.h"

static int show_name_of_game(sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile("ressources/Championship.ttf");
    if (font == NULL)
        return 1;
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setString(text, "MINESWEEPER");
    sfText_setPosition(text, (sfVector2f){400, 200});
    sfRenderWindow_drawText(window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
    return 0;
}

static int show_animate_background(sfRenderWindow *window, sfClock *clock)
{
    int frame_width = 750;
    int frame_height = 422;
    int total_frames = 1;
    float time_per_frame = 0.2f;
    sfTexture *texture = sfTexture_createFromFile("ressources/mine.png", NULL);
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    int current_frame = (int)(seconds / time_per_frame) % total_frames;
    sfIntRect frame_rect = {current_frame * frame_width, 0, frame_width, frame_height};
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, frame_rect);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setScale(sprite, (sfVector2f){3.0f, 3.0f});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return 0;
}

int start_screen(sfRenderWindow *window, creator_t *button, sfClock *clock, texture_t *texture)
{
    sfRectangleShape_setTexture(button->button[0]->rect, texture->easy_text, sfTrue);
    sfRectangleShape_setTexture(button->button[1]->rect, texture->hard_text, sfTrue);
    sfRectangleShape_setTexture(button->button[2]->rect, texture->arrow_text, sfTrue);
    show_animate_background(window, clock);
    draw_button(button, window);
    if (show_name_of_game(window) == 1)
        return 1;
    return 0;
}
