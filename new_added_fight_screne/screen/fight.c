/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** .
*/

#include "../inc/fightsystem.h"

void player_attack(player_stats_t *player_stats, monster_stats_t *monster_stats, int i)
{
    if (i = 1) {
        monster_stats->hp = monster_stats->hp - player_stats->attack;
        player_stats->hp = player_stats->hp - monster_stats->attack;
    } else if (i = 2) {
        monster_stats->hp = monster_stats->hp - (player_stats->attack - monster_stats->defense);
    } else {
        monster_stats->hp = monster_stats->hp - player_stats->attack;
        player_stats->hp = player_stats->hp - monster_stats->magic;
    } 
}

void player_defense(player_stats_t *player_stats, monster_stats_t *monster_stats, int i)
{
    if (i = 1) {
        player_stats->hp = player_stats->hp - (player_stats->defense - monster_stats->attack);
    } else if (i = 2) {
        if(player_stats->defense < monster_stats->defense)
            player_stats->defense = player_stats->defense - 1;
        monster_stats->defense = monster_stats->defense - 1;
    } else {
        player_stats->hp = player_stats->hp - monster_stats->magic;
    }
}

void player_magic(player_stats_t *player_stats, monster_stats_t *monster_stats, int i)
{
    if (i = 1) {
        monster_stats->hp = monster_stats->hp - player_stats->magic;
        player_stats->hp = player_stats->hp - monster_stats->attack;
    } else if (i = 2) {
        monster_stats->hp = monster_stats->hp - player_stats->magic;
    } else {
        monster_stats->hp = monster_stats->hp - player_stats->magic;
        player_stats->hp = player_stats->hp - monster_stats->magic;
    } 
}

void player_run(player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    if (player_stats->speed < monster_stats->speed)
        player_stats->hp = player_stats->hp - (monster_stats->attack / 2);
}

int my_fight(int i, player_stats_t *player_stats, monster_stats_t *monster_stats)
{
    int enem_turn = my_random(3);

    monster_stats->decision = enem_turn;
    player_stats->decision = i;

    switch (i) {
        case 1: player_attack(player_stats, monster_stats, enem_turn); break;
        case 2: player_defense(player_stats, monster_stats, enem_turn); break;
        case 3: player_magic(player_stats, monster_stats, enem_turn); break;
        case 4: player_run(player_stats, monster_stats); break;
    }
    printf("%d\n", player_stats->hp);
    printf("%d\n", monster_stats->hp);  
}