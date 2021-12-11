# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 20:30:07 by jmilson-          #+#    #+#              #
#    Updated: 2021/12/09 23:33:05 by jmilson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./lib/libft/libft.a
LIBFT_PATH = ./lib/libft
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft

CFLAGS = -g -Wall -Wextra -Werror

CC = gcc

AR = ar rcs

SRC = check_map.c \
	image.c \
	map.c \
	move.c \
	so_long.c \
	window.c

SRC_DIR = ./sources
SRC:= $(addprefix $(SRC_DIR)/,$(SRC))


INCLUDES_DIR = ./includes ./lib/libft
INCLUDES = $(addprefix -I, $(INCLUDES_DIR))

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS) -lmlx -Ilmlx -lXext -lX11

%.o:$(SRC_DIR)%.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBFT_FLAGS) -lmlx -Ilmlx -lXext -lX11

$(LIBFT):
		make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

go:	all
	./so_long

.PHONY : all clean fclean re
