/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** prototypes
*/

#include "structures.h"

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_

// init functions

int init_character(game_t *game);
window_t *init_window(window_t *window);
game_t *init_game(game_t *game, window_t *window);
maps_t *init_map();
music_t *init_music(music_t *music);
sound_t *init_sound(sound_t *sound);
text_t *init_text(char *text, char *font, sfVector2f pos);
button_t *init_button(char *text, char *font, sfVector2f pos);

// window functions

window_t *resize_window(window_t *window);

// game loop functions

int my_rpg_game(game_t *game);
int display(game_t *game);
int reset_zoom(game_t *game);
int event_loop(game_t *game);
int update_animation(game_t *game);
int zoom_view(float zoom, game_t *game);
int rotate_view(float rotate, game_t *game);
int key_pressed(game_t *game, sfEvent event);
int analyse_event(game_t *game, sfEvent event);
int move_view(int x, int y, game_t *game, sfEvent *event);
int move_animation(game_t *game, int direction, sfEvent event);

// particles functions

int draw_particle(game_t *game);
int update_particle(game_t *game);
int create_particles(game_t *game);
int destroy_particles(game_t *game);
int create_rain_particles(game_t *game);
int update_rain_particle(game_t *game);
int draw_rain_particle(game_t *game);
int rain_gestion(game_t *game);
int destroy_rain_particles(game_t *game);
int destroy_all_rain_particles(game_t *game);

// destroy functions

int destroy_all(game_t *game);
int destroy_game(game_t *game);
int destroy_all_particles(game_t *game);
int destroy_enemy(game_t *game);
int destroy_all_enemy(game_t *game);

// enemies functions

int draw_enemy(game_t *game);
int update_enemy(game_t *game);
int create_enemy(game_t *game, int level);
void vulnerability_update(game_t *game);

// arrays of buttons functions

button_t **array_of_buttons(void);
button_t **array_of_buttons_settings(void);
button_t **array_of_buttons_htp(void);
button_t **array_of_buttons_pause(void);

// arrays of texts functions

text_t **array_of_texts_main_menu(void);
text_t **array_of_texts(game_t *game, text_t **texts);

// meunus functions

int rpg_menu(void);
int main_menu(game_t *game);
int menu_htp(game_t *game);
int menu_settings(game_t *game);
int menu_pause(game_t *game);

// pre game launching functions

void check_help(char *av[]);
int check_env(char **env);
int analyse_event(game_t *game, sfEvent event);

// displaying functions

void display_hud(game_t *game, background_t *bg, button_t **buttons);
void display_buttons(game_t *game , button_t **buttons);
void display_hud_main_menu(game_t *game, background_t *bg, button_t **buttons);
int display_background(game_t *game, background_t *bg);

// checking hitbox buttons functions

int check_click_on_button_settings(game_t *game, button_t **buttons,
sfMouseButtonEvent event);
int check_click_on_button_htp(game_t *game, button_t **buttons,
sfMouseButtonEvent event);
int check_click_on_button_pause(game_t *game, button_t **buttons,
sfMouseButtonEvent event);
int check_click_on_button(game_t *game, button_t **buttons,
sfMouseButtonEvent event);

// audio functions

int play_background_music(game_t *game);
music_t *update_music(music_t *music);
int play_sound_effect_merp(game_t *game);
sound_t *update_sound(sound_t *sound);

#endif /* !PROTOTYPES_H_ */
