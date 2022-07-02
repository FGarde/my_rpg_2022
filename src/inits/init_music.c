/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde [WSL: Ubuntu]
** File description:
** init_music
*/

#include "global.h"

music_t *init_music(music_t *music)
{
    music->pathfile = "ressources/audio/soundtracks/ambiant_st_one.ogg";
    music->volume = 100;

    return music;
}
