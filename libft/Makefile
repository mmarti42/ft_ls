# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartole <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 22:08:51 by abartole          #+#    #+#              #
#    Updated: 2019/07/18 13:27:33 by abartole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a
SRCDIR = ./
OBJDIR = ./
HEADDIR = ./
HEADER = -I $(HEADDIR)
SRC = $(patsubst $(SRCDIR)%, %, $(wildcard $(SRCDIR)*.c))

OBJ = $(SRC:.c=.o)

vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
