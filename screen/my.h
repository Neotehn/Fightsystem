/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** .
*/


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

player_stats_t my_player_stats_generation(void);
monster_stats_t my_monster_stats_generation(int player_level);
int my_random(int level);