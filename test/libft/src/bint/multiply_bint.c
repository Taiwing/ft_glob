/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_bint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:58:07 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/12 15:12:40 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint.h"

int			mult_32bint(t_bint res, t_bint lef, t_u32 rig)
{
	t_u32	*r;
	t_u32	*l;
	t_u64	prod;

	prod = 0;
	r = res + 1;
	l = lef + 1;
	while (l < lef + 1 + (lef[0] & NBR_LENGTH))
	{
		prod += (t_u64)(*l++) * rig;
		*r++ = (t_u32)(prod & 0xFFFFFFFF);
		prod >>= 32;
	}
	if (prod)
	{
		if ((lef[0] & NBR_LENGTH) + 1 > ((res[0] & ARR_SIZE) >> 16))
			return (0);
		*r = (t_u32)prod;
	}
	res[0] = (res[0] & ~NBR_LENGTH) + (lef[0] & NBR_LENGTH) + (prod != 0);
	return (1);
}

int			mult2_bint(t_bint res, t_bint in)
{
	t_u32	*i;
	t_u32	*r;
	t_u32	carry;
	t_u32	limit;

	i = in;
	r = res;
	carry = 0;
	limit = ((res[0] & ARR_SIZE) >> 16) - 1;
	if (limit < (in[0] & NBR_LENGTH))
		return (0);
	while (++i < in + 1 + (in[0] & NBR_LENGTH))
	{
		*++r = (*i << 1) | carry;
		carry = *i >> 31;
	}
	if (carry)
	{
		if (r - res + 1 > limit)
			return (0);
		*++r = carry;
	}
	res[0] = (res[0] & ~NBR_LENGTH) + (in[0] & NBR_LENGTH) + (carry != 0);
	return (1);
}

int			smult2_bint(t_bint res)
{
	t_u32	*r;
	t_u32	cur;
	t_u32	carry;
	t_u32	limit;

	r = res;
	carry = 0;
	limit = ((res[0] & ARR_SIZE) >> 16) - 1;
	while (++r < res + 1 + (res[0] & NBR_LENGTH))
	{
		cur = *r;
		*r = (cur << 1) | carry;
		carry = cur >> 31;
	}
	if (carry)
	{
		if (r - res + 1 > limit)
			return (0);
		*r = carry;
		++res[0];
	}
	return (1);
}

int			smult10_bint(t_bint res)
{
	t_u32	*r;
	t_u64	prod;

	r = res;
	prod = 0;
	while (++r < res + 1 + (res[0] & NBR_LENGTH))
	{
		prod += (t_u64)(*r) * 10ull;
		*r = (t_u32)(prod & 0xFFFFFFFF);
		prod >>= 32;
	}
	if (prod)
	{
		if (r - res + 1 > ((res[0] & ARR_SIZE) >> 16) - 1)
			return (0);
		*r = (t_u32)prod;
		++res[0];
	}
	return (1);
}
