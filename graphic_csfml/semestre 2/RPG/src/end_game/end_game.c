/*
** EPITECH PROJECT, 2022
** end_game
** File description:
** my_rpg
*/

#include "my_rpg.h"

void free_map(global_t *global)
{
    for (int i = 0; i < 5; i++) {
        if (i != 2) {
            sfSprite_destroy(global->map[i].sprite);
            sfSprite_destroy(global->map[i].front);
        }
    }
    sfSprite_destroy(global->map[0].good_job);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; global->map[i].map_txt[j] != NULL; j++)
            free(global->map[i].map_txt[j]);
        free(global->map[i].map_txt);
    }
    sfSprite_destroy(global->map[0].back);
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(global->house[i].sprite);
        for (int j = 0; global->house[i].house_txt[j] != NULL; j++)
            free(global->house[i].house_txt[j]);
        free(global->house[i].house_txt);
    }
    return;
}

void end_game(global_t *global)
{
    sfRenderWindow_close(global->window);
    sfSprite_destroy(global->pause_menu[0].sprite);
    sfSprite_destroy(global->pause_menu[0].resume);
    sfSprite_destroy(global->pause_menu[0].quit);
    sfSprite_destroy(global->pause_menu[0].option);
    sfSprite_destroy(global->intro[0].sprite);
    sfSprite_destroy(global->speak[0].sprite);
    sfSprite_destroy(global->speak[0].sprite_button);
    sfSprite_destroy(global->speak[0].hero);
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(global->button_play[i].sprite);
        sfSprite_destroy(global->button_tuto[i].sprite);
        sfSprite_destroy(global->button_quit[i].sprite);
        sfTexture_destroy(global->button_quit[i].texture);
        sfTexture_destroy(global->button_tuto[i].texture);
        sfTexture_destroy(global->button_play[i].texture);
    }
    for (int i = 0; i < 10; i++) {
        sfSprite_destroy(global->bird[i].sprite);
        sfTexture_destroy(global->bird[i].texture);
    }
    sfSprite_destroy(global->font_blue.sprite);
    sfTexture_destroy(global->font_blue.texture);
    sfMusic_destroy(global->music[0].music);
    for (int i = 0; i < 4; i++) {
        sfSound_destroy(global->sound[i].sound);
        sfSoundBuffer_destroy(global->sound[i].sound_buffer);
    }
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(global->mountains[i].sprite);
        sfTexture_destroy(global->mountains[i].texture);
        sfSprite_destroy(global->big_cloud[i].sprite);
        sfTexture_destroy(global->big_cloud[i].texture);
        sfSprite_destroy(global->fine_cloud[i].sprite);
        sfTexture_destroy(global->fine_cloud[i].texture);
        sfSprite_destroy(global->multiple_clouds[i].sprite);
        sfTexture_destroy(global->multiple_clouds[i].texture);
        sfSprite_destroy(global->front_clouds[i].sprite);
        sfTexture_destroy(global->front_clouds[i].texture);
    }
    sfSprite_destroy(global->behind_cloud.sprite);
    sfTexture_destroy(global->behind_cloud.texture);
    sfSprite_destroy(global->title.sprite);
    sfTexture_destroy(global->title.texture);
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(global->shield[i].sprite);
    sfClock_destroy(global->shield[0].clock_cd);
    sfClock_destroy(global->shield[0].clock);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(global->png_crest[i].sprite);
    sfClock_destroy(global->png_crest[0].clock);
    for (int i = 0; i < 5; i++)
        sfSprite_destroy(global->hit_attack[i].sprite);
    free_map(global);
    for (int i = 0; i < 12; i++)
        sfSprite_destroy(global->hero[i].sprite);
    sfClock_destroy(global->hero[0].clock);
    for (int i = 0; i < 5; i++) {
        sfSprite_destroy(global->enemy[i].sprite);
        sfSprite_destroy(global->enemy[i].sprite_d);
        sfClock_destroy(global->enemy[i].clock);
    }
    sfSprite_destroy(global->boss.sprite);
    sfClock_destroy(global->boss.clock);
    global->my_exit = 1;
    sfSprite_destroy(global->rain[0].sprite);
    sfSprite_destroy(global->rain[0].spriteblack);
    sfClock_destroy(global->rain[0].clock);
    sfSprite_destroy(global->speaker[0].sprite);
    sfClock_destroy(global->speaker[0].clock);
    for (int i = 0; i < 3; i++)
            sfSprite_destroy(global->door[i].sprite);
    sfClock_destroy(global->door[0].clock);
    sfSprite_destroy(global->panel[0].sprite);
    sfText_destroy(global->panel[0].text);
    sfSprite_destroy(global->house[0].space);
    sfSprite_destroy(global->house[0].enter);
    for (int i = 0; i < 10; i++)
        sfSprite_destroy(global->life[i].sprite);
    sfClock_destroy(global->fire[0].clock);
    sfSprite_destroy(global->fire[0].sprite);
    sfClock_destroy(global->fire[0].clock_f);
    sfSprite_destroy(global->fire[0].sprite_r);
    sfSprite_destroy(global->box[0].sprite);
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(global->hit_boss[i].sprite);
    sfText_destroy(global->hit_boss[0].life);
    sfSprite_destroy(global->toucht[0].sprite);
    sfSprite_destroy(global->inventory[0].sprite);
    sfSprite_destroy(global->inventory[0].quit);
    sfSprite_destroy(global->inventory[0].gold_s);
    sfSprite_destroy(global->inventory[0].sword);
    sfSprite_destroy(global->island[0].sprite);
    sfClock_destroy(global->intro[0].clock);
    sfSprite_destroy(global->mentor[0].sprite);
    sfClock_destroy(global->mentor[0].clock);
    sfSprite_destroy(global->bubble[0].sprite);
    sfClock_destroy(global->bubble[0].clock);
    sfText_destroy(global->bubble[0].text);
    sfText_destroy(global->bubble[0].text1);
    sfText_destroy(global->bubble[0].text2);
    sfText_destroy(global->bubble[0].text3);
    sfText_destroy(global->bubble[0].text4);
    sfText_destroy(global->bubble[0].text5);
    sfText_destroy(global->bubble[0].text6);
    sfText_destroy(global->bubble[0].text7);
    sfSprite_destroy(global->minispace[0].sprite);
    sfSprite_destroy(global->light[0].sprite);
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(global->labydoor[i].sprite);
    sfClock_destroy(global->labydoor[0].clock);
    for (int i = 0; i < 10; i++)
        sfSprite_destroy(global->particle[i].sprite);
    for (int i = 0; i < 2; i++)
        sfSprite_destroy(global->potion[i].sprite);
    sfClock_destroy(global->clock_menu);
    sfClock_destroy(global->clock_bird);
    return;
}
