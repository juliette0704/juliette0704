/*
** EPITECH PROJECT, 2021
** running.c
** File description:
** run
*/

#include "my.h"
#include "struct.h"

void turtle_comming(globale_t *m)
{
    int posx = 0, posy = 0;
    float moovx = -10;
    sfVector2f pos = {posx, posy};
    sfSprite_move(m->turtle->s_turtle[0], (sfVector2f){moovx, 0});
    pos = sfSprite_getPosition(m->turtle->s_turtle[0]);
}


turtle_t *sprite_turtle(globale_t *m)
{
    turtle_t *turt = malloc(sizeof(*turt));
    for (int i = 0; i != 20 ; i++) {
        char *file[] = {"./turtle.png"};
        turt->file = file;
    }
    for (int i = 0; i != 20 ; i++) {
        turt->s_turtle[i] = sfSprite_create();
        turt->t_turtle[i] = sfTexture_createFromFile("./turtle.png", NULL);
        sfSprite_setTexture(turt->s_turtle[i], turt->t_turtle[i], sfTrue);
        sfSprite_setPosition(turt->s_turtle[i], (sfVector2f){1920, 765});
    }
    return turt;
}

void analyse_map(char *map, globale_t *m)
{
    if (map[m->j] == '.') {
        m->j++;
    } else if (map[m->j] == 'o') {
        turtle_comming(m);
        sfRenderWindow_drawSprite(m->window, m->turtle->s_turtle[0], NULL);
    }
}

int read_pos(int ac, char *av, globale_t *m)
{
    int n = 1;
    char max[1000];
    int fd = 0;
    fd = open(av, O_RDONLY);
    if (fd == -1  && av[1] != 'i') {
        write(2, "ERROR", 5);
        return 84;
    }
    n = read(fd, max, 1000);
    analyse_map(max, m);
    return 0;
}

int moov_rect_jump(globale_t *all, speed_t *speed)
{
    all->rectjump = (sfIntRect){0, 155, 120, 180};
    all->rectjump.left = speed->speedjump;
    sfSprite_setTextureRect(all->ninja->s_nin[0], all->rectjump);
    sfRenderWindow_drawSprite(all->window, all->ninja->s_nin[0], NULL);
}
