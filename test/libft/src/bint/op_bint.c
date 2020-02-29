/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:20:05 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/12 15:14:36 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint.h"

int			sadd_32bint(t_bint res, t_u32 rig)
{
	t_u32	*r;
	t_u64	sum;

	r = res;
	sum = rig;
	while (sum && ++r < res + 1 + (res[0] & NBR_LENGTH))
	{
		sum += (t_u64)(*r);
		*r = (t_u32)(sum & 0xFFFFFFFF);
		sum >>= 32;
	}
	if (sum)
	{
		if ((res[0] & NBR_LENGTH) + 1 > ((res[0] & ARR_SIZE) >> 16) - 1)
			return (0);
		*r = (t_u32)sum;
		++res[0];
	}
	return (1);
}

static int	add(t_bint res, t_bint small, t_bint large, t_u32 max)
{
	t_u32	*c;
	t_u32	*r;
	t_u32	*l;
	t_u64	sum;

	sum = 0;
	r = res;
	c = small;
	l = large;
	while (++c < small + 1 + (small[0] & NBR_LENGTH))
	{
		sum += (t_u64)(*++l) + *c;
		*++r = sum & 0xFFFFFFFF;
		sum >>= 32;
	}
	while (++l < large + 1 + (large[0] & NBR_LENGTH))
	{
		sum += (t_u64)(*l);
		*++r = sum & 0xFFFFFFFF;
		sum >>= 32;
	}
	if (sum == 1 && max < ((res[0] & ARR_SIZE) >> 16) - 1)
		*++r = 1;
	res[0] = (res[0] & ~NBR_LENGTH) + max + sum;
	return (!sum || (sum == 1 && max < ((res[0] & ARR_SIZE) >> 16) - 1));
}

int			add_bint(t_bint res, t_bint l, t_bint r)
{
	t_u32	max;

	max = (l[0] & NBR_LENGTH) > (r[0] & NBR_LENGTH) ?
			(l[0] & NBR_LENGTH) : (r[0] & NBR_LENGTH);
	if (max > ((res[0] & ARR_SIZE) >> 16) - 1)
		return (0);
	bintclr(res);
	return (add(res, (l[0] & NBR_LENGTH) < (r[0] & NBR_LENGTH) ? l : r,
			(l[0] & NBR_LENGTH) < (r[0] & NBR_LENGTH) ? r : l, max));
}

static int	mult(t_bint res, t_bint s, t_bint l, t_u32 limit)
{
	t_u64	prod;
	t_u32	i;
	t_u32	j;

	i = 0;
	while (++i <= (s[0] & NBR_LENGTH))
	{
		if (s[i])
		{
			j = 0;
			prod = 0;
			while (++j <= (l[0] & NBR_LENGTH))
			{
				prod += res[j] + (l[j] * (t_u64)s[i]);
				res[j] = prod & 0xFFFFFFFF;
				prod >>= 32;
			}
			if (j >= limit)
				return (0);
			res[j] = (t_u32)(prod & 0xFFFFFFFF);
		}
		res++;
	}
	return (1);
}

int			mult_bint(t_bint res, t_bint l, t_bint r)
{
	t_u32	max;

	max = (l[0] & NBR_LENGTH) + (r[0] & NBR_LENGTH);
	if (l == res || r == res || max > BINT_SIZE - 1)
		return (0);
	bintclr(res);
	if (!mult(res, (l[0] & NBR_LENGTH) < (r[0] & NBR_LENGTH) ? l : r,
		(l[0] & NBR_LENGTH) < (r[0] & NBR_LENGTH) ? r : l,
		(res[0] & ARR_SIZE) >> 16))
		return (0);
	res[0] = (res[0] & ~NBR_LENGTH)
			+ (max > 0 && res[max] == 0 ? max - 1 : max);
	return (1);
}
