/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:16:26 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 01:16:08 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	start_win(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->col * 32,
			game->row * 32, "Harry no uchi");
}
