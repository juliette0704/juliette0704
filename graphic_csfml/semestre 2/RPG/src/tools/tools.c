/*
** EPITECH PROJECT, 2022
** tools
** File description:
** my_defender
*/

#include "my_rpg.h"

sfText *make_text(int x, int y, int size, sfColor color)
{
    sfVector2f pos_text = {x, y};
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("font/Pixelletters.ttf");
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    sfText_setPosition(text, pos_text);
    return text;
}

float make_clock(sfClock *clock)
{
    sfTime time;
    float sec;
    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / 1000000.0;
    return sec;
}

char *open_map(char *str)
{
    int size = 20000000;
    int fd = open(str, O_RDONLY);
    char *map = malloc(size + 1);
    int nb = read(fd, map, size);
    map[nb] = '\0';
    close(fd);
    return map;
}

sfSprite *make_sprite(char *pathfile)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(pathfile, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
