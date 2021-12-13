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

void	message_exit(char *s, t_game *game)
{
	printf("Error\n%s\n\n", s);
	free_matrix(game);
	exit(42);
}

static void	valid_walls(t_game *game)
{
	int	i;
	int	c;

	i = 0;
	while (game->map[i])
	{
		c = 0;
		while (game->map[i][c])
		{
			if (game->map[0][c] != '1' || game->map[game->row - 1][c] != '1')
				message_exit("Surround your map with walls!", game);
			if (game->map[i][0] != '1' || game->map[i][game->col - 1] != '1')
				message_exit("Surround your map with walls!", game);
			c++;
		}
		i++;
	}
}

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
			message_exit("Your map is not rectangular!", game);
		line++;
	}
	valid_walls (game);
}

static void	valid_char(t_game *game, char c, int line, int col)
{
	if (c == 'C')
		game->score++;
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
		message_exit("Allowed characters: 1, 0, C, E, P", game);
}

void	valid_map(t_game *game)
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
	if (game->score == 0)
		message_exit("There's no collectables. (C)", game);
	else if (game->exit == 0)
		message_exit("There's no exit. (E)", game);
	else if (game->exit > 1)
		message_exit("You just need one exit per map. (E)", game);
	else if (game->player == 0)
		message_exit("There's no player. (P)", game);
	else if (game->player > 1)
		message_exit("You just need one player per map. (P)", game);
}
