/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:05:11 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/19 23:44:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dragon4.h"
#include "bint.h"
#include "log_and_ceil.h"

static int	scale_val(t_bint scale, t_bint scaled_val, t_fltinf *info)
{
	int		digit_exp;
	t_u32	tmp[BINT_SIZE];

	bintinit(tmp, 0);
	bintinit(scale, 0);
	bintinit(scaled_val, 0);
	bintset(info->mantissa, scaled_val);
	shiftleft_bint(scaled_val, info->exp > 0 ? info->exp + 1 : 1);
	pow2_bint(scale, info->exp > 0 ? 1 : 1 - info->exp);
	digit_exp = ft_ceil(((int)info->log2 + info->exp) * LOG10_2 - 0.69);
	if (info->conv == 'f' || info->conv == 'F')
		digit_exp = digit_exp <= -info->prec ? 1 - info->prec : digit_exp;
	if (digit_exp > 0)
		multpow10_bint(tmp, scale, digit_exp);
	else if (digit_exp < 0)
		multpow10_bint(tmp, scaled_val, -digit_exp);
	if (digit_exp)
		bintcpy(tmp, digit_exp > 0 ? scale : scaled_val);
	if (bintcmp(scaled_val, scale) >= 0)
		++digit_exp;
	else
		smult10_bint(scaled_val);
	return (digit_exp);
}

static char	*ftostr(t_bint scale, t_bint scaled_val,
		t_fltinf *info, char *cur_digit)
{
	t_u32	hi_block;
	int		prec;
	int		cutoff_exp;

	prec = info->prec + info->digit_exp > 16383 ?
	16383 - info->digit_exp : info->prec;
	cutoff_exp = info->conv == 'f' || info->conv == 'F' ?
		-prec : info->digit_exp - prec - 1;
	hi_block = scale[scale[0] & NBR_LENGTH];
	if (hi_block < 8 || hi_block > 429496729)
	{
		prec = (32 + 27 - logbase2_32(hi_block)) % 32;
		shiftleft_bint(scale, (t_u32)prec);
		shiftleft_bint(scaled_val, (t_u32)prec);
	}
	while (1)
	{
		--info->digit_exp;
		info->digit = divmod_max9_bint(scaled_val, scale);
		if (!(scaled_val[0] & NBR_LENGTH) || (info->digit_exp == cutoff_exp))
			break ;
		*cur_digit++ = (char)(48 + info->digit);
		smult10_bint(scaled_val);
	}
	return (cur_digit);
}

static char	*round_up9(char *cur_digit, char *buf, int *exp10, int conv)
{
	char	*last_digit;

	last_digit = cur_digit;
	while (1)
	{
		if (cur_digit == buf)
		{
			*cur_digit++ = '1';
			++(*exp10);
			break ;
		}
		--cur_digit;
		if (*cur_digit != '9')
		{
			*cur_digit = *cur_digit + 1;
			++cur_digit;
			break ;
		}
		else
			*cur_digit = '0';
	}
	return (conv == 'g' || conv == 'G' ? last_digit : cur_digit);
}

int			dragon4(t_fltinf *info, char *buf)
{
	t_u32	scaled_val[BINT_SIZE];
	t_u32	scale[BINT_SIZE];
	char	*cur_digit;
	int		round_down;
	int		cmp;

	if (!info->mantissa)
	{
		*buf = '0';
		info->exp10 = 0;
		return (1);
	}
	info->digit_exp = scale_val(scale, scaled_val, info);
	info->exp10 = info->digit_exp - 1;
	cur_digit = ftostr(scale, scaled_val, info, buf);
	smult2_bint(scaled_val);
	cmp = bintcmp(scaled_val, scale);
	round_down = !cmp ? !(info->digit & 1) : cmp < 0;
	if (round_down)
		*cur_digit++ = (char)(48 + info->digit);
	else if (info->digit < 9)
		*cur_digit++ = (char)(48 + info->digit + 1);
	else
		cur_digit = round_up9(cur_digit, buf, &(info->exp10), info->conv);
	return ((int)(cur_digit - buf));
}
