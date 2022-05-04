/*
** EPITECH PROJECT, 2021
** init_bubble_speak.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_bubble(global_t *m)
{
    m->bubble[0].clock = sfClock_create();
    sfVector2f pos = {900,65};
    m->bubble[0].sprite = make_sprite("sprite/speak/bubble.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setPosition(m->bubble[i].sprite, pos);
    }
    m->bubble[0].i = 0;
    m->bubble[0].text = sfText_create();
    m->bubble[0].text1 = sfText_create();
    m->bubble[0].text2 = sfText_create();
    m->bubble[0].text3 = sfText_create();
    m->bubble[0].text4 = sfText_create();
    m->bubble[0].text5 = sfText_create();
    m->bubble[0].text6 = sfText_create();
    m->bubble[0].click = 0;
    char *test = "Hello! my name is:\nTONYNOUCRAFT";
    char *text1 = "Our planet is invaded\nthis is why we call you";
    char *text2 = "Will you fight for us?\n[YES]    [NO]";
    char *text3 = "Super! You can go I will\n call you for training!";
    char *text4 = "So, first you can check your inventory with Key [i], try it!";
    char *text5 = "Good job! Now you can try to press the key [a], it will be very usefull to\nkill the naughty slime";
    char *text6 = "MMhhhh... I think You are ready...! When you think it too, you can press key\n[space] to go in our poor planet";
    init_text((sfVector2f){980, 100}, test, m->bubble[0].text);
    init_text((sfVector2f){980, 100}, text1, m->bubble[0].text1);
    init_text((sfVector2f){980, 100}, text2, m->bubble[0].text2);
    init_text((sfVector2f){980, 100}, text3, m->bubble[0].text3);
    init_text((sfVector2f){980, 100}, text4, m->bubble[0].text4);
    init_text((sfVector2f){980, 100}, text5, m->bubble[0].text5);
    init_text((sfVector2f){72, 800}, text6, m->bubble[0].text6);
    return;
}