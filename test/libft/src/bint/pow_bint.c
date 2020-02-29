/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_bint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:26:58 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/12 20:32:45 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint.h"
#include "bint_mathconsts.h"

int		pow10_bint(t_bint res, t_u32 exp)
{
	t_u32	i;
	t_u32	cur[BINT_SIZE];
	t_u32	next[BINT_SIZE];

	if (exp >> 13)
		return (0);
	bintinit(cur, 0);
	bintinit(next, 0);
	if (!bintset(g_pow10_u32[exp & 0x7], cur))
		return (0);
	exp >>= 3;
	i = 0;
	while (exp)
	{
		if (exp & 1)
		{
			if (!mult_bint(next, cur, (t_bint)g_pow10_big[i])
				|| !bintcpy(next, cur))
				return (0);
		}
		++i;
		exp >>= 1;
	}
	return (bintcpy(cur, res));
}

int		multpow10_bint(t_bint res, t_bint in, t_u32 exp)
{
	t_u32	tmp[BINT_SIZE];

	bintinit(tmp, 0);
	return (pow10_bint(tmp, exp) && mult_bint(res, tmp, in));
}

int		pow2_bint(t_bint res, t_u32 exp)
{
	t_u32	i;
	t_u32	index;

	index = exp / 32;
	if (index > ((res[0] & ARR_SIZE) >> 16) - 1)
		return (0);
	i = 0;
	while (++i <= index + 1)
		res[i] = 0;
	res[index + 1] |= 1 << (exp % 32);
	res[0] = (res[0] & ~NBR_LENGTH) + index + 1;
	return (1);
}
