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