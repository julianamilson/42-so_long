/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:29:17 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 01:10:34 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	valid_matrix(t_game *game)
{
	int	col;
	int	line;
	int	size;
	
	col = 0;
	line = 0;
	size = 0;
	size = ft_strlen(game->map[0]);
	while (game->map[line] != 0)
	{
		col = ft_strlen(game->map[line]);
		if (col != size)
		{
			printf("Invalid map! Nao eh um retangulo >:c");
			exit(1);
		}
		line++;
	}
}

void	valid_char(t_game *game, char c, int line, int col)
{
	if (c == 'C')
	{
		game->score++;
	}
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->p_x = line;
		game->p_y = col;
	}
	else if (c == '1' || c == '0')
		return ;
	else
	{
		printf("Invalid map!");
		exit(0);
	}
}

void	move_map(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			valid_char(game, game->map[line][col], line, col);
			col++;
		}
		line++;
	}
	if (line == col)
		exit(2);
	if (game->score == 0 || game->exit == 0 || game->player != 1)
		exit(3);
}

/* 1. mapa tem que ser do tipo .ber
   
   2. soh pode ter ATÉ 5 tipos de characteres diferentes: 0, 1, C, E (0 for an 
   empty space, 1 for a wall, C for a collectible, E for map exit and P for 
   the player’s starting position.) 
   
   3. tem que ter muros em volta

   4. tem que ter uma saida, posicao e PELO MENOS UM ITEM pra coletar.

   5. tem que ser retangular

   SE O MAPA FALHAR EM ALGUM DESTES REQUISITOS devolver um "Error\n" e 
   especificar qual tipo de erro que foi.

   obs. nao precisa verificar se tem caminho valido!
   
*/