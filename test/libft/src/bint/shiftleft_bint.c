/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftleft_bint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/12 15:15:22 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint.h"

static void	shift_part(t_bint res, t_u32 shift_blocks, t_u32 shift_bits)
{
	t_u32	in;
	t_u32	out;
	t_u32	low;
	t_u32	high;
	t_u32	block;

	in = res[0] & NBR_LENGTH;
	out = in + shift_blocks + 1;
	res[0] = (res[0] & ~NBR_LENGTH) + out;
	high = 0;
	block = res[in];
	low = block >> (32 - shift_bits);
	while (in > 1)
	{
		res[out--] = high | low;
		high = block << shift_bits;
		block = res[--in];
		low = block >> (32 - shift_bits);
	}
	res[out] = high | low;
	res[--out] = block << shift_bits;
	while (out > 1)
		res[--out] = 0;
	res[0] = !res[res[0] & NBR_LENGTH] ? res[0] - 1 : res[0];
}

int			shiftleft_bint(t_bint res, t_u32 shift)
{
	t_u32	shift_blocks;
	t_u32	shift_bits;
	t_u32	out;
	t_u32	in;

	if (!shift)
		return (1);
	shift_blocks = shift / 32;
	shift_bits = shift % 32;
	if ((res[0] & NBR_LENGTH) + shift_blocks > ((res[0] & ARR_SIZE) >> 16) - 1)
		return (0);
	if (!shift_bits)
	{
		in = res[0] & NBR_LENGTH;
		out = in + shift_blocks;
		while (in > 0)
			res[out--] = res[in--];
		while (out > 0)
			res[out--] = 0;
		res[0] += shift_blocks;
	}
	else
		shift_part(res, shift_blocks, shift_bits);
	return (1);
}
