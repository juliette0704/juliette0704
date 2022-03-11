/*
** EPITECH PROJECT, 2021
** ground.c
** File description:
** ground
*/

#include "my.h"
#include "struct.h"

void jumpe(globale_t *m, speed_t *speed, jump_t *jumping)
{
    sfVector2f pos = sfSprite_getPosition(m->ninja->s_nin[0]);
    int fuck = 0;
    moov_rect_jump(m, speed);
    if (pos.y > 620 && jumping->x != 4) {
        pos.y -= 5 - m->i;
        jumping->x = 1;
    }
    if (pos.y <= 620 && jumping->x != 4) {
        jumping->x = 2;
    }
    if (jumping->x != 1) {
        pos.y += 5 - m->vec;
        m->vec--;
        jumping->x = 4;
    }
    if (jumping->x == 4 && pos.y > 814) {
        pos.y = 815;
        m->i = 1;
    }
    sfSprite_setPosition(m->ninja->s_nin[0], pos);
}

void moov_sprite(globale_t *m, speed_t *speed, jump_t *jumping)
{
    int top = 0;
    if (m->event.type == sfEvtKeyReleased && m->event.key.code == sfKeySpace) {
        m->i == 2;
        init_rect_jump(m, speed);
        jumpe(m, speed, jumping);
    }
}

int moov_rect(globale_t *all, speed_t *speed)
{
    all->rectninja = (sfIntRect){0, 0, 125, 165};
    all->rectninja.left = speed->speedo;
    sfSprite_setTextureRect(all->ninja->s_nin[0], all->rectninja);
}

int init_rect(globale_t *all, speed_t *speed)
{
    all->time = sfClock_getElapsedTime(all->clock);
    all->second = all->time.microseconds / 1000000.0;
    if (all->second > 0.09) {
        moov_rect(all, speed);
        sfClock_restart(all->clock);
        if (speed->speedo >= 500) {
            speed->speedo = 125;
        } else {
            speed->speedo += 125;
        }
    }
    return speed->speedo;
}