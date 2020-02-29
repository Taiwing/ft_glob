/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_and_ceil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:23:52 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/13 21:30:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint_mathconsts.h"

int				ft_ceil(double d)
{
	if (d - (int)d == 0.0f || d < 0.0f)
		return ((int)d);
	else
		return ((int)d + 1);
}

unsigned int	logbase2_32(unsigned int nbr)
{
	unsigned int	tmp;

	tmp = nbr >> 24;
	if (tmp)
		return (24 + g_logtable[tmp]);
	tmp = nbr >> 16;
	if (tmp)
		return (16 + g_logtable[tmp]);
	tmp = nbr >> 8;
	if (tmp)
		return (8 + g_logtable[tmp]);
	return (g_logtable[nbr]);
}

unsigned int	logbase2_64(unsigned long int nbr)
{
	if (nbr >> 32)
		return (32 + logbase2_32((unsigned int)(nbr >> 32)));
	return (logbase2_32((unsigned int)nbr));
}
