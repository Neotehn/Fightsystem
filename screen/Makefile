##
## EPITECH PROJECT, 2021
## my_defender
## File description:
## makefile
##

SRC	=	./main.c

NAME	=	my_rpg

INC	=	-I./inc/

all:	$(NAME)

$(NAME):
			gcc $(SRC) $(INC) -o $(NAME) -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio -g3

clean:
		rm -f $(NAME)

fclean:	clean

re:	fclean	all