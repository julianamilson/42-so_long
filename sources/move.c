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

int	which_key(int pressed_key, t_game *game)
{
	int	col;
	int	line;

	col = game->p_x;
	line = game->p_y;
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
	return (0);
}

/*
	1. W, A, S e D movimentam o char

	2. Nao pode atravessar paredes (kkkkk)

	3. Sumir quando encostar em inimigo (aparecer game over), sumir na posição
	da porta (you did it!)

	4. mostrar quantidade de movimentos.

	Obs. do que entendi, soh ganha o jogo se coletar todos os itens E se
	fizer o caminho mais curto (verificar!)
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
