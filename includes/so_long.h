/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:01:47 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/14 14:14:07 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# define IMG_P "./assets/img/bunny1.xpm"
# define IMG_C "./assets/img/heart.xpm"
# define IMG_E "./assets/img/exit.xpm"
# define IMG_S "./assets/img/grass.xpm"
# define IMG_W "./assets/img/wall.xpm"

# define KEY_W 'w'
# define KEY_A 'a'
# define KEY_S 's'
# define KEY_D 'd'
# define KEY_ESC 0xff1b

typedef struct s_img
{
	void	*i_heart;
	void	*i_player;
	void	*i_floor;
	void	*i_wall;
	void	*i_exit;
	int		height;
	int		width;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
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
