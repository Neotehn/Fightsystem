/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** header file
*/

#ifndef FIGHTSYSTEM_H_
#define FIGHTSYSTEM_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

typedef struct fight_buttons_s {
    sfRectangleShape **rect;
    sfVector2f *pos;
    sfFont *font;
    sfText *text;
} fbutton_t;

typedef struct player_stats_s {
    int level;
    int hp;
    int attack;
    int defense;
    int magic;
    int speed;
} player_stats_t;

typedef struct monster_stats_s {
    int hp;
    int attack;
    int defense;
    int magic;
    int speed;
} monster_stats_t;

player_stats_t *my_player_stats_generation(player_stats_t *player_stats);
monster_stats_t *my_monster_stats_generation(monster_stats_t *monster_stats, int player_level);
int my_random(int level);
int my_fight(int i, player_stats_t *player_stats, monster_stats_t *monster_stats);

#endif /* !FIGHTSYSTEM_H_ */