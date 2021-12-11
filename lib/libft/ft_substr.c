/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:28:33 by jmilson-          #+#    #+#             */
/*   Updated: 2021/09/17 01:46:56 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len >= slen)
		len = slen - start;
	if (slen >= start)
	{
		sub = (char *)ft_calloc(len + 1, sizeof(char));
		if (sub == NULL)
			return (NULL);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	else
		sub = ft_calloc(1, 1);
	return (sub);
}
