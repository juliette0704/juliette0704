/*
** EPITECH PROJECT, 2021
** tutorial.c
** File description:
** tuto
*/

#include "my_rpg.h"

void mouse_is_it_yes(global_t *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
    sfMouseButton bout = sfMouseLeft;
    if (sfMouse_isButtonPressed(bout)) {
        if (pos.x > 1032 && pos.x < 1060 && pos.y > 212 && pos.y < 227)
            m->bubble[0].i = 3;
        if (pos.x > 1228 && pos.x < 1243 && pos.y > 210 && pos.y < 230)
            sfRenderWindow_close(m->window);
    }
}

void before_training(global_t *global)
{
    if (global->bubble[0].i == 1)
        sfRenderWindow_drawText(global->window, global->bubble[0].text1, NULL);
    if (global->bubble[0].i == 2)
        sfRenderWindow_drawText(global->window, global->bubble[0].text2, NULL);
    if (global->bubble[0].i == 3) {
        sfSprite_setPosition(global->minispace[0].sprite, (sfVector2f){-5000, -5000});
        sfRenderWindow_drawText(global->window, global->bubble[0].text3, NULL);
    }
}

void speak_of_training(global_t *global)
{
    if (global->bubble[0].sec > 10 && global->bubble[0].i != 3) {
        sfSprite_setPosition(global->minispace[0].sprite, (sfVector2f){1400, 236});
        sfRenderWindow_drawSprite(global->window, global->minispace[0].sprite, NULL);
        if (sfKeyboard_isKeyPressed((sfKeyCode){sfKeySpace}) && global->bubble[0].i == 1) {
            global->bubble[0].i = 2;
        }
    }
    mouse_is_it_yes(global);
}

void speak_to_mentor(global_t *global)
{
    if (global->bubble[0].i == 0)
        sfRenderWindow_drawText(global->window, global->bubble[0].text, NULL);
    if (global->bubble[0].sec > 7 && global->bubble[0].sec < 10) {
        sfRenderWindow_drawSprite(global->window, global->minispace[0].sprite, NULL);
        if (sfKeyboard_isKeyPressed((sfKeyCode){sfKeySpace}) && global->bubble[0].i == 0) {
            sfSprite_setPosition(global->minispace[0].sprite, (sfVector2f){-5000, -5000});
            global->bubble[0].i = 1;
        }
    }
}

void final_step(global_t *global)
{
    if (global->bubble[0].i == 7) {
        sfRenderWindow_drawSprite(global->window, global->speak[0].sprite, NULL);
        sfRenderWindow_drawText(global->window, global->bubble[0].text7, NULL);
        if (sfKeyboard_isKeyPressed((sfKeySpace))) {
            global->scene = -1;
        }
    }
}

void step_to_go(global_t *global)
{
    if (global->bubble[0].i == 6) {
        sfSprite_setPosition(global->speak[0].sprite, (sfVector2f){0, 200});
        sfRenderWindow_drawSprite(global->window, global->speak[0].sprite, NULL);
        sfRenderWindow_drawText(global->window, global->bubble[0].text6, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            global->bubble[0].i = 7;
        }
        // if (sfKeyboard_isKeyPressed((sfKeySpace)))
        //     global->scene = -1;
    }
}

void step_invetory(global_t *global)
{
    if (global->bubble[0].sec > 17 && global->bubble[0].i == 3) {
        sfSprite_setPosition(global->bubble[0].sprite, (sfVector2f){-5000, -5000});
        sfText_setPosition(global->bubble[0].text3, (sfVector2f){-5000, -5000});
        global->bubble[0].i = 4;
    }
    if (global->bubble[0].i == 4) {
        if (global->bubble[0].sec > 20) {
            sfRenderWindow_drawSprite(global->window, global->speak[0].sprite, NULL);
            sfText_setPosition(global->bubble[0].text4, (sfVector2f){80, 600});
            sfRenderWindow_drawText(global->window, global->bubble[0].text4, NULL);
            if (sfKeyboard_isKeyPressed((sfKeyI))) {
                global->bubble[0].i = 5;
            }
        }
    }
}

void step_attack(global_t *global)
{
    if (global->bubble[0].i == 5) {
        sfRenderWindow_drawSprite(global->window, global->speak[0].sprite, NULL);
        sfText_setPosition(global->bubble[0].text5, (sfVector2f){80, 600});
        sfText_setPosition(global->bubble[0].text4, (sfVector2f){-5000, -5000});
        sfRenderWindow_drawText(global->window, global->bubble[0].text5, NULL);
        if (sfKeyboard_isKeyPressed((sfKeyA))) {
            sfText_setPosition(global->bubble[0].text5, (sfVector2f){-5000, -5000});
            sfSprite_setPosition(global->speak[0].sprite, (sfVector2f){-5000, -5000});
            global->bubble[0].i = 6;
        }
    }
}

void draw_island(global_t *global)
{
    sfVector2f pos = sfSprite_getPosition(global->mentor[0].sprite);
    deplace_in_map(global->window, global, 2);
    sfSprite_setTextureRect(global->island[0].sprite, global->map[2].my_view);
    sfRenderWindow_drawSprite(global->window, global->island[0].sprite, NULL);
    sfRenderWindow_drawSprite(global->window, global->hero[global->hero[0].check_mouv].sprite, NULL);
    sfRenderWindow_drawSprite(global->window, global->map[2].front, NULL);
    anim_mentor(global);
    if (global->map[2].map_txt[global->hero[2].y][global->hero[2].x] == 's') {
        sfRenderWindow_drawSprite(global->window, global->bubble[0].sprite, NULL);
            global->bubble[0].click = 1;
        if (global->bubble[0].click == 1) {
            speak_to_mentor(global);
            speak_of_training(global);
            before_training(global);
        }
    }
    if (global->bubble[0].sec > 17 && global->bubble[0].i == 3) {
        sfSprite_setPosition(global->bubble[0].sprite, (sfVector2f){-5000, -5000});
        sfText_setPosition(global->bubble[0].text3, (sfVector2f){-5000, -5000});
        global->bubble[0].i = 4;
        // sfClock_restart(global->bubble[0].clock);
    }
    if (global->bubble[0].i == 4) {
        if (global->bubble[0].sec > 20) {
            sfRenderWindow_drawSprite(global->window, global->speak[0].sprite, NULL);
            sfText_setPosition(global->bubble[0].text4, (sfVector2f){80, 600});
            sfRenderWindow_drawText(global->window, global->bubble[0].text4, NULL);
            if (sfKeyboard_isKeyPressed((sfKeyI))) {
                global->bubble[0].i = 5;
            }
        }
    }
    if (global->bubble[0].i == 5) {
        sfRenderWindow_drawSprite(global->window, global->speak[0].sprite, NULL);
        sfText_setPosition(global->bubble[0].text5, (sfVector2f){80, 600});
        sfText_setPosition(global->bubble[0].text4, (sfVector2f){-5000, -5000});
        sfRenderWindow_drawText(global->window, global->bubble[0].text5, NULL);
        if (sfKeyboard_isKeyPressed((sfKeyA))) {
            sfText_setPosition(global->bubble[0].text5, (sfVector2f){-5000, -5000});
            sfSprite_setPosition(global->speak[0].sprite, (sfVector2f){-5000, -5000});
            global->bubble[0].i = 6;
        }
    }
    // if (global->bubble[0].i == 6) {
    //     if (sfKeyboard_isKeyPressed((sfKeyA)))
    //         global->bubble[0].i = 7;
    // }
    // if (global->bubble[0].i == 7) {
    //     if (sfKeyboard_isKeyPressed((sfKeyA)))
    //         global->bubble[0].i = 8;
    // }
    if (global->bubble[0].i == 6) {
        sfSprite_setPosition(global->speak[0].sprite, (sfVector2f){0, 200});
        sfRenderWindow_drawSprite(global->window, global->speak[0].sprite, NULL);
        sfRenderWindow_drawText(global->window, global->bubble[0].text6, NULL);
        if (sfKeyboard_isKeyPressed((sfKeySpace))) {
            global->scene = -1;
        }
    }
    step_invetory(global);
    step_attack(global);
    step_to_go(global);
    final_step(global);
    draw_shield(global);
}