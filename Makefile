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

SRC = $(addprefix $(DIR_SRC), err.c main.c objects.c recursive_search.c sort.c)

OBJ = err.o main.o objects.o recursive_search.o sort.o

HEADER = $(addprefix $(DIR_HEADER), ft_ls.h)

LIB = ./libft/libft.a

NAME = ft_ls

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(LIB) $(OBJ)
	$(GCC) -o $@ $^
$(LIB):
	make -C ./libft
%.o: $(DIR_SRC)%.c $(HEADER)
	$(GCC) -I. $(HEADER) -c $<
clean:
	rm -rf $(OBJ)
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
re: fclean all
