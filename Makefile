##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC = 	src/main.c\
		src/init_window.c\
		src/button_creator.c\
		src/start_screen.c


OBJ = $(SRC:.c=.o)

NAME = minesweeper

CC = gcc

CFLAGS = -g

RM = rm -f

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lm
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
