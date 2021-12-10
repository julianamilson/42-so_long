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