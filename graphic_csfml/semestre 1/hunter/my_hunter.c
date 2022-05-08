/*
** EPITECH PROJECT, 2021
** my_hunter.c
** File description:
** my
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <SFML/System.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

void openwindow(sfRenderWindow *window);
sfSprite *sprite(sfRenderWindow *window);
void end_of_page(sfVector2f pos, sfSprite *s);

typedef struct life life;
struct life
{
    int nblife;
};

char *itoa( int digits)
{
    int len;
    char *str;
    int temp;

    temp = digits;
    len = 0;
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = digits % 10 + '0';
        digits /= 10;
    }
    return str;
}

void cursore(sfVector2i pos1, sfSprite *cursor, sfRenderWindow *Window)
{
    sfBool show;
    sfRenderWindow_setMouseCursorVisible(Window, sfFalse);
    sfVector2f pos = {pos1.x - 30, pos1.y - 30};
    sfSprite_setPosition(cursor, pos);
}

sfText* init_score(sfText *text, sfVector2f position, int score)
{
    char *string = itoa(score);
    sfFont *font = sfFont_createFromFile("arial.ttf");
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    sfText_setCharacterSize(text, 70);
    sfText_setPosition(text, position);
    return text;
}

void end_of_page(sfVector2f pos, sfSprite *s)
{
    int lower = 1, upper = 863, count = 10;
    pos.y = (rand() % (upper - lower + 1)) + lower;
    pos.x = 0;
    sfSprite_setPosition(s, pos);
}

int touch_christmas(sfRenderWindow *window, float x, float y, sfSprite *cursor, sfSprite *s, sfVector2f pos, int score)
{
    sfMouseButton boutton = sfMouseLeft;
    int touch = 0;
    sfVector2i pos1;
    pos1 = sfMouse_getPositionRenderWindow(window);
    cursore(pos1, cursor, window);
    if (sfMouse_isButtonPressed(boutton)) {
        if ((pos1.x < pos.x + 200 && pos1.x >= pos.x) && (pos1.y < pos.y + 210 && pos1.y >= pos.y)) {
            end_of_page(pos, s);
            score++;
        }
    }
    return score;
}

sfSprite *init_sprite(char *path)
{
    sfTexture* texture;
    sfSprite* sprite;
    texture = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void move_rect(sfSprite *s, int x)
{
    sfIntRect textureRect = {0, 0, 200, 210};
    textureRect.left = x;
    sfSprite_setTextureRect(s, textureRect);
}

int moveSprite(sfSprite *s, sfRenderWindow *window, sfSprite *cursor, int score)
{
    int posx = 0, posy = 0;
    float moovx = 45;
    float moovy = 0;
    sfVector2f pos = {posx, posy};
    sfSprite_move(s, (sfVector2f){moovx, moovy});
    pos = sfSprite_getPosition(s);
    score = touch_christmas(window, moovx, moovy, cursor, s, pos, score);
    if (pos.x == 1800) {
        end_of_page(pos, s);
    }
    return score;
}

void openwindow(sfRenderWindow *window)
{
    sfText *text = sfText_create();
    sfVector2i position = {40, 50};
    int x = 200;
    srand(time(0));
    int random = rand();
    sfSprite *deadnoel = init_sprite("pernoeldead.png");
    sfSprite *bonhommeneige = init_sprite("bonhommeneige.png");
    sfSprite *background = init_sprite("fond4.png");
    sfSprite *s = init_sprite("noeldetoure.png");
    sfSprite *cursor = init_sprite("cadeau1.png");
    sfEvent event;
    sfVideoMode mode = {1920, 1065, 60};
    sfClock *myclocknoel = sfClock_create();
    sfClock *rectclock = sfClock_create();
    sfTime time;
    sfTime recttime;
    int scorelife = 0;
    int aie = 0, score = 0;
    float second;
    float recsecond;
    window = sfRenderWindow_create(mode, "Happy Christmas", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        time = sfClock_getElapsedTime(myclocknoel);
        second = time.microseconds / 1000000.0;
        recttime = sfClock_getElapsedTime(rectclock);
        recsecond = recttime.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) sfRenderWindow_close(window);
        }
        position = sfMouse_getPositionRenderWindow(window);
        cursore(position, cursor, window);
        if (second > 0.11) {
            score = moveSprite(s, window, cursor, score);
            sfClock_restart(myclocknoel);
        }
        if (recsecond > 0.09) {
            move_rect(s, x);
            sfClock_restart(rectclock);
            if (x >= 1000) x = 216;
                else x = x + 216;
        }
        init_score(text, (sfVector2f){1800, 970}, score);
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawSprite(window, s, NULL);
        sfRenderWindow_drawSprite(window, bonhommeneige, NULL);
        sfRenderWindow_drawSprite(window, cursor, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
}

int main(int ac, char **av)
{
    if (ac == 1) {
        sfRenderWindow *window;
        openwindow(window);
    }
}
