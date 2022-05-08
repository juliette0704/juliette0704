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

typedef struct button_play {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} button_play_t;

typedef struct button_quit {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} button_quit_t;

typedef struct button_tuto {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
} button_tuto_t;

typedef struct bird {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    int haste;
} bird_t;

typedef struct font_blue {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
} font_blue_t;

typedef struct mountains {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
} mountains_t;

typedef struct behind_cloud {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
} behind_cloud_t;

typedef struct big_cloud {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
} big_cloud_t;

typedef struct fine_cloud {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
} fine_cloud_t;

typedef struct multiple_clouds {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
} multiple_clouds_t;

typedef struct front_clouds {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
} front_clouds_t;

typedef struct title {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
} title_t;

typedef struct pause_menu
{
    sfSprite *sprite;
    sfSprite *resume;
    sfVector2f pos_resume;
    sfIntRect rect_resume;
    sfSprite *option;
    sfVector2f pos_option;
    sfIntRect rect_option;
    sfSprite *quit;
    sfVector2f pos_quit;
    sfIntRect rect_quit;
} pause_menu_t;

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
    sfText *text;
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
    sfSprite *good_job;
} map_t;

typedef struct avatar {
    sfSprite *sprite;
    sfIntRect rect;
    int yes;
} avatar_t;

typedef struct attack_boss {
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f pos;
    int touch;
    int life_boss;
    char *life_boss_str;
    sfText *life;
    sfVector2f pos_life;
    int is_life;
} attack_boss_t;

typedef struct enemy {
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite_d;
    sfIntRect detec;
    sfClock *clock;
    int pos_x;
    int pos_y;
    float sec;
    int life;
    int stage;
    int damage;
    int rotate;
    float growth;
    int wave;
} enemy_t;

typedef struct shield {
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    float sec;
    int active;
    int duration;
    int cd;
    float sec_cd;
    sfClock *clock_cd;
} shield_t;

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
    int damage;
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

typedef struct potion
{
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect select;
    int regen;
    int is_open;
    int is_pot;
} potion_t;

typedef struct fire
{
    sfSprite *sprite;
    sfIntRect rect;
    sfIntRect rect_r;
    sfSprite *sprite_r;
    sfClock *clock;
    sfVector2f pos;
    float sec;
    int speedfire;
    float sec_f;
    sfClock *clock_f;
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
    float tmp;
    int tmpsec;
    int one;
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
    sfText *text7;
} bubble_t;

typedef struct particle
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    float sec;
    sfClock *clock;
} particle_t;

typedef struct minispace
{
    sfSprite *sprite;
    sfIntRect rect;
} minispace_t;

typedef struct light
{
    sfSprite *sprite;
    sfIntRect rect;
} light_t;

typedef struct quest
{
    sfSprite *sprite;
    sfIntRect rect;
    sfText *text;
    sfVector2f pos;
    sfClock *clock;
    int t;
    sfText *text2;
    float sec;
    float ecou;
    int onetime;
} quest_t;

typedef struct labydoor
{
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    int speed;
    float sec;
} labydoor_t;

typedef struct global
{
    speak_t speak[2];
    int apt;
    button_play_t button_play[2];
    button_quit_t button_quit[2];
    button_tuto_t button_tuto[2];
    bird_t bird[10];
    font_blue_t font_blue;
    mountains_t mountains[3];
    behind_cloud_t behind_cloud;
    big_cloud_t big_cloud[3];
    fine_cloud_t fine_cloud[3];
    multiple_clouds_t multiple_clouds[3];
    front_clouds_t front_clouds[3];
    title_t title;
    // speak_t speak[1];
    shield_t shield[2];
    hero_t png_crest[3];
    hitbox_t hit_attack[5];
    map_t map[49];
    hero_t hero[12];
    enemy_t enemy[10];
    enemy_t boss;
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
    attack_boss_t hit_boss[2];
    toucht_t toucht[1];
    int scene;
    int scene_past;
    int facty;
    int life_slime;
    inventory_t inventory[2];
    sfVector2f mouse;
    tuto_t tutorial[1];
    island_t island[1];
    intro_t intro[3];
    pause_menu_t pause_menu[1];
    // intro_t intro[1];
    mentor_t mentor[1];
    bubble_t bubble[1];
    minispace_t minispace[1];
    sfEvent eventbox;
    light_t light[1];
    labydoor_t labydoor[2];
    particle_t particle[5];
    // labydoor_t labydoor[1];
    quest_t quest[15];
    int tuto;
    int my_exit;
    int attack;
    int nb_slime;
    int history_place;
    potion_t potion[2];
    float sec_menu;
    sfClock *clock_menu;
    float sec_bird;
    sfClock *clock_bird;
} global_t;

void init_avatar(global_t *m);
int initialization(void);
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
void slime_pushed_back(global_t *global, int i, int k);
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
void slime_hit(global_t *global, int i);
void draw_intro(global_t *global);
void init_intro(global_t *global_t);
void init_shield(global_t *global);
void animation_shield(global_t *global);
void draw_shield(global_t *global);
void draw_game_over(global_t *global);
void init_game_over(global_t *global);
int draw_pause(global_t *global);
void init_pause(global_t *global);
void end_game(global_t *global);
void draw_arena(global_t *global);
void animation_slime_boss(global_t *global);
void init_slime_boss(global_t *global);
void new_wave(global_t *global);
void init_mentor(global_t *g);
void init_rect_mentor(global_t *g);
void anim_mentor(global_t *g);
void init_bubble(global_t *m);
void init_minispace(global_t *m);
void init_light(global_t *g);
void check_hit_slime_boss(global_t *global);
void init_potion(global_t *global);
void inventory_react(global_t *global);
void draw_final(global_t *global);
void init_laby_door(global_t *m);
void draw_laby_door(global_t *m);
void anim_labydoor(global_t *m);
void window_create(global_t *global);
void init_title(global_t *global);
void init_mountains(global_t *global);
void init_big_clouds(global_t *global);
void init_background(global_t *global);
void init_button_play(global_t *global);
void init_button_quit(global_t *global);
void init_button_tuto(global_t *global);
void init_fine_clouds(global_t *global);
void init_behind_clouds(global_t *global);
void init_multiple_clouds(global_t *global);
void init_front_clouds(global_t *global);
void draw_menu(sfRenderWindow *window, global_t *global);
void init(global_t *global);
void change_position(global_t *global);
void reset_position(global_t *global);
void init_birds(global_t *global);
void move_rect(sfIntRect *rect, int offset, int max_value);
void define_clock(global_t *global);
void init_buttons(global_t *global);
void button_play_selected(global_t *global);
void button_draw(sfRenderWindow *window, global_t *global);
void bird_draw(sfRenderWindow *window, global_t *global);
void button_tuto_selected(global_t *global);
void play_draw(sfRenderWindow *window, global_t *global);
void tuto_draw(sfRenderWindow *window, global_t *global);
void button_quit_selected(global_t *global);
void setting_draw(sfRenderWindow *window, global_t *global);
void map(global_t *global);
void draw_landscape(sfRenderWindow *window, global_t *global);
void condition(global_t *global);
void quit_draw(sfRenderWindow *window, global_t *global);
void menu_button_selected(global_t *global);
void game_over_final(global_t *global);
void init_talk_to_png(global_t *global);
void init_boss_door(global_t *global);
void draw_end_game(global_t *global);
void init_end_game(global_t *global);
void init_fire_particle(global_t *global);
void fire_particle(global_t *global, int i);
void init_quest(global_t *m);
void draw_quest(global_t *m);

#endif /* MY_RPG_H_ */