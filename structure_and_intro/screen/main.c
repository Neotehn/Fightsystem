#include "../inc/fightsystem.h"

void display_objects(fbutton_t *button, window_t *win)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(win->window, button->rect[i], NULL);
    }
    sfRenderWindow_drawRectangleShape(win->window, win->player, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->enemy, NULL);
}

void eventhandler_helper(window_t *win ,fbutton_t * button)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
    }
}

int main()
{
    window_t *win = malloc(sizeof(window_t));
    win->mode = (sfVideoMode) {800, 600, 32};
    win->player = sfRectangleShape_create();
    win->enemy = sfRectangleShape_create();
    fbutton_t *buttons = malloc(sizeof(fbutton_t));
    player_stats_t *player_stats = malloc(sizeof( player_stats_t));                   
    monster_stats_t *monster_stats = malloc(sizeof( monster_stats_t));
    
    player_stats = my_player_stats_generation(player_stats);        
    monster_stats = my_monster_stats_generation(monster_stats, player_stats->level);

    if (!buttons)
        exit(84);
    win->window = sfRenderWindow_create(win->mode, "SFML window", sfResize | sfClose, NULL);
    declare_buttons(buttons);
    declare_buttons_helper(buttons);
    if (!win->window)
        return EXIT_FAILURE;
    intro_scene(win);
    while (sfRenderWindow_isOpen(win->window)) {
        eventhandler_helper(win, buttons);
        sfRenderWindow_clear(win->window, sfBlack);
        change_state_button(buttons, win, player_stats, monster_stats);
        display_objects(buttons, win);
        sfRenderWindow_display(win->window);
    }
    sfRenderWindow_destroy(win->window);
    return EXIT_SUCCESS;
}
