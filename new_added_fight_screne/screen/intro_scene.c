#include "../inc/fightsystem.h"

sfVector2f calculate_move_offset(sfVector2f dest, sfVector2f current_point)
{
    sfVector2f tmp = (sfVector2f) {dest.x - current_point.x,\
    dest.y - current_point.y};
    int x = 0;
    int y = 0;

    if (tmp.x < 0 || tmp.y < 0) {
        if (tmp.x < 0)
            x = 1;
        if (tmp.y < 0)
            y = 1;
    }
    tmp = (sfVector2f) {tmp.x / (tmp.x + tmp.y) * 0.60,\
    tmp.y / (tmp.y + tmp.x) * 0.60};
    if (x == 1 || y == 1) {
        if (x == 1)
            tmp.x *= -1;
        if (y == 1)
            tmp.y *= -1;
    }
    return tmp;
}

void intro_scene_helper(window_t *win, sfVector2f pos_p, sfVector2f pos_e)
{
    sfRectangleShape_setPosition(win->player, pos_p);
    sfRectangleShape_setPosition(win->enemy, pos_e);
    sfRectangleShape_setSize(win->player, (sfVector2f) {20, 20});
    sfRectangleShape_setSize(win->enemy, (sfVector2f) {20, 20});
    sfRectangleShape_setFillColor(win->player, sfWhite);
    sfRectangleShape_setFillColor(win->enemy, sfWhite);
}

void intro_scene(window_t *win)
{
    sfVector2f pos_p = (sfVector2f) {-200, 200};
    sfVector2f pos_e = (sfVector2f) {1000, 200};
    sfVector2f offset = (sfVector2f) {0, 0};

    intro_scene_helper(win, pos_p, pos_e);
    while (1) {
        sfRenderWindow_clear(win->window, sfBlack);
        offset = calculate_move_offset((sfVector2f) {200, 300}, pos_p);
        pos_p = (sfVector2f) {pos_p.x + offset.x, pos_p.y + offset.y};
        sfRectangleShape_setPosition(win->player, pos_p);
        offset = calculate_move_offset((sfVector2f) {600, 100}, pos_e);
        pos_e = (sfVector2f) {pos_e.x + offset.x, pos_e.y + offset.y};
        sfRectangleShape_setPosition(win->enemy, pos_e);
        sfRenderWindow_drawRectangleShape(win->window, win->player, NULL);
        sfRenderWindow_drawRectangleShape(win->window, win->enemy, NULL);
        sfRenderWindow_display(win->window);
        if (pos_p.x >= 199 && pos_p.y >= 299)
            break;
    }
}