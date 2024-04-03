##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c 		\
		my_compute_square_root.c 	\
		my_find_prime_sup.c 		\
		my_getnbr.c 			\
		my_isneg.c 			\
		my_is_prime.c 			\
		my_putchar.c 			\
		my_put_nbr.c		 	\
		my_putstr.c 			\
		my_put_nbr_uns.c 		\
		my_revstr.c 			\
		my_showstr.c 			\
		my_get_decimal.c		\
		my_decimal_to_octal.c 		\
		get_bin.c  			\
		my_strcapitalize.c 		\
		my_strcat.c 			\
		my_strcmp.c 			\
		my_strcpy.c 			\
		my_nb_float.c  			\
		my_nb_scientific.c 		\
		my_put_long_uns.c 		\
		my_count_nbr.c 			\
		my_put_long.c 			\
		my_printf.c			\
		my_str_isalpha.c 		\
		my_str_islower.c 		\
		my_str_isnum.c 			\
		my_str_isprintable.c		\
		my_str_isupper.c 		\
		my_strlen.c 			\
		my_strlowcase.c 		\
		my_strncat.c 			\
		my_strncpy.c 			\
		my_strstr.c 			\
		my_strupcase.c 			\
		my_swap.c			\
		my_put_sign.c		\
		my_strndup.c 		\
		my_strdup.c 		\
		my_strncmp.c 		\
		my_strcmp2.c 		\

OBJ 	=	$(SRC:.c=.o)

NAME1	=	libmy.a

all:	$(NAME1) clean

$(NAME1):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME1)

re: fclean all
