/*
** EPITECH PROJECT, 2021
** initialization
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_door_animation(global_t *global)
{
    sfVector2f pos[] = {{2544, 1943}, {3297, 1900}};
    sfVector2f scale = {1.4, 1.4};
    sfIntRect rect = {0, 0, 49, 52};
    global->door[0].sprite = make_sprite("sprite/map/mom_door.png");
    global->door[1].sprite = make_sprite("sprite/map/classic_door.png");
    for (int i = 0; i < 2; i++) {
        global->door[i].rect = rect;
        global->door[i].pos = pos[i];
        sfSprite_setScale(global->door[i].sprite, scale);
        sfSprite_setTextureRect(global->door[i].sprite, rect);
        sfSprite_setPosition(global->door[i].sprite, pos[i]);
    }
    float sec;
    sfClock *clock;
    global->door[0].sec = sec;
    global->door[0].clock = clock;
    global->door[0].clock = sfClock_create();
    return;
}

void init_talk_to_png(global_t *global)
{
    global->speak[0].sprite_button = make_sprite("sprite/speak/space.png");
    global->speak[0].sprite = make_sprite("sprite/speak/speak_rect.png");
    global->speak[0].hero = make_sprite("sprite/speak/speak_hero.png");
    sfVector2f pos_rect = {0, -50};
    sfVector2f pos_button = {390 * 2.3, 160 * 2.3};
    global->speak[0].check_pos = 0;
    global->speak[0].pos_button = pos_button;
    sfSprite_setPosition(global->speak[0].sprite, pos_rect);
    sfSprite_setPosition(global->speak[0].sprite_button, pos_button);
    return;
}

void init_png_crest(global_t *global)
{
    float sec;
    sfClock *clock;
    global->png_crest[0].sec = sec;
    global->png_crest[0].clock = clock;
    global->png_crest[0].clock = sfClock_create();
    sfIntRect rect = {2, 0, 48, 48};
    global->png_crest[0].rect = rect;
    sfVector2f scale = {2.3, 2.3};
    sfVector2f pos = {1725 * 2.3, 675 * 2.3};
    global->png_crest[0].pos = pos;
    global->png_crest[0].sprite = make_sprite("sprite/png/png_crest_idle.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setTextureRect(global->png_crest[i].sprite, rect);
        sfSprite_setScale(global->png_crest[i].sprite, scale);
        sfSprite_setPosition(global->png_crest[i].sprite, pos);
    }
    return;
}

void init_hero(global_t *global)
{
    global->hero[0].check_mouv = 0;
    global->hero[0].check_idle = 0;
    global->hero[0].check_attack = 0;
    global->hero[0].sprite = make_sprite("sprite/hero/idle_down.png");
    global->hero[1].sprite = make_sprite("sprite/hero/idle_up.png");
    global->hero[2].sprite = make_sprite("sprite/hero/idle_left.png");
    global->hero[3].sprite = make_sprite("sprite/hero/idle_right.png");
    global->hero[4].sprite = make_sprite("sprite/hero/mouv_down.png");
    global->hero[5].sprite = make_sprite("sprite/hero/mouv_up.png");
    global->hero[6].sprite = make_sprite("sprite/hero/mouv_left.png");
    global->hero[7].sprite = make_sprite("sprite/hero/mouv_right.png");
    global->hero[8].sprite = make_sprite("sprite/hero/attack_down.png");
    global->hero[9].sprite = make_sprite("sprite/hero/attack_up.png");
    global->hero[10].sprite = make_sprite("sprite/hero/attack_left.png");
    global->hero[11].sprite = make_sprite("sprite/hero/attack_right.png");

    sfIntRect rect = {0, 0, 48, 48};
    sfIntRect rect_attack = {0, 0, 144, 144};
    global->hero[0].rect = rect;
    global->hero[0].rect_attack = rect_attack;
    sfVector2f scale = {2.3, 2.3};
    sfVector2f pos = {960, 540};
    sfVector2f pos_attack = {850, 430};

    global->hero[0].x = 1;
    global->hero[0].y = 1;
    global->hero[0].down = 0;
    global->hero[0].up = 0;
    global->hero[0].left = 0;
    global->hero[0].right = 0;
    global->hero[0].speed = 0;

    //sfVector2f pos = {0, 0};
    for (int i = 0; i < 8; i++) {
        sfSprite_setTextureRect(global->hero[i].sprite, rect);
        sfSprite_setScale(global->hero[i].sprite, scale);
        sfSprite_setPosition(global->hero[i].sprite, pos);
    }
    for (int i = 8; i < 12; i++) {
        sfSprite_setTextureRect(global->hero[i].sprite, rect_attack);
        sfSprite_setScale(global->hero[i].sprite, scale);
        sfSprite_setPosition(global->hero[i].sprite, pos_attack);
    }
    global->hero[0].pos = pos;
    float sec;
    sfClock *clock;
    global->hero[0].sec = sec;
    global->hero[0].clock = clock;
    global->hero[0].clock = sfClock_create();
    global->hero[1].sec = sec;
    global->hero[1].clock = clock;
    global->hero[1].clock = sfClock_create();
    return;
}

void init_house(global_t *global)
{
    sfVector2f scale = {2, 2};
    global->house[0].sprite = make_sprite("sprite/house/mom_house.png");
    global->house[0].house_txt = my_str_to_word_array(open_map("parsing/mom_house"), '\n');
    global->house[1].sprite = make_sprite("sprite/house/hospital.png");
    global->house[1].house_txt = my_str_to_word_array(open_map("parsing/hospital"), '\n');
    sfSprite_setScale(global->house[0].sprite, scale);
    sfSprite_setScale(global->house[1].sprite, scale);
    sfIntRect m_view = {660, 650, 960, 540}; //470 left + 400 right // 270 up
    for (int i = 0; i < 2; i++) {
        global->house[i].my_view = m_view;
        global->house[i].y = 30;
        global->house[i].x = 30;
        global->house[i].is_open = 0;
        global->house[i].down = 0;
        global->house[i].up = 0;
        global->house[i].left = 0;
        global->house[i].right = 0;
    }
    sfSprite_setTextureRect(global->house[0].sprite, global->house[0].my_view);
    sfSprite_setTextureRect(global->house[1].sprite, global->house[1].my_view);
    global->house[0].space = make_sprite("sprite/speak/space.png");
    global->house[0].enter = make_sprite("sprite/house/enter.png");
    sfSprite_setScale(global->house[0].space, scale);
    sfSprite_setScale(global->house[0].enter, scale);
    sfVector2f center = {800, 200};
    sfSprite_setPosition(global->house[0].enter, center);
    sfSprite_setPosition(global->house[0].space, center);
    return;
}

void init_map(global_t *global)
{
    sfIntRect m_view = {0, 0, 960, 540};
    sfVector2f scale = {2, 2};
    sfVector2f scale_2 = {1.4, 1.4};
    global->map[0].my_view = m_view;
    char *map = open_map("parsing/start_map");
    global->map[0].sprite = make_sprite("sprite/map/map.png");
    global->map[0].back = make_sprite("sprite/map/front.png");
    global->map[0].front = make_sprite("sprite/map/back.png");
    sfVector2f pos_front = {400 * 2, 250 * 2};
    global->map[0].pos_front = pos_front;
    sfSprite_setScale(global->map[0].front, scale_2);
    sfSprite_setScale(global->map[0].back, scale_2);
    sfSprite_setPosition(global->map[0].front, global->map[0].pos_front);
    sfSprite_setPosition(global->map[0].back, global->map[0].pos_front);
    global->map[0].map_txt = my_str_to_word_array(map, '\n');
    int cont_m = 220 * 2.3;
    for (int i = 0; global->map[0].map_txt[i] != NULL; i++) {
        sfVector2f pos = {450 * 2.3, cont_m};
        global->map[i].pos = pos;
        global->map[i].temp = make_text(450 * 2.3, cont_m, 100, sfWhite);
        sfText_setString(global->map[i].temp, global->map[0].map_txt[i]);
        cont_m += 45;
    }
    int cont = 0;
    sfSprite_setScale(global->map[0].sprite, scale);
    return;
}

void initialization(void)
{
    global_t *global = malloc(sizeof(global_t));
    sfVideoMode mode = {1920, 1080, 32};
    global->window = sfRenderWindow_create(mode, "SFML window",
    sfResize | sfClose, NULL);
    global->scene = 0;
    file_to_struct(global);
    init_life(global);
    init_house(global);
    init_speaker(global);
    init_rain(global);
    init_avatar(global);
    init_map(global);
    init_poster(global);
    init_hero(global);
    init_door_animation(global);
    init_png_crest(global);
    init_slime(global);
    init_talk_to_png(global);
    init_hitbox_attack(global);
    init_cursor(global);
    start_game(global);
    return;
}
