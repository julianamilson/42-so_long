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

#include "../includes/so_long_bonus.h"

int	free_img(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_loop_end(game->mlx_ptr);
	mlx_destroy_image(game->mlx_ptr, game->img.i_carrot);
	mlx_destroy_image(game->mlx_ptr, game->img.i_exit);
	mlx_destroy_image(game->mlx_ptr, game->img.i_floor);
	mlx_destroy_image(game->mlx_ptr, game->img.i_pl);
	mlx_destroy_image(game->mlx_ptr, game->img.i_pr);
	mlx_destroy_image(game->mlx_ptr, game->img.i_v);
	mlx_destroy_image(game->mlx_ptr, game->img.i_wall);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_matrix(game);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

void	start_img(t_game *game)
{
	game->img.i_wall = mlx_xpm_file_to_image(game->mlx_ptr, IMG_W,
			&game->img.height, &game->img.width);
	game->img.i_pl = mlx_xpm_file_to_image(game->mlx_ptr, IMG_PL,
			&game->img.height, &game->img.width);
	game->img.i_pr = mlx_xpm_file_to_image(game->mlx_ptr, IMG_PR,
			&game->img.height, &game->img.width);
	game->img.i_v = mlx_xpm_file_to_image(game->mlx_ptr, IMG_V,
			&game->img.height, &game->img.width);
	game->img.i_floor = mlx_xpm_file_to_image(game->mlx_ptr, IMG_S,
			&game->img.height, &game->img.width);
	game->img.i_exit = mlx_xpm_file_to_image(game->mlx_ptr, IMG_E,
			&game->img.height, &game->img.width);
	game->img.i_carrot = mlx_xpm_file_to_image(game->mlx_ptr, IMG_C,
			&game->img.height, &game->img.width);
}

static void	side_player(t_game *game, int line, int col)
{
	if (game->side == KEY_A)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.i_pl,
			col * 32, line * 32);
	else if (game->side == KEY_D)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.i_pr,
			col * 32, line * 32);
}

static void	verify_char(int line, int col, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.i_wall, col * 32, line * 32);
	if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.i_floor, col * 32, line * 32);
	if (c == 'P')
		side_player(game, line, col);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.i_exit, col * 32, line * 32);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.i_carrot, col * 32, line * 32);
	if (c == 'V')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.i_v, col * 32, line * 32);
}

int	render_img(t_game *game)
{
	char	*move;
	int		line;
	int		col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			verify_char(line, col, game->map[line][col], game);
			col++;
		}
		line++;
	}
	move = ft_itoa(game->move);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0xF0F8FF,
		"Movements: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 10, 0xF0F8FF, move);
	free(move);
	return (0);
}
