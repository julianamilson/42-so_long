/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:16:25 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/09 21:24:05 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_move(t_game *game, int col, int line, int pressed_key)
{
	if (game->map[line][col] == '1')
		return (-1);
	if (game->map[line][col] == 'C')
		game->score--;
	if (game->map[line][col] == 'E' && game->score == 0)
	{
		game->end_game = 1;
		game->map[game->p_x][game->p_y] = '0';
		return (-1);
	}
	else if (game->map[line][col] == 'E')
		return (-1);
	if (pressed_key != KEY_W && pressed_key != KEY_S && pressed_key != KEY_A
		&& pressed_key != KEY_D)
		return (-1);
	else
		return (1);
}

void	move(t_game *game, int col, int line, int pressed_key)
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
	}
}

int	which_key(int pressed_key, t_game *game)
{
	int	col;
	int	line;

	col = game->p_y;
	line = game->p_x;
	if (pressed_key == KEY_A)
		col--;
	else if (pressed_key == KEY_W)
		line--;
	else if (pressed_key == KEY_S)
		line++;
	else if (pressed_key == KEY_D)
		col++;
	else if (pressed_key == KEY_ESC)
		free_img(game);
	if (game->end_game != 1)
		move (game, col, line, pressed_key);
	return (0);
}

/*
	1. W, A, S e D movimentam o char

	2. Nao pode atravessar paredes (kkkkk)

	3. Sumir quando encostar em inimigo (aparecer game over), sumir na posição
	da porta (you did it!)

	4. mostrar quantidade de movimentos.

	Obs. do que entendi, soh ganha o jogo se coletar todos os itens.
	Obs2. Tentar animar o char!!
*/

// int	move()
// {
// 	if (press == 'A' || press == 'a')
// 	{
// 		if (posicao[atual - 1][y] != '1')
// 			x--;
// 		printf("Movements: %d\n", count++);
// 	}
// 	else if (press == 'D' || press == 'd')
// 	{
// 		if (posicao[atual + 1][y] != '1')
// 			x++;
// 		printf("Movements: %d\n", count++);
// 	}
// 	else if (press == 'S' || press == 's')
// 	{
// 		if (posicao[x][atual + 1] != '1')
// 			y++;
// 		printf("Movements: %d\n", count++);
// 	}
// 	else if (press == 'W' || press == 'w')
// 	{
// 		if (posicao[x][atual - 1] != '1')
// 			y--;
// 		printf("Movements: %d\n", count++);
// 	}
// 	// else if (press == ESC)
// 	// { free em tudo e fecha tela }

// 	// else if (posicao[atual + 1 ou -1] == C)
// 	// {coletar}

// 	// else if (posicao[atual + 1 ou -1] == E)
// 	// {se tiver coletado, mensagem parabenizando, free em tudo, exit}
// }
