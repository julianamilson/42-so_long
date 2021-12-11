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
