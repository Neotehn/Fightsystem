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

void display_objects(fbutton_t *button, sfRenderWindow *win)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(win, button->rect[i], NULL);
    }
}

void change_state_button_left(fbutton_t *button, sfRenderWindow *win, sfVector2i pos)
{
    if (pos.x >= 0 && pos.x < 400) {
        sfRectangleShape_setFillColor(button->rect[0], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRectangleShape_setFillColor(button->rect[0], (sfColor) {255, 0, 0, 30});
    } else if (pos.x >= 400 && pos.x < 800) {
        sfRectangleShape_setFillColor(button->rect[2], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRectangleShape_setFillColor(button->rect[2], (sfColor) {255, 0, 0, 30});
    }
}

void change_state_button_right(fbutton_t *button, sfRenderWindow *win, sfVector2i pos)
{
    if (pos.x >= 0 && pos.x < 400) {
        sfRectangleShape_setFillColor(button->rect[1], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRectangleShape_setFillColor(button->rect[1], (sfColor) {255, 0, 0, 30});
    } else if (pos.x >= 400 && pos.x < 800) {
        sfRectangleShape_setFillColor(button->rect[3], (sfColor) {255, 0, 0, 180});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRectangleShape_setFillColor(button->rect[3], (sfColor) {255, 0, 0, 30});
    }
}

void change_state_button(fbutton_t *button, sfRenderWindow *win, sfVector2i pos)
{
    int check = 1;
    pos = sfMouse_getPosition((const sfWindow *) win);

    for (int i = 0; i < 4; i++)
        sfRectangleShape_setFillColor(button->rect[i], sfRed);
    if (pos.y >= 400 && pos.y < 500) {
        change_state_button_left(button, win, pos);
    } else if (pos.y >= 500 && pos.y < 600) {
        change_state_button_right(button, win, pos);
    }
}

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;
    sfRenderWindow* window;
    sfVector2i pos;
    fbutton_t *buttons = malloc(sizeof(fbutton_t));

    if (!buttons)
        exit(84);
    
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    declare_buttons(buttons);
    declare_buttons_helper(buttons);
    if (!window)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        change_state_button(buttons, window, pos);
        display_objects(buttons, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
