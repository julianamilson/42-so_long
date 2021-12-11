/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 01:51:17 by jmilson-          #+#    #+#             */
/*   Updated: 2021/09/15 19:26:03 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < dstsize)
		i++;
	while (((i + j + 1) < dstsize) && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
