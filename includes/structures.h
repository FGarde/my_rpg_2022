/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** structures
*/

#ifndef STRUCTURES_H_
    #define STRUCTURES_H_

    #include "linked_list.h"

typedef struct sounds {
    char *pathfile;
    int volume;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} sound_t;

typedef struct musics {
    char *pathfile;
    int volume;
    sfMusic *music;
} music_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
} text_t;

typedef struct background_s
{
    sfSprite *sprite;
    sfTexture *texture;
} background_t;

typedef struct button_s
{
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    int i;
} button_t;

typedef struct window_s
{
    sfRenderWindow *window;
    sfVideoMode mode;
    int res_x;
    int res_y;
    int fps;
    char *name;
    int resolution;
} window_t;

typedef struct maps_s {
    sfTexture *map_texture_3d;
    sfTexture *map_texture;
    sfSprite *map_sprite_3d;
    sfSprite *map_sprite;
    sfImage *map_collision;
} maps_t;

typedef struct character_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    int direction;
    bool moving;
    sfVector2f pos;
    int life;
    int damage;
    sfInt64 attack_speed;
    sfClock *clock_attack;
    sfIntRect hitbox;
    bool vulnerable;
} character_t;

typedef struct particles_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfColor color;
    int lifetime;
} particle_t;

typedef struct game_s
{
    maps_t *maps;
    sfView *view;
    sfView *hud_view;
    sfFloatRect view_rect;
    sfVector2f view_pos;
    sfClock *clock;
    float zoom;
    character_t *character;
    linked_list_t *particles;
    linked_list_t *rain;
    linked_list_t *enemies;
    bool raining;
    sfClock *particle_clock;
    bool paused;
    sfClock *enemy_clock;
    sfTexture *texture_life;
    sfSprite *sprite_life;
    sfIntRect rect_life;
    button_t *Button;
    text_t *Text;
    background_t *Background;
    window_t *Window;
    int id_screen;
    sound_t *sound;
    music_t *music;
}  game_t;

#endif /* !STRUCTURES_H_ */
