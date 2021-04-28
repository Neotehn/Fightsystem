#include "../inc/fightsystem.h"

void change_state_button_left(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    if (win->pos.x >= 0 && win->pos.x < 400) {
        attack_button(button, win, player_stats, monster_stats);
    } else if (win->pos.x >= 400 && win->pos.x < 800) {
        defense_button(button, win, player_stats, monster_stats);
    }
}

void change_state_button_right(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    if (win->pos.x >= 0 && win->pos.x < 400) {
        magic_button(button, win, player_stats, monster_stats);
    } else if (win->pos.x >= 400 && win->pos.x < 800) {
        run_away_button(button, win, player_stats, monster_stats);
    }
}

void change_state_button(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    int check = 1;
    win->pos = sfMouse_getPosition((const sfWindow *) win->window);

    for (int i = 0; i < 4; i++)
        sfRectangleShape_setFillColor(button->rect[i], sfRed);
    if (win->pos.y >= 400 && win->pos.y < 500) {
        change_state_button_left(button, win, player_stats, monster_stats);
    } else if (win->pos.y >= 500 && win->pos.y < 600) {
        change_state_button_right(button, win, player_stats, monster_stats);
    }
}