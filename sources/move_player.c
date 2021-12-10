/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:38:25 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 19:53:35 by jmilson-         ###   ########.fr       */
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
