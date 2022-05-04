/*
** EPITECH PROJECT, 2021
** my_rpg.h
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/System/Export.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "my.h"
    #include "avatar.h"

typedef struct intro
{
    sfSprite *sprite;
    sfClock *clock;
    float sec;
    int is_done;
} intro_t;

typedef struct speak
{
    sfSprite *sprite_button;
    sfVector2f pos_button;
    sfSprite *sprite;
    sfSprite *hero;
    int check_pos;
} speak_t;

typedef struct house
{
    sfSprite *sprite;
    sfIntRect my_view;
    char **house_txt;
    int x;
    int y;
    int is_open;
    int down;
    int left;
    int up;
    int right;
    sfSprite *enter;
    sfSprite *space;
} house_t;

typedef struct inventory
{
    sfSprite *sprite;
    sfSprite *quit;
    sfIntRect rect_quit;
    sfVector2f pos_quit;
    int is_open;
    sfSprite *ball;
    int is_ball;
    sfSprite *gold_s;
    sfSprite *sword;
    int is_gold;
    int gold_i;
    sfVector2f pos_gold;
    sfVector2f pos_gold_i;
} inventory_t;

typedef struct door
{
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    sfVector2f pos;
    float sec;
} door_t;

typedef struct animate_t
{
    sfSprite *sprite;
    sfIntRect rect;
} animate_t;

typedef struct menu_t
{
    sfSprite *sprite;
} menu_t;

typedef struct mouse_t
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    float sec;
} mouse_t;

typedef struct button_t
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
} button_t;

typedef struct music
{
    sfMusic *music;
} music_t;

typedef struct sound
{
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} sound_t;

typedef struct turret_t
{
    sfSprite *sprite_placement;
    sfSprite *sprite;
    sfSprite *sprite_menu;
    sfSprite *sprite_basement;
    sfIntRect rect_menu;
    sfVector2f pos_menu;
    sfIntRect rect;
    sfIntRect rect_placement;
    sfVector2f pos;
    sfVector2f pos_upgrade;
    sfTexture *texture;
    sfTexture *texture_up1;
    sfTexture *texture_up2;
    int damage;
    int is_menu;
    int is_turret;
    int is_up;
} turret_t;

typedef struct map_t
{
    sfText *temp;
    sfVector2f pos;
    sfVector2f pos_front;
    char **map_txt;
    sfIntRect my_view;
    sfSprite *sprite;
    sfSprite *back;
    sfSprite *front;
} map_t;

typedef struct avatar {
    sfSprite *sprite;
    sfIntRect rect;
    int yes;
} avatar_t;

typedef struct enemy {
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    int pos_x;
    int pos_y;
    float sec;
    int life;
    int stage;
} enemy_t;

typedef struct hero {
    int x;
    int y;
    int down;
    int left;
    int up;
    int right;
    sfVector2f pos;
    sfSprite *sprite;
    sfIntRect rect;
    sfIntRect rect_attack;
    sfClock *clock;
    int check_mouv;
    int check_idle;
    int check_attack;
    float sec;
    int speed;
} hero_t;

typedef struct hitbox_t
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
} hitbox_t;

typedef struct obstacle
{
    sfSprite *name;
    sfVector2f pos;
    int i;
} obstacle_t;

typedef struct text
{
    sfText *txt;
    int score;
    char *txt_str;
    sfSprite *icon;
} text_t;

typedef struct pixel
{
    sfSprite *sprite;
} pixel_t;

typedef struct rain
{
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    float sec;
    sfTime timerain;
    int speedrain;
    sfSprite *spriteblack;
} rain_t;

typedef struct speaker
{
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    float sec;
    int speedspeak;
} speaker_t;

typedef struct panel
{
    sfSprite *sprite;
    sfIntRect rect;
    sfText *text;
} panel_t;

typedef struct lifehero
{
    sfSprite *sprite;
    sfIntRect rect;
    int life;
} life_t;

typedef struct fire
{
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    float sec;
    int speedfire;
} fire_t;

typedef struct box
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int take;
    int yes;
} box_t;

typedef struct toucht
{
    sfSprite *sprite;
    sfIntRect rect;
} toucht_t;

typedef struct tuto
{
    sfText *text;
} tuto_t;

typedef struct island
{
    sfSprite *sprite;
    sfIntRect rect;
    sfSprite *spriteback;
    sfIntRect rectback;
} island_t;

typedef struct mentor
{
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    float sec;
    int speedmentor;
    sfVector2f pos;
} mentor_t;

typedef struct bubble
{
    sfSprite *sprite;
    sfIntRect rect;
    int i;
    int click;
    sfClock *clock;
    float sec;
    int speedmentor;
    sfText *text;
    sfText *text1;
    sfText *text2;
    sfText *text3;
    sfText *text4;
    sfText *text5;
    sfText *text6;
} bubble_t;

typedef struct minispace
{
    sfSprite *sprite;
    sfIntRect rect;
} minispace_t;

typedef struct global
{
    speak_t speak[1];
    hero_t png_crest[2];
    hitbox_t hit_attack[5];
    map_t map[49];
    hero_t hero[12];
    enemy_t enemy[1];
    pixel_t pixel[820];
    sfRenderWindow *window;
    sfEvent event;
    avatar_t avatar[1];
    rain_t rain[1];
    speaker_t speaker[1];
    door_t door[3];
    panel_t panel[1];
    house_t house[3];
    mouse_t cursor;
    life_t life[10];
    fire_t fire[1];
    box_t box[1];
    toucht_t toucht[1];
    int scene;
    int facty;
    inventory_t inventory[1];
    sfVector2f mouse;
    tuto_t tutorial[1];
    island_t island[1];
    intro_t intro[1];
    mentor_t mentor[1];
    bubble_t bubble[1];
    minispace_t minispace[1];
    sfEvent eventbox;
    int tuto;
} global_t;

void init_avatar(global_t *m);
void initialization(void);
int start_game(global_t *global);
void draw(sfRenderWindow *window, global_t *global);
float make_clock(sfClock *clock);
char *open_map(char *str);
sfSprite *make_sprite(char *pathfile);
void move(sfRenderWindow *window, global_t *global, int i);
void attack(sfRenderWindow *window, global_t *global, int i);
void move_sprint(sfRenderWindow *window, global_t *global, int i);
void move_png_crest(sfRenderWindow *window, global_t *global, int i);
sfText *make_text(int x, int y, int size, sfColor color);
void talk_to_png(global_t *global, sfRenderWindow *window);
void choose_avatar(global_t *m);
void deplace_in_map(sfRenderWindow *window, global_t *global, int i);
void init_rain(global_t *m);
void moov_rain(global_t *g);
void init_black(global_t *m);
void init_speaker(global_t *g);
void anim_speaker(global_t *g);
void start_map(sfRenderWindow *window, global_t *global);
void draw_house(sfRenderWindow *window, global_t *global, int i);
void init_poster(global_t *m);
void play_poster(global_t *m);
void init_slime(global_t *global);
void animation_slime(global_t *global);
void init_hitbox_attack(global_t *global);
void slime_pushed_back(global_t *global, int i);
void init_cursor(global_t *global);
void cursor_animation(global_t *global);
void check_hit_slime(global_t *global);
void test_hitbox(global_t *global);
void file_to_struct(global_t *m);
void init_toucht(global_t *m);
void init_fire(global_t *g);
void anim_fire(global_t *g);
void init_box(global_t *m);
void draw_inventory(global_t *global);
void draw_dungeon(global_t *global);
void sokoban(global_t *m);
void draw_life(global_t *m);
void init_life(global_t *m);
void init_rect_fire(global_t *g);
void init_front_map(global_t *global, char *str);
void tuto(global_t *m);
void init_text(sfVector2f position, char *string, sfText *text);
void init_island(global_t *m);
void draw_island(global_t *m);
void slime_hit(global_t *global);
void draw_intro(global_t *global);
void init_intro(global_t *global_t);
void init_mentor(global_t *g);
void init_rect_mentor(global_t *g);
void anim_mentor(global_t *g);
void init_bubble(global_t *m);
void init_minispace(global_t *m);

#endif /* MY_RPG_H_ */