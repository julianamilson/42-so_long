/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:15:09 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 01:32:50 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_img(t_game *game)
{
	game->img.i_wall = mlx_xpm_file_to_image(game->mlx_ptr, IMG_W, &game->img.height, &game->img.width);
	game->img.i_player = mlx_xpm_file_to_image(game->mlx_ptr, IMG_P, &game->img.height, &game->img.width);
	game->img.i_floor = mlx_xpm_file_to_image(game->mlx_ptr, IMG_S, &game->img.height, &game->img.width);
	game->img.i_exit = mlx_xpm_file_to_image(game->mlx_ptr, IMG_E, &game->img.height, &game->img.width);
	game->img.i_carrot = mlx_xpm_file_to_image(game->mlx_ptr, IMG_C, &game->img.height, &game->img.width);
}

int	render_img(t_game *game)
{
	int line;
	int	col;
	
	start_img(game);
	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.i_wall, col * 32, line * 32);
			if (game->map[line][col] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.i_floor, col * 32, line * 32);
			if (game->map[line][col] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.i_player, col * 32, line * 32);
			if (game->map[line][col] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.i_exit, col * 32, line * 32);
			if (game->map[line][col] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.i_carrot, col * 32, line * 32);	
			col++;
		}
		line++;
	}
	return (0);	
}