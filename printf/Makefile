# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartole <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 17:58:29 by abartole          #+#    #+#              #
#    Updated: 2019/07/19 19:12:04 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -g
ADDFLAGS = -I ../libft/

INC = ft_printf.h double.h

SRC = check_format.c conversion1.c flags.c for_help1.c ft_big_pow.c integral_part.c number.c check_format1.c \
	  double.c flags_for_int.c for_help2.c ft_printf.c lets_work.c unordinary_flags.c conversion.c \
	  double_main.c for_help.c fractional_part.c int_flags.c norme.c work_with_bits.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "Making ft_printf..."
	@make --directory ../libft
	@cp ../libft/libft.a ./$(NAME)
	@$(CC) $(FLAGS) -c $(SRC)  -I. ft_printf.h double.h
	@ar rc $@ $(OBJ)
	@ranlib $(NAME)

clean:
	@make clean -C ../libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C ../libft
	@rm -rf $(NAME)

re: fclean all
