/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:53:23 by jmilson-          #+#    #+#             */
/*   Updated: 2021/09/23 17:34:30 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_brain(char *s, size_t i, int n)
{
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	i = i - 1;
	if (n > 9)
	{
		while (n != 0)
		{
			s[i] = (n % 10) + 48;
			n = n / 10;
			i--;
		}
	}
	else
		s[i] = n + 48;
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_counter(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (ft_brain(str, len, n));
}
