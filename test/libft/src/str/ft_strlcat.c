/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:25:58 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/08 09:41:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		dlen;

	s = src;
	d = dest;
	while (size && *d)
	{
		d++;
		size--;
	}
	dlen = d - dest;
	if (size == 0)
		return (dlen + ft_strlen(src));
	while (*s)
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}
