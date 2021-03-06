/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:05:51 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/14 04:54:29 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init_var(t_game *game)
{
	game->p_x = 0;
	game->p_y = 0;
	game->score = 0;
	game->exit = 0;
	game->player = 0;
	game->row = 0;
	game->col = 0;
	game->end_game = 0;
	game->side = KEY_D;
	game->move = 0;
}

void	start_win(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->col * 32,
			game->row * 32, "The way back home");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments.\n\n");
		exit(1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0)
	{
		printf("Error\nYou must use a '.ber' file.\n\n");
		exit(2);
	}
	init_var(&game);
	open_map(argv[1], &game);
	valid_matrix(&game);
	valid_map(&game);
	game.mlx_ptr = mlx_init();
	start_win(&game);
	start_img(&game);
	mlx_loop_hook(game.mlx_ptr, render_img, &game);
	mlx_hook(game.win_ptr, 17, 0L, free_img, &game);
	mlx_hook(game.win_ptr, 02, 1L << 0, which_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
