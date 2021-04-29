#include "../inc/fightsystem.h"

void magic_button(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    static int check = 0;

    sfRectangleShape_setFillColor(button->rect[1], \
    (sfColor) {255, 0, 0, 180});
    if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
        sfRectangleShape_setFillColor(button->rect[1], \
        (sfColor) {255, 0, 0, 30});
        check = 1;
    } else {
        if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
            my_fight(3, player_stats, monster_stats);
            sfRectangleShape_setFillColor(button->rect[0], \
            (sfColor) {255, 0, 0, 255});
            printf("MAGIC\n");
            check = 0;
        }
    }
}

void run_away_button(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    static int check = 0;

    sfRectangleShape_setFillColor(button->rect[3], \
    (sfColor) {255, 0, 0, 180});
    if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
        sfRectangleShape_setFillColor(button->rect[3], \
        (sfColor) {255, 0, 0, 30});
        check = 1;
    } else {
        if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
            my_fight(4, player_stats, monster_stats);
            sfRectangleShape_setFillColor(button->rect[0], \
            (sfColor) {255, 0, 0, 255});
            printf("RUN AWAY\n");
            check = 0;
        }
    }
}

void attack_button(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    static int check = 0;

    sfRectangleShape_setFillColor(button->rect[0], \
    (sfColor) {255, 0, 0, 180});
    if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
        sfRectangleShape_setFillColor(button->rect[0], \
        (sfColor) {255, 0, 0, 30});
        check = 1;
    } else {
        if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
            my_fight(1, player_stats, monster_stats);
            sfRectangleShape_setFillColor(button->rect[0], \
            (sfColor) {255, 0, 0, 255});
            fight_result(button, win, player_stats, monster_stats);
            printf("ATTACK\n");
            check = 0;
        }
    }
}

void defense_button(fbutton_t *button, window_t *win,\
player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    static int check = 0;

    sfRectangleShape_setFillColor(button->rect[2], \
    (sfColor) {255, 0, 0, 180});
    if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
        sfRectangleShape_setFillColor(button->rect[2], \
        (sfColor) {255, 0, 0, 30});
        check = 1;
    } else {
        if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
            my_fight(2, player_stats, monster_stats);
            sfRectangleShape_setFillColor(button->rect[0], \
            (sfColor) {255, 0, 0, 255});
            printf("DEFENSE\n");
            check = 0;
        }
    }
}

//implement time -> faking calc
void fight_result(fbutton_t *buttons, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    while (sfRenderWindow_isOpen(win->window)) {
        eventhandler_helper(win, buttons);
        sfRenderWindow_clear(win->window, sfBlack);
        display_objects(buttons, win);
        sfRenderWindow_display(win->window);
    }
}