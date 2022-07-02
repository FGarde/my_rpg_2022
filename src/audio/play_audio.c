/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde [WSL: Ubuntu]
** File description:
** play_audio
*/

#include "global.h"

int play_background_music(game_t *game)
{
    game->music->music = sfMusic_createFromFile(game->music->pathfile);
    if (!game->music->music)
        return 84;
    sfMusic_setVolume(game->music->music, game->music->volume);
    sfMusic_setLoop(game->music->music, sfTrue);
    sfMusic_play(game->music->music);
    return 0;
}

music_t *update_music(music_t *music)
{
    int vol_max = 125;
    music->volume += 25;

    if (music->volume >= vol_max) {
        music->volume = 0;
    }
    return music;
}
