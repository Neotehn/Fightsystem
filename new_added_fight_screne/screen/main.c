#include "../inc/fightsystem.h"

void display_objects(fbutton_t *button, window_t *win, sfText **text)
{
    static int change = 0;

    sfRenderWindow_drawSprite(win->window, win->sprite[change], NULL);
    sfSprite_setPosition(win->sprite[change], (sfVector2f) {430.0, 178.32});
    sfRenderWindow_drawSprite(win->window, win->sprite[change], NULL);
    sfSprite_setPosition(win->sprite[change], (sfVector2f) {330.0, 178.32});
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawRectangleShape(win->window, button->rect[i], NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->player, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->enemy, NULL);
    if (win->time >= 0.2) {
        sfClock_restart(win->clock);
        win->time = 0;
        change += 1;
    }
    if (change == 3)
        change = 0;
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawText(win->window, text[i], NULL);
}

void eventhandler_helper(window_t *win ,fbutton_t * button)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
    }
}

void game_loop(window_t *win, fbutton_t *buttons, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    while (sfRenderWindow_isOpen(win->window)) {
        win->time = sfTime_asSeconds(sfClock_getElapsedTime(win->clock));
        eventhandler_helper(win, buttons);
        sfRenderWindow_clear(win->window, sfBlack);
        change_state_button(buttons, win, player_stats, monster_stats);
        display_objects(buttons, win, win->text);
        sfRenderWindow_display(win->window);
        if (win->end != 0)
            break;
    }
}

void free_struct(window_t *win, fbutton_t *buttons, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    sfRectangleShape_destroy(win->enemy);
    sfRectangleShape_destroy(win->player);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(win->sprite[i]);
        sfTexture_destroy(win->texture[i]);
    }
    free(win->sprite);
    free(win->texture);
    for (int i = 0; i < 5; i++)
        sfText_destroy(win->text[i]);
    free(win->text);
    sfClock_destroy(win->clock);
    for (int i = 0; i < 4; i++)
        sfRectangleShape_destroy(buttons->rect[i]);
    free(buttons->pos);
    free(buttons->rect);
}

int main()
{
    window_t *win = malloc(sizeof(window_t));
    fbutton_t *buttons = malloc(sizeof(fbutton_t));
    player_stats_t *player_stats = malloc(sizeof(player_stats_t));                   
    monster_stats_t *monster_stats = malloc(sizeof(monster_stats_t));
    sfFont *font = sfFont_createFromFile("../fonts/font.otf");
    
    if (!buttons || !win || !player_stats || !monster_stats || !win)
        exit(84);
    init_structures(win, buttons, player_stats, monster_stats);
    intro_scene(win);
    declare_text(font, win->text);
    game_loop(win, buttons, player_stats, monster_stats);
    free_struct(win, buttons, player_stats, monster_stats);
    sfRenderWindow_destroy(win->window);
    return win->end;
}
