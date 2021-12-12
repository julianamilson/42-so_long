/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:01:47 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 19:41:10 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

# define IMG_PL "./assets/img/bunny.xpm"
# define IMG_PR "./assets/img/bunny1.xpm"
# define IMG_C "./assets/img/carrot.xpm"
# define IMG_E "./assets/img/exit.xpm"
# define IMG_S "./assets/img/grass.xpm"
# define IMG_W "./assets/img/wall.xpm"
# define IMG_V "./assets/img/v.xpm"

# define KEY_W 'w'
# define KEY_A 'a'
# define KEY_S 's'
# define KEY_D 'd'
# define KEY_ESC 0xff1b

typedef struct s_img
{
	void	*i_carrot;
	void	*i_pr;
	void	*i_pl;
	void	*i_floor;
	void	*i_wall;
	void	*i_exit;
	void	*i_v;
	int		height;
	int		width;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		side;
	int		row;
	int		col;
	int		exit;
	int		score;
	int		player;
	int		p_y;
	int		p_x;
	int		end_game;
	int		move;
}	t_game;

void	open_map(char *argv, t_game *game);
void	valid_map(t_game *game);
void	valid_matrix(t_game *game);
void	start_img(t_game *game);
int		render_img(t_game *game);
int		which_key(int pressed_key, t_game *game);
void	free_matrix(t_game *game);
int		free_img(t_game *game);
void	message_exit(char *s, t_game *game);

#endif