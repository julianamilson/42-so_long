/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:05:51 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 02:06:16 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_function(t_game *game)
{
	game->p_x = 0;
	game->p_y = 0;
	game->score = 0;
	game->exit = 0;
	game->player = 0;
	game->row = 0;
	game->col = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_function(&game);
	game.mlx_ptr = mlx_init();
	if (argc != 2)
		return (0);
	read_map(argv[1], &game);
	move_map(&game);
	valid_matrix(&game);
	if (game.mlx_ptr == NULL)
		exit(42);
	start_win(&game);
	start_img(&game);
	mlx_loop_hook(game.mlx_ptr, render_img, &game);
	mlx_hook(game.win_ptr, 02, 1L<<0, which_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
