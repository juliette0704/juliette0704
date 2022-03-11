/*
** EPITECH PROJECT, 2022
** score
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

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

sfText* init_money(global_t *m)
{
    char *string = "NO ENOUGHT MONEY!!!";
    sfFont *font = sfFont_createFromFile("leadcoat.ttf");
    sfText_setString(m->textmoney, string);
    sfText_setFont(m->textmoney, font);
    sfText_setColor(m->textmoney, sfBlack);
    sfText_setCharacterSize(m->textmoney, 160);
    sfText_setPosition(m->textmoney, (sfVector2f){338, 348});
    return m->textmoney;
}

sfText* init_score(global_t *m)
{
    char *string = itoa(m->score_bit);
    sfFont *font = sfFont_createFromFile("leadcoat.ttf");
    sfText_setString(m->text, string);
    sfText_setFont(m->text, font);
    sfText_setColor(m->text, sfBlack);
    sfText_setCharacterSize(m->text, 50);
    sfText_setPosition(m->text, (sfVector2f){138, 48});
    return m->text;
}

heart_t *sprite_heart(void)
{
    heart_t *m = malloc(sizeof(heart_t));
    char *file[] = {"./life/heart.png"};
    m->file = file;
    m->s_heart[0] = sfSprite_create();
    m->t_heart[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(m->s_heart[0], m->t_heart[0], sfTrue);
    sfSprite_setPosition(m->s_heart[0], (sfVector2f){50, 90});
    return m;
}

sfText* init_heart(global_t *m)
{
    char *string = itoa(m->life_game);
    sfFont *font = sfFont_createFromFile("leadcoat.ttf");
    sfText_setString(m->textheart, string);
    sfText_setFont(m->textheart, font);
    sfText_setColor(m->textheart, sfBlack);
    sfText_setCharacterSize(m->textheart, 50);
    sfText_setPosition(m->textheart, (sfVector2f){138, 110});
    return m->textheart;
}

sfText* init_minitext(global_t *m)
{
    char *string = itoa(m->life_en1);
    sfFont *font = sfFont_createFromFile("leadcoat.ttf");
    sfText_setString(m->textmini1, string);
    sfText_setFont(m->textmini1, font);
    sfText_setColor(m->textmini1, sfBlack);
    sfText_setCharacterSize(m->textmini1, 50);
    sfText_setPosition(m->textmini1, (sfVector2f){148, 176});
    return m->textmini1;
}