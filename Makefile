##
## EPITECH PROJECT, 2023
## Prog_Sys_Unix
## File description:
## Makefile
##

SRC		=	src/main/main.c 				\
			src/main/launch_terminal.c 		\
			src/main/splitter.c 			\
			src/commands/executer.c 		\
			src/env/env_commands.c 			\
			src/cd/change_directory.c 		\
			src/commands/get_all_path.c 	\
			src/cd/cd_env.c 				\
			src/cd/cd_get_pos.c				\
			src/env/unsetenv.c 				\
			src/env/setenv.c 				\
			src/main/check_commands.c 		\
			src/main/utils.c 				\
			src/main/executioner.c 			\
			src/cd/cd_error.c 				\

OBJ		=	$(SRC:.c=.o)

NAME 	=	mysh

FLAGS = -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -g -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/my
	rm -f $(NAME)
	rm -f unit_test

re: fclean all

unit_test:
	make -C lib/my
	gcc -o unit_test $(SRC2) --coverage -lcriterion $(FLAGS)

tests_run: unit_test
	./unit_test
