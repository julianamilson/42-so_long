/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:05:51 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 01:49:27 by jmilson-         ###   ########.fr       */
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
	printf("init func\n");
	game.mlx_ptr = mlx_init();
	printf("mlx init\n");
	if (argc != 2)
		return (0);
	read_map(argv[1], &game);
	move_map(&game);
	printf("move map\n");
	valid_matrix(&game);
	if (game.mlx_ptr == NULL)
		exit(42);
	if (game.win_ptr == NULL)
	{
		free(game.win_ptr);
		exit(42);
	}
	printf("oi");
	start_win(&game);
	printf("start win\n");
	start_img(&game);
	printf("start img\n");
	mlx_loop_hook(game.mlx_ptr, render_img, &game);
	printf("loop hook\n");
	mlx_loop(game.mlx_ptr);
	printf("loop\n");
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
	return (0);
	//argc eh o .so_long enquanto o outro argumento eh referente ao mapa
	//verificar se o mapa eh valido
	// se a verificacao nao der certo, aparecer erro e terminar execucao
	// senao, iniciar tela e o jogo	
}
