/*
** EPITECH PROJECT, 2021
** stats_generation.c
** File description:
** .
*/

#include "../inc/fightsystem.h"

int my_random(int level)
{
    int num = (rand() %((level) - 1 + 1)) + 1;
    return (num);
}

player_stats_t *my_player_stats_generation(player_stats_t *player_stats)
{
    player_stats->level = 1;
    player_stats->hp = 100;
    player_stats->attack = 10;
    player_stats->defense = 10;
    player_stats->magic = 10;
    player_stats->speed = 10;
    return (player_stats);
}

monster_stats_t *my_monster_stats_generation(monster_stats_t *monster_stats, int player_level)
{
    monster_stats->hp = 10 * my_random(player_level + 1);
    monster_stats->attack = 2 * my_random(player_level + 1);
    monster_stats->defense = 2 * my_random(player_level + 1);
    monster_stats->magic = 2 * my_random(player_level + 1);
    monster_stats->speed = 2 * my_random(player_level + 1);
    return (monster_stats);
}