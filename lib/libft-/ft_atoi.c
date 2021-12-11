/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 01:12:03 by jmilson-          #+#    #+#             */
/*   Updated: 2021/09/13 23:35:45 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *src)
{
	size_t	i;
	int		rslt;
	int		m;

	i = 0;
	m = 1;
	rslt = 0;
	if (src == 0)
		return (0);
	while (src[i] == ' ' || src[i] == '\t' || src[i] == '\n'
		|| src[i] == '\r' || src[i] == '\v' || src[i] == '\f')
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			m = -1;
		i++;
	}
	while (ft_isdigit(src[i]))
	{
		rslt = (rslt * 10) + (src[i] - 48);
		i++;
	}
	return (rslt * m);
}
