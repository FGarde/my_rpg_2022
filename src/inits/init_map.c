/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** init_map
*/

#include "global.h"

maps_t *init_map(void)
{
    maps_t *maps = malloc(sizeof(maps_t));

    maps->map_texture = sfTexture_createFromFile\
    ("ressources/maps/map.png", NULL);
    maps->map_sprite = sfSprite_create();
    sfSprite_setTexture(maps->map_sprite, \
    maps->map_texture, sfTrue);
    sfSprite_setPosition(maps->map_sprite, (sfVector2f){0, 0});
    maps->map_texture_3d = sfTexture_createFromFile\
    ("ressources/maps/map_3d.png", NULL);
    maps->map_sprite_3d = sfSprite_create();
    sfSprite_setTexture(maps->map_sprite_3d, \
    maps->map_texture_3d, sfTrue);
    sfSprite_setPosition(maps->map_sprite_3d, (sfVector2f){0, 0});
    return maps;
}
