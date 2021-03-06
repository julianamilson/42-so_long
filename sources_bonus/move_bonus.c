/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:16:25 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/14 00:42:15 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	end_game(t_game *game)
{
	char	*move;

	move = ft_itoa(game->move++);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 20, 10, 0xF0F8FF,
		"Movements: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 10, 0xF0F8FF, move);
	if (game->end_game == 1)
		printf("\n\nYOU WIN!!\nIt was fun! Welcome back home!! ~(n v n )~\n\n");
	if (game->end_game == -1)
	{
		printf("\n\nYOU LOSE!\nOh, no! Poor bunny!! ( T ^ T)\n\n");
		game->end_game = 1;
	}
	game->map[game->p_x][game->p_y] = '0';
	free(move);
	return (-1);
}

static int	valid_move(t_game *game, int col, int line, int pressed_key)
{
	if (game->map[line][col] == '1')
		return (-1);
	if (game->map[line][col] == 'C')
		game->score--;
	if (game->map[line][col] == 'E' && game->score == 0)
	{
		game->map[line][col] = 'H';
		game->end_game = 1;
		return (end_game(game));
	}
	else if (game->map[line][col] == 'E')
		return (-1);
	if (game->map[line][col] == 'V')
	{
		game->map[line][col] = 'L';
		game->end_game = -1;
		return (end_game(game));
	}
	if (pressed_key != KEY_W && pressed_key != KEY_S && pressed_key != KEY_A
		&& pressed_key != KEY_D)
		return (-1);
	else
		return (1);
}

static void	move(t_game *game, int col, int line, int pressed_key)
{
	int	valid;
	int	tcol;
	int	tline;

	tcol = game->p_y;
	tline = game->p_x;
	valid = valid_move(game, col, line, pressed_key);
	if (valid != -1)
	{
		game->map[tline][tcol] = '0';
		game->p_y = col;
		game->p_x = line;
		game->map[line][col] = 'P';
		game->move++;
	}
}

int	which_key(int pressed_key, t_game *game)
{
	int	col;
	int	line;

	col = game->p_y;
	line = game->p_x;
	if (pressed_key == KEY_A)
	{
		game->side = KEY_A;
		col--;
	}
	else if (pressed_key == KEY_W)
		line--;
	else if (pressed_key == KEY_S)
		line++;
	else if (pressed_key == KEY_D)
	{
		game->side = KEY_D;
		col++;
	}
	else if (pressed_key == KEY_ESC)
		free_img(game);
	if (game->end_game != 1)
		move(game, col, line, pressed_key);
	return (0);
}
