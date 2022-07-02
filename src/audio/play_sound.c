/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** play_sound
*/

#include "global.h"

int play_sound_effect_merp(game_t *game)
{
    game->sound->sound_buffer = sfSoundBuffer_createFromFile\
    ("ressources/audio/soundeffects/merp.ogg");
    game->sound->sound = sfSound_create();
    if (!game->sound->sound_buffer)
        return 84;

    sfSound_setVolume(game->sound->sound, game->sound->volume);
    sfSound_setBuffer(game->sound->sound,game->sound->sound_buffer);
    sfSound_play(game->sound->sound);
    return 0;
}

sound_t *update_sound(sound_t *sound)
{
    int vol_max = 125;
    sound->volume += 25;

    if (sound->volume >= vol_max) {
        sound->volume = 0;
    }
    return sound;
}
