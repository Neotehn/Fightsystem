#include "../inc/fightsystem.h"

void init_structures_helper(window_t *win, fbutton_t *buttons, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    for (int i = 0; i < 3; i++) {
        win->sprite[i] = sfSprite_create();
        if (i == 0) {
            win->texture[i] = \
            sfTexture_createFromFile("../sprites_symbols/sword.png", NULL);
            sfSprite_setTexture(win->sprite[i], win->texture[i], sfTrue);
            sfSprite_setScale(win->sprite[i], (sfVector2f) {0.1, 0.1});
        } else if (i == 1) {
            win->texture[i] = \
            sfTexture_createFromFile("../sprites_symbols/shield.png", NULL);
            sfSprite_setTexture(win->sprite[i], win->texture[i], sfTrue);
            sfSprite_setScale(win->sprite[i], (sfVector2f) {0.307, 0.307});
        } else {
            win->texture[i] = \
            sfTexture_createFromFile("../sprites_symbols/magic.png", NULL);
            sfSprite_setTexture(win->sprite[i], win->texture[i], sfTrue);
            sfSprite_setScale(win->sprite[i], (sfVector2f) {0.072, 0.072});
        }
        sfSprite_setPosition(win->sprite[i], (sfVector2f) {330.0, 178.35});
    }
}

void init_structures(window_t *win, fbutton_t *buttons, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    win->mode = (sfVideoMode) {800, 600, 32};
    win->window = \
    sfRenderWindow_create(win->mode, "SFML window", sfResize | sfClose, NULL);
    win->player = sfRectangleShape_create();
    win->enemy = sfRectangleShape_create();
    win->sprite = malloc(sizeof(sfSprite *) * 4);
    win->texture = malloc(sizeof(sfTexture *) * 4);
    win->time = 0;
    win->clock = sfClock_create();
    win->text = malloc(sizeof(sfText *) * 10);
    win->end = 0;

    if (!win->window || !win->sprite || !win->texture || !win->text)
        exit(84);
    init_structures_helper(win, buttons, player_stats, monster_stats);
    player_stats = my_player_stats_generation(player_stats);        
    monster_stats = \
    my_monster_stats_generation(monster_stats, player_stats->level);
    declare_buttons(buttons);
    declare_buttons_helper(buttons);
}