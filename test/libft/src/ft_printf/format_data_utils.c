/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:01:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 16:01:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_data.h"
#include "libft.h"

void		apply_fw(t_pdata *l, t_params *conv, int fdat[4], int *size)
{
	char	*t;

	if ((t = ft_strchr("dbBouxXpPeEfFgG", conv->type)) && *size < conv->fw
		&& conv->flags & F_ZERO && !(conv->flags & F_MINUS)
		&& (conv->prec < 0 || ft_strchr("eEfFgG", conv->type)))
	{
		fdat[ZPAD] += conv->fw - *size - (l->buf[0] == '-');
		if (l->buf[0] == '-')
		{
			fdat[SIGN] = '-';
			l->buf[0] = '0';
		}
	}
	else if (!t && *size < conv->fw && conv->flags & F_ZERO
			&& !(conv->flags & F_MINUS) && conv->type != 't')
		fdat[ZPAD] = conv->fw - *size;
	else if (*size < conv->fw && conv->type != 't')
	{
		fdat[SPAD] = conv->fw - *size;
		fdat[SPAD] *= conv->flags & F_MINUS ? -1 : 1;
	}
	else
		return ;
	*size = conv->fw;
}

void		apply_sign(t_pdata *l, t_params *conv, int fdat[4], int *size)
{
	if (ft_strchr("deEfFgG", conv->type) && l->buf[0] != '-'
		&& fdat[SIGN] != '-' && (conv->flags & F_PLUS || conv->flags & F_SPACE))
	{
		fdat[SIGN] = conv->flags & F_PLUS ? '+' : ' ';
		(*size)++;
	}
}

static void	apply_prec(t_pdata *l, t_params *conv, int *size, int fdat[4])
{
	fdat[ZPAD] = conv->prec - *size;
	if (l->buf[0] == '-')
	{
		fdat[SIGN] = '-';
		l->buf[0] = '0';
		(*size)++;
	}
	*size = *size + fdat[ZPAD];
}

static void	apply_hash(t_pdata *l, char t, int *size, int fdat[4])
{
	if (t == 'o' && !fdat[ZPAD] && (l->buf[0] != '0' || !l->n))
	{
		fdat[ZPAD]++;
		(*size)++;
	}
	else if ((ft_strchr("bBxX", t) && !(l->buf[0] == '0' && *size == 1)
			&& *size > 0) || t == 'p' || t == 'P')
	{
		*size = *size + 2;
		if (t == 'b' || t == 'B')
			fdat[HEX] = t == 'b' ? 3 : 4;
		else
			fdat[HEX] = t == 'x' || t == 'p' ? 1 : 2;
	}
}

void		int_format(t_params *conv, t_pdata *l, int fdat[4], int *size)
{
	if (conv->prec > *size - (l->buf[0] == '-'))
		apply_prec(l, conv, size, fdat);
	else if (!conv->prec && *size == 1 && l->buf[0] == '0')
	{
		(*size)--;
		(l->n)--;
		l->buf[0] = 0;
	}
	if (conv->type != 'd' && (conv->flags & F_HASH
		|| conv->type == 'p' || conv->type == 'P'))
		apply_hash(l, conv->type, size, fdat);
}
