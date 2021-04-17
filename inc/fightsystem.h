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

#endif /* !FIGHTSYSTEM_H_ */