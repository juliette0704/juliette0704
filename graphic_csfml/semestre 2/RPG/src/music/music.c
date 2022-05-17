/*
** EPITECH PROJECT, 2022
** music
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_music(global_t *global)
{
    global->music[0].music = sfMusic_createFromFile("music/music.wav");
    sfMusic_setVolume(global->music[0].music, 10);
    char *str[] = {"music/boss_sound.wav", "music/potion_sound.wav", "music/shield_sound.wav", "music/sword_sound.wav"};
    for (int i = 0; i < 4; i++) {
        global->sound[i].sound_buffer = sfSoundBuffer_createFromFile(str[i]);
        global->sound[i].sound = sfSound_create();
        sfSound_setBuffer(global->sound[i].sound, global->sound[i].sound_buffer);
    }
    sfMusic_play(global->music[0].music);
    sfMusic_setLoop(global->music[0].music, sfTrue);
    return;
}
