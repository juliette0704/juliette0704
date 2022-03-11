/*
** EPITECH PROJECT, 2021
** my_runner.c
** File description:
** main
*/

#include "my.h"
#include "struct.h"

bg_t *sprite_bg(void)
{
    bg_t *m = malloc(sizeof(*m));
    char *file[] = {"./Sprite/Island/Layers/L1.png"
                , "./Sprite/Island/Layers/L2.png"
                , "./Sprite/Island/Layers/L3.png"
                , "./Sprite/Island/Layers/L4.png"
                , "./Sprite/Island/Layers/L5.png"};
    m->file = file;
    for (int i = 0, j = 0 ; i != 10 ; i++) {
        m->s_bg[i] = sfSprite_create();
        m->t_bg[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_bg[i], m->t_bg[j], sfTrue);
        if ((i + 1) % 2 == 0) {
            j++;
            sfSprite_setPosition(m->s_bg[i], (sfVector2f){1920, 0});
        }
    }
    return m;
}

ninja_t *sprite_ninja(void)
{
    ninja_t *all = malloc(sizeof(*all));
    char *file[] = {"./Sprite/ninja3.png"};
    all->file = file;
    all->s_nin[0] = sfSprite_create();
    all->t_nin[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(all->s_nin[0], all->t_nin[0], sfTrue);
    sfSprite_setPosition(all->s_nin[0], (sfVector2f){50, 825});
    return all;
}

void move(sfSprite *s, float speed)
{
    sfVector2f pos = sfSprite_getPosition(s);

    pos.x += speed;
    if (pos.x < -1920)
        pos.x = 1910;
    sfSprite_setPosition(s, pos);
}

void print_sprite(globale_t *m, speed_t *v, score_t *s)
{
    float speedbg = -6;
    m->timebg = sfClock_getElapsedTime(m->clockbg);
    m->secondbg = m->timebg.microseconds / 1000000.0;
    if (m->secondbg > 0.09) {
        for (int i = 0 ; i != 10 ; i++) {
            sfRenderWindow_drawSprite(m->window, m->bg->s_bg[i], NULL);
            move(m->bg->s_bg[i], speedbg);
            if ((i + 1) % 2 == 0)
                speedbg -= 0.5;
        }
    }
    init_rect(m, v);
    sfRenderWindow_drawSprite(m->window, m->ninja->s_nin[0], NULL);
    if (s->scores == 500)
        sfRenderWindow_drawSprite(m->window, m->vic->s_vic[0], NULL);
}

globale_t init(globale_t m)
{
    m.j = 0;
    m.vec = 0;
    m.vic = sprite_victory(&m);
    m.clock = sfClock_create();
    m.clockjump = sfClock_create();
    m.clockbg = sfClock_create();
    m.mode = (sfVideoMode){1920, 1080, 60};
    m.window = sfRenderWindow_create(m.mode, "Run", sfResize | sfClose, NULL);
    m.bg = sprite_bg();
    m.menu = 0;
    m.ninja = sprite_ninja();
    m.turtle = sprite_turtle(&m);
    return m;
}
