# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 20:30:07 by jmilson-          #+#    #+#              #
#    Updated: 2021/12/13 16:18:51 by jmilson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus


LIBFT = libft/libft.a
LIBFT_PATH = libft
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft

CFLAGS = -Wall -Wextra -Werror
MLXF = -lmlx -Ilmlx -lXext -lX11

CC = gcc

SRC = check_map.c \
	image.c \
	map.c \
	move.c \
	so_long.c

SRC_BONUS = check_map_bonus.c \
	image_bonus.c \
	map_bonus.c \
	move_bonus.c \
	so_long_bonus.c

SRC_DIR = ./sources
SRC:= $(addprefix $(SRC_DIR)/,$(SRC))

SRC_DIR_BONUS = ./sources_bonus
SRC_BONUS:= $(addprefix $(SRC_DIR_BONUS)/,$(SRC_BONUS))

INCLUDES_DIR = ./includes ./lib/libft
INCLUDES = $(addprefix -I, $(INCLUDES_DIR))

OBJS = $(SRC:%.c=%.o)

OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS) $(MLXF)

%.o:$(SRC_DIR)%.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBFT_FLAGS) $(MLXF)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
		$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(INCLUDES) $(LIBFT_FLAGS) $(MLXF)

%.o:$(SRC_DIR_BONUS)%.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBFT_FLAGS) $(MLXF)

$(LIBFT):
		make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C $(LIBFT_PATH)

re: fclean all

re_bonus: fclean bonus

.PHONY : all clean fclean re bonus re_bonus
