/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:52:22 by jmilson-          #+#    #+#             */
/*   Updated: 2021/09/21 22:23:11 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_row(char const *s, char c)
{
	size_t	row;
	size_t	i;

	i = 0;
	row = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			row++;
		i++;
	}
	return (row);
}

static size_t	ft_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	rows;
	size_t	i;
	size_t	k;

	rows = ft_row(s, c);
	split = ft_calloc(sizeof(char *), (rows + 1));
	if (split == NULL)
		return (NULL);
	k = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = ft_words(s, c);
			split[k] = ft_substr(s, 0, i);
			if (!split[k])
				return (NULL);
			s += i;
			k++;
		}
		while (*s && (*s == c))
			s++;
	}
	return (split);
}
