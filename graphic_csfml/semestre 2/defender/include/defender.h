/*
** EPITECH PROJECT, 2021
** defender.h
** File description:
** square
*/

#include "my.h"

typedef struct buildings
{
    sfSprite *s_bui[3];
    sfTexture *t_bui[3];
    char **file;
} buildings_t;

typedef struct place
{
    sfSprite *s_place[2];
    sfTexture *t_place[2];
    char **file;
} place_t;

typedef struct bgtower
{
    sfSprite *s_bgtower[2];
    sfTexture *t_bgtower[2];
    char **file;
} bgtower_t;

typedef struct tower2
{
    sfSprite *s_t2[4];
    sfTexture *t_t2[4];
    char **file;
} tower2_t;

typedef struct tower3
{
    sfSprite *s_t3[4];
    sfTexture *t_t3[4];
    char **file;
} tower3_t;

typedef struct tower1
{
    sfSprite *s_t1[4];
    sfTexture *t_t1[4];
    char **file;
} tower1_t;

typedef struct rect
{
    sfSprite *s_rect[1];
    sfTexture *t_rect[1];
    char **file;
} rect_t;

typedef struct bg
{
    sfSprite *s_bg[1];
    sfTexture *t_bg[1];
    char **file;
} bg_t;

typedef struct bit
{
    sfSprite *s_bit[1];
    sfTexture *t_bit[1];
    char **file;
} bit_t;

typedef struct sizerect
{
    int rectmax;
} sizerect_t;

typedef struct pause
{
    sfSprite *s_pause[1];
    sfTexture *t_pause[1];
    char **file;
} pause_t;

typedef struct heart
{
    sfSprite *s_heart[1];
    sfTexture *t_heart[1];
    char **file;
} heart_t;

typedef struct minis1
{
    sfSprite *s_minis1[1];
    sfTexture *t_minis1[1];
    char **file;
} minis1_t;

typedef struct menu
{
    sfSprite *s_men[1];
    sfTexture *t_men[1];
    char **file;
} menu_t;

typedef struct ennemis
{
    sfSprite *s_enemis[6];
    sfTexture *t_enemis[6];
    char **file;
} ennemis_t;

typedef struct global
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    ennemis_t *ennemi;
    bg_t *bg;
    heart_t *heart;
    tower2_t *tower2;
    bgtower_t *bgtower;
    minis1_t *minis1;
    place_t *place;
    buildings_t *tower;
    tower1_t *towere1;
    tower3_t *tower3;
    rect_t *rect;
    bit_t *bit;
    float secondennemi;
    sfTime timennemi;
    sfClock *clockennemi;
    float secondskin;
    sfClock *clockskin;
    sfTime timeskin;
    float secondmoov;
    sfClock *clockmoov;
    sfTime timemoov;
    float secondskin2;
    sfClock *clockskin2;
    sfTime timeskin2;
    float secondmoov2;
    sfClock *clockmoov2;
    sfTime timemoov2;
    sfIntRect rectennemis;
    sfIntRect rectennemis2;
    sfIntRect tower1;
    sfIntRect rectower2;
    sfIntRect rectower3;
    float secondrect;
    sfClock *clockrect;
    sfTime timerect;
    pause_t *pause;
    int speed;
    int speed2;
    int speedy;
    int hight;
    int space;
    int a;
    int z;
    int newtower1;
    int menu;
    int firstplace;
    int secondplace;
    int j;
    int score_bit;
    int life_en1;
    int life_en2;
    int toucht2;
    int lify;
    sfText *textmini1;
    sfText *text;
    sfText *textheart;
    sfText *textmoney;
    int ist1;
    int ist2;
    int level;
    int life_game;
    int dispmoney;
    int lifeno;
    int toucht3;
    int isenem2;
    int tkt;

} global_t;

int my_strlen(char const *str);
char **str_to_word_array(char *chaine);
void my_putstr(char *str);
void game_rules(void);
int char_to_int(char *string1);
void print_sprite1(global_t *m);
void moov_ennemis(global_t *m);
void moov_rect(global_t *m);
void print_sprite2(global_t *m);
void moov_ennemis2(global_t *m);
void send_waves(global_t *m);
void print_pause(global_t *m);
void init_rect_sprite2(global_t *m);
void play(global_t *m);
void print_tower(global_t *m);
void pause_main(global_t *m);
int main(int ac, char **av);
void game_loop(global_t *m);
void create_and_place_t1(global_t *m);
bg_t *sprite_bg(void);
global_t init_global(global_t m);
void init_the_game(void);
void init_rect_sprite1(global_t *m);
buildings_t *sprite_buildings(void);
void display_menu_tower(global_t *m);
void mouse_menu(global_t *m);
void menu(global_t *m);
void mouse_tower(global_t *m);
void mouse_tower1_select(global_t *m);
ennemis_t *sprite_ennemi(void);
int game_pause(global_t *m, int space);
int key_pause(global_t *m);
void print_place(global_t *m);
void create_and_place_t1(global_t *m);
void emplace_tower(global_t *m);
bgtower_t *sprite_bg_tower(void);
place_t *sprite_place(void);
void ennemi_wave(global_t *m);
int my_strlen(char const *str);
void my_putstr(char *str);
tower1_t *sprite_t1(global_t *t);
tower2_t *sprite_t2(global_t *t);
void mouse_tower2_select(global_t *m);
bit_t *sprite_bit(global_t *m);
int str_to_int(char *string1);
sfText* init_score(global_t *m);
rect_t *sprite_rect(global_t *t);
void zone_sprite_touch(global_t *m);
heart_t *sprite_heart(void);
sfText* init_heart(global_t *m);
sfText* init_money(global_t *m);
sfText* init_minitext(global_t *m);
minis1_t *sprite_mini1(global_t *m);
void mouse_tower3_select(global_t *m);
tower3_t *sprite_t3(global_t *t);