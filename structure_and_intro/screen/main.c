#include "../inc/fightsystem.h"

void declare_buttons_helper(fbutton_t *button)
{
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_setPosition(button->rect[i], button->pos[i]);
        sfRectangleShape_setSize(button->rect[i], (sfVector2f) {400.0, 100.0});
        sfRectangleShape_setFillColor(button->rect[i], sfRed);
        sfRectangleShape_setOutlineColor(button->rect[i], sfBlack);
        sfRectangleShape_setOutlineThickness(button->rect[i], 2.0);
    }
}

void declare_buttons(fbutton_t *button)
{
    button->pos = malloc(sizeof(sfVector2f *) * 4);
    button->rect = malloc(sizeof(sfRectangleShape *) * 4);

    for (int i = 0; i < 4; i++) {
        button->rect[i] = sfRectangleShape_create();
        if (!button->rect[i] || !button->pos)
            exit(84);
        if (i >= 2) {
            button->pos[i].x = 400;
            if (i == 2)
                button->pos[i].y = 400;
            else
                button->pos[i].y = 500;
        } else {
            button->pos[i].x = 0;
            if (i == 0)
                button->pos[i].y = 400;
            else
                button->pos[i].y = 500;
        }
    }
}

void display_objects(fbutton_t *button, window_t *win)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(win->window, button->rect[i], NULL);
    }
}

void change_state_button_left(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    static int check = 0;

    if (win->pos.x >= 0 && win->pos.x < 400) {
        sfRectangleShape_setFillColor(button->rect[0], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
            sfRectangleShape_setFillColor(button->rect[0], (sfColor) {255, 0, 0, 30});
            check = 1;
        } else {
            if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
                my_fight(1, player_stats, monster_stats);
                printf("ATTACK\n");
                check = 0;
            }
        }
    } else if (win->pos.x >= 400 && win->pos.x < 800) {
        sfRectangleShape_setFillColor(button->rect[2], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
            sfRectangleShape_setFillColor(button->rect[2], (sfColor) {255, 0, 0, 30});
            check = 1;
        } else {
            if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
                my_fight(2, player_stats, monster_stats);
                printf("DEFENSE\n");
                check = 0;
            }
        }
    }
}

void change_state_button_right(fbutton_t *button, window_t *win, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    static int check = 0;

    if (win->pos.x >= 0 && win->pos.x < 400) {
        sfRectangleShape_setFillColor(button->rect[1], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
            sfRectangleShape_setFillColor(button->rect[1], (sfColor) {255, 0, 0, 30});
            check = 1;
        } else {
            if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
                my_fight(3, player_stats, monster_stats);
                printf("MAGIC\n");
                check = 0;
            }
        }
    } else if (win->pos.x >= 400 && win->pos.x < 800) {
        sfRectangleShape_setFillColor(button->rect[3], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft) && (check == 0 || check == 1)) {
            sfRectangleShape_setFillColor(button->rect[3], (sfColor) {255, 0, 0, 30});
            check = 1;
        } else {
            if (!sfMouse_isButtonPressed(sfMouseLeft) && check == 1) {
                my_fight(4, player_stats, monster_stats);
                printf("RUN AWAY\n");
                check = 0;
            }
        }
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

void eventhandler_helper(window_t *win ,fbutton_t * button)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
    }
}

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
    tmp = (sfVector2f) {tmp.x / (tmp.x + tmp.y) * 0.30,\
    tmp.y / (tmp.y + tmp.x) * 0.30};
    if (x == 1 || y == 1) {
        if (x == 1)
            tmp.x *= -1;
        if (y == 1)
            tmp.y *= -1;
    }
    return tmp;
}

void intro_scene(window_t *win)
{
    sfRectangleShape *player = sfRectangleShape_create();
    sfRectangleShape *enemy = sfRectangleShape_create();
    sfVector2f pos_p = (sfVector2f) {-200, 300};
    sfVector2f pos_e = (sfVector2f) {1000, 200};
    sfVector2f offset = (sfVector2f) {0, 0};

    sfRectangleShape_setPosition(player, pos_p);
    sfRectangleShape_setPosition(enemy, pos_e);
    sfRectangleShape_setSize(player, (sfVector2f) {20, 20});
    sfRectangleShape_setSize(enemy, (sfVector2f) {20, 20});
    sfRectangleShape_setFillColor(player, sfWhite);
    sfRectangleShape_setFillColor(enemy, sfWhite);
    while (1) {
        sfRenderWindow_clear(win->window, sfBlack);
        offset = calculate_move_offset((sfVector2f) {200, 400}, pos_p);
        pos_p = (sfVector2f) {pos_p.x + offset.x, pos_p.y + offset.y};
        sfRectangleShape_setPosition(player, pos_p);
        offset = calculate_move_offset((sfVector2f) {600, 100}, pos_e);
        pos_e = (sfVector2f) {pos_e.x + offset.x, pos_e.y + offset.y};
        sfRectangleShape_setPosition(enemy, pos_e);
        sfRenderWindow_drawRectangleShape(win->window, player, NULL);
        sfRenderWindow_drawRectangleShape(win->window, enemy, NULL);
        sfRenderWindow_display(win->window);
    }
}

int main()
{
    window_t *win = malloc(sizeof(window_t));
    win->mode = (sfVideoMode) {800, 600, 32};
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
