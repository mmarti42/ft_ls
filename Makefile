# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 13:43:25 by lshellie          #+#    #+#              #
#    Updated: 2019/07/21 14:06:23 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC = sources/

DIR_HEADER = headers/

SRC = $(addprefix $(DIR_SRC), err.c main.c objects.c recursive_search.c sort.c convert_params.c convert_time.c long_output.c columns.c norme.c print.c)

OBJ = err.o main.o objects.o recursive_search.o sort.o convert_params.o convert_time.o long_output.o columns.o norme.o print.o

HEADER = $(addprefix $(DIR_HEADER), ft_ls.h)

LIB = ./libft/libft.a

PRINTF = ./printf/libftprintf.a

NAME = ft_ls

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(LIB) $(PRINTF) $(OBJ)
	$(GCC) -o $@ $^
$(LIB):
	make -C ./libft
$(PRINTF):
	make -C ./printf
%.o: $(DIR_SRC)%.c $(HEADER)
	$(GCC) -I. $(HEADER) -c $<
clean:
	rm -rf $(OBJ)
	make clean -C ./printf
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./printf
	make fclean -C ./libft
re: fclean all
