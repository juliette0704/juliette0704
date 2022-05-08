/*
** EPITECH PROJECT, 2022
** draw_pause
** File description:
** my_rpg
*/

#include "my_rpg.h"

void quit_react(global_t *global)
{
    sfMouseButton click = sfMouseLeft;
    sfVector2f pos;
    if (sfIntRect_contains(&global->pause_menu[0].rect_quit, global->mouse.x, global->mouse.y)) {
        pos.x = global->pause_menu[0].pos_quit.x - 10;
        pos.y = global->pause_menu[0].pos_quit.y - 10;
        sfSprite_setPosition(global->pause_menu[0].quit, pos);
        if (sfMouse_isButtonPressed(click))
            end_game(global);
    } else
        sfSprite_setPosition(global->pause_menu[0].quit,
    global->pause_menu[0].pos_quit);
}

void option_react(global_t *global)
{
    sfVector2f pos;
    if (sfIntRect_contains(&global->pause_menu[0].rect_option, global->mouse.x, global->mouse.y)) {
        pos.x = global->pause_menu[0].pos_option.x - 10;
        pos.y = global->pause_menu[0].pos_option.y - 10;
        sfSprite_setPosition(global->pause_menu[0].option, pos);
    } else
        sfSprite_setPosition(global->pause_menu[0].option,
    global->pause_menu[0].pos_option);
}

void resume_react(global_t *global)
{
    sfMouseButton click = sfMouseLeft;
    sfVector2f pos;
    if (sfIntRect_contains(&global->pause_menu[0].rect_resume, global->mouse.x, global->mouse.y)) {
        pos.x = global->pause_menu[0].pos_resume.x - 10;
        pos.y = global->pause_menu[0].pos_resume.y - 10;
        sfSprite_setPosition(global->pause_menu[0].resume, pos);
        if (sfMouse_isButtonPressed(click))
            global->scene = global->scene_past;
    } else
        sfSprite_setPosition(global->pause_menu[0].resume,
    global->pause_menu[0].pos_resume);
}

void init_pause(global_t *global)
{
    sfIntRect rect[] = {{800, 200, 300, 90}, {800, 400, 300, 90}, {800, 600, 300, 90}};
    sfVector2f pos[] = {{800, 200}, {800, 400}, {800, 600}};
    sfVector2f scale = {1.5, 1.5};
    global->pause_menu[0].sprite = make_sprite("sprite/intro/pause.png");
    global->pause_menu[0].resume = make_sprite("sprite/intro/resume.png");
    global->pause_menu[0].option = make_sprite("sprite/intro/option.png");
    global->pause_menu[0].quit = make_sprite("sprite/intro/quit.png");
    sfSprite_setPosition(global->pause_menu[0].resume, pos[0]);
    sfSprite_setPosition(global->pause_menu[0].option, pos[1]);
    sfSprite_setPosition(global->pause_menu[0].quit, pos[2]);
    sfSprite_setScale(global->pause_menu[0].resume, scale);
    sfSprite_setScale(global->pause_menu[0].option, scale);
    sfSprite_setScale(global->pause_menu[0].quit, scale);
    global->pause_menu[0].pos_resume = pos[0];
    global->pause_menu[0].pos_option = pos[1];
    global->pause_menu[0].pos_quit = pos[2];
    global->pause_menu[0].rect_resume = rect[0];
    global->pause_menu[0].rect_option = rect[1];
    global->pause_menu[0].rect_quit = rect[2];
    return;
}

int draw_pause(global_t *global)
{
    resume_react(global);
    option_react(global);
    quit_react(global);
    if (global->my_exit == 1)
        return 1;
    sfRenderWindow_drawSprite(global->window, global->pause_menu[0].sprite, NULL);
    sfRenderWindow_drawSprite(global->window, global->pause_menu[0].resume, NULL);
    sfRenderWindow_drawSprite(global->window, global->pause_menu[0].option, NULL);
    sfRenderWindow_drawSprite(global->window, global->pause_menu[0].quit, NULL);
    return 0;
}
