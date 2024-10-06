# Makefile

NAME = Projet_morpion

SRC = tic-tac-toe.c

all :  $(NAME)

$(NAME): $(SRC)
	gcc $(SRC) -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all
