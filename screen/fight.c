/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** .
*/

#include "./my.h"

void player_attack(player_stats_t player_stats, monster_stats_t monster_stats)
{
    int i = my_random(3);

    if(i = 1) {
        monster_stats.hp = monster_stats.hp - player_stats.attack;
        player_stats.hp = player_stats.hp - monster_stats.attack;
    } else if (i = 2) {
        monster_stats.hp = monster_stats.hp - (player_stats.attack - monster_stats.defense);
    } else {
        monster_stats.hp = monster_stats.hp - player_stats.attack;
        player_stats.hp = player_stats.hp - monster_stats.magic;
    } 
}

void player_defense(player_stats_t player_stats, monster_stats_t monster_stats)
{
    int i = my_random(3);

    if(i = 1) {
        player_stats.hp = player_stats.hp - (monster_stats.attack - player_stats.defense);
    } else if (i = 2) {
        if(player_stats.defense < monster_stats.defense)
            player_stats.defense = player_stats.defense - 1;
        monster_stats.defense = monster_stats.defense - 1;
    } else {
        player_stats.hp = player_stats.hp - monster_stats.magic;
    } 
}

void player_magic(player_stats_t player_stats, monster_stats_t monster_stats)
{
    int i = my_random(3);

    if(i = 1) {
        monster_stats.hp = monster_stats.hp - player_stats.magic;
        player_stats.hp = player_stats.hp - monster_stats.attack;
    } else if (i = 2) {
        monster_stats.hp = monster_stats.hp - player_stats.magic;
    } else {
        monster_stats.hp = monster_stats.hp - player_stats.magic;
        player_stats.hp = player_stats.hp - monster_stats.magic;
    } 
}

void player_run(player_stats_t player_stats, monster_stats_t monster_stats)
{
    if (player_stats.speed < monster_stats.speed)
        player_stats.hp = player_stats.hp - (monster_stats.attack / 2);
}

int fight(int i)
{
    player_stats_t player_stats = my_player_stats_generation();
    monster_stats_t monster_stats = my_monster_stats_generation(player_stats.level);

    switch (i) {
        case 1: player_attack(player_stats, monster_stats); break;
        case 2: player_defense(player_stats, monster_stats); break;
        case 3: player_magic(player_stats, monster_stats); break;
        case 4: player_run(player_stats, monster_stats); break;
    }
}