/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde [WSL: Ubuntu]
** File description:
** init_sound
*/

#include "global.h"

sound_t *init_sound(sound_t *sound)
{
    sound->volume = 100;
    return sound;
}
