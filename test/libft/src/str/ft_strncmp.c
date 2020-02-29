/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:26:23 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/08 11:06:04 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_uchar	c1;
	t_uchar	c2;

	c1 = (t_uchar)*s1;
	c2 = (t_uchar)*s2;
	if (!n)
		return (0);
	else if (c1 != c2 || c1 == 0 || c2 == 0)
		return (c1 - c2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
