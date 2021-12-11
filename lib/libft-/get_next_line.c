/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:55:00 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/09 20:43:31 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*verify(char **bbackup)
{
	char	*line;
	char	*temp;

	if (**bbackup == '\n' && **bbackup + 1 != '\0')
	{
		line = ft_strdup("\n");
		temp = *bbackup;
		*bbackup = ft_strdup(&temp[1]);
		free(temp);
		temp = NULL;
		return (line);
	}
	if (!**bbackup)
	{
		free(*bbackup);
		*bbackup = NULL;
		return (NULL);
	}
	line = *bbackup;
	*bbackup = NULL;
	return (line);
}

static char	*get_line(char **bbackup, size_t bef_n)
{
	char	*line;
	char	*temp;

	if (bef_n == 0)
		return (verify(bbackup));
	temp = *bbackup;
	line = ft_substr(temp, 0, bef_n + 1);
	*bbackup = ft_strdup(temp + bef_n + 1);
	free(temp);
	return (line);
}

static char	*get_content(char **bbackup, char *buffer, int fd)
{
	char	*temp;
	int		read_chars;

	while (!ft_strchr(*bbackup, '\n'))
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars <= 0)
		{
			free(buffer);
			return (get_line(bbackup, 0));
		}
		buffer[read_chars] = '\0';
		temp = *bbackup;
		*bbackup = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (get_line(bbackup, ft_strclen(*bbackup, '\n')));
}

char	*get_next_line(int fd)
{
	static char	*bbackup;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!bbackup)
		bbackup = ft_strdup("");
	return (get_content(&bbackup, buffer, fd));
}
