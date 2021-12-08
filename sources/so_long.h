/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:01:47 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/08 22:27:42 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	// x;
	// y;
	// count;
	// hero;
	// collect;
	// exit;
	// enemy;
} t_map;

typedef struct s_screen
{
	// carrot;
	// hero;
	// enemy;
	// floor;
	// exit;
	// wall;	
} t_screen;

# define IMG_P "../assets/img/bunny1.xpm"
# define IMG_C "../assets/img/carrot.xpm"
# define IMG_E "../assets/img/exit.xpm"
# define IMG_S "../assets/img/grass.xpm"
# define IMG_W "../assets/img/wall.xpm"

	// check_map();
	// exit();
	// move();
	// free_mem();

#endif
