/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:07:44 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/10 02:28:19 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	open_map(char *argv, t_game *game)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return ;
	temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(temp, line);
		free(line);
		game->row++;
	}
	game->map = ft_split(temp, '\n');
	game->col = ft_strlen(game->map[0]);
	free(temp);
	free(line);
}
