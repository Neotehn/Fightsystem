#include "../inc/fightsystem.h"

void display_objects(fbutton_t *button, window_t *win)
{
    static int change = 0;

    sfRenderWindow_drawSprite(win->window ,win->sprite[change], NULL);
    sfSprite_setPosition(win->sprite[change], (sfVector2f) {450.0, 178.32});
    sfRenderWindow_drawSprite(win->window ,win->sprite[change], NULL);
    sfSprite_setPosition(win->sprite[change], (sfVector2f) {350.0, 178.32});
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(win->window, button->rect[i], NULL);
    }
    sfRenderWindow_drawRectangleShape(win->window, win->player, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->enemy, NULL);

    change += 1;
    if (change == 3)
        change = 0;
}

void eventhandler_helper(window_t *win ,fbutton_t * button)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
    }
}

//43,3 px
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
        sfSprite_setPosition(win->sprite[i], (sfVector2f) {350.0, 178.35});
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

    if (!win->window || !win->sprite || !win->texture)
        exit(84);
    init_structures_helper(win, buttons, player_stats, monster_stats);
    player_stats = my_player_stats_generation(player_stats);        
    monster_stats = \
    my_monster_stats_generation(monster_stats, player_stats->level);
    declare_buttons(buttons);
    declare_buttons_helper(buttons);
}

int main()
{
    window_t *win = malloc(sizeof(window_t));
    fbutton_t *buttons = malloc(sizeof(fbutton_t));
    player_stats_t *player_stats = malloc(sizeof( player_stats_t));                   
    monster_stats_t *monster_stats = malloc(sizeof( monster_stats_t));
    
    if (!buttons || !win || !player_stats || !monster_stats)
        exit(84);
    init_structures(win, buttons, player_stats, monster_stats);
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
