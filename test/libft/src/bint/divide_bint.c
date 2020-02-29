/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_bint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:00:29 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/06 15:39:14 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint.h"

static void	substract_bintxu32(t_bint res, t_bint b, t_u32 q)
{
	t_u32	i;
	t_u64	prod;
	t_u64	diff;

	i = 0;
	prod = 0;
	diff = 0;
	while (++i <= (b[0] & NBR_LENGTH))
	{
		prod += (t_u64)b[i] * (t_u64)q;
		diff = (t_u64)res[i] - (prod & 0xFFFFFFFF) - diff;
		res[i] = diff & 0xFFFFFFFF;
		prod >>= 32;
		diff = (diff >> 32) & 1;
	}
	while ((res[0] & NBR_LENGTH) > 1 && !res[res[0] & NBR_LENGTH])
		--res[0];
}

t_u32		divmod_max9_bint(t_bint dividend, t_bint divisor)
{
	t_u32	quotient;

	if (!(divisor[0] & NBR_LENGTH) || divisor[divisor[0] & NBR_LENGTH] < 8
		|| divisor[divisor[0] & NBR_LENGTH] > 0xFFFFFFFE
		|| (dividend[0] & NBR_LENGTH) > (divisor[0] & NBR_LENGTH))
		return (10);
	if ((divisor[0] & NBR_LENGTH) > (dividend[0] & NBR_LENGTH))
		return (0);
	quotient = dividend[dividend[0] & NBR_LENGTH]
			/ ((divisor[divisor[0] & NBR_LENGTH]) + 1);
	if (quotient)
		substract_bintxu32(dividend, divisor, quotient);
	if (bintcmp(dividend, divisor) >= 0)
	{
		++quotient;
		substract_bintxu32(dividend, divisor, 1);
	}
	return (quotient);
}
