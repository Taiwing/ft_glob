/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:26:56 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 19:50:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef NO_COLLEC

char	**ft_strsplit(char const *s, char c)
{
	static int	i = 0;
	int			l;
	char		*cpy;
	char		**tb;

	if (!s)
		return (NULL);
	tb = NULL;
	cpy = NULL;
	i = i == -1 ? 1 : i + 1;
	while (*s == c)
		++s;
	l = 0;
	while (s[l] && s[l] != c)
		++l;
	if (l && !(cpy = ft_strndup(s, l)))
		i = -1;
	if (i != -1 && !(tb = cpy ? ft_strsplit(s + l, c)
		: (char **)ft_secmalloc(i * sizeof(char *))))
		i = -1;
	if (i == -1 && cpy)
		free(cpy);
	else if (i != -1)
		tb[--i] = cpy;
	return (tb);
}

#else

char	**ft_strsplit(char const *s, char c)
{
	static int	i = 0;
	int			l;
	char		*cpy;
	char		**tb;

	if (!s)
		return (NULL);
	tb = NULL;
	cpy = NULL;
	i = i == -1 ? 1 : i + 1;
	while (*s == c)
		++s;
	l = 0;
	while (s[l] && s[l] != c)
		++l;
	if (l && !(cpy = ft_strndup(s, l)))
		i = -1;
	if (i != -1 && !(tb = cpy ? ft_strsplit(s + l, c)
		: (char **)ft_secmalloc(i * sizeof(char *))))
		i = -1;
	if (i == -1 && cpy)
		free(ft_heap_collector(cpy, FT_COLLEC_GET));
	else if (i != -1)
		tb[--i] = cpy;
	return (tb);
}

#endif
