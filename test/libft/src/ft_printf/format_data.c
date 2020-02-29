/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:10:09 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 16:10:41 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_data_utils.h"
#include "format_data.h"
#include "libft.h"

void		format_data(t_pdata *d, t_pdata *l, t_params *conv, int size)
{
	int		fdat[4];

	size = l->n;
	fdat[SPAD] = 0;
	fdat[ZPAD] = 0;
	fdat[SIGN] = 0;
	fdat[HEX] = 0;
	if (ft_strchr("dbBouxXpP", conv->type))
		int_format(conv, l, fdat, &size);
	apply_sign(l, conv, fdat, &size);
	apply_fw(l, conv, fdat, &size);
	if (fdat[SPAD] > 0)
		add_to_buf(d, NULL, ' ', fdat[SPAD]);
	if (fdat[SIGN])
		add_to_buf(d, NULL, fdat[SIGN], 1);
	if (fdat[HEX] && fdat[HEX] < 3)
		add_to_buf(d, fdat[HEX] == 1 ? "0x" : "0X", 0, 2);
	if (fdat[HEX] > 2)
		add_to_buf(d, fdat[HEX] == 3 ? "0b" : "0B", 0, 2);
	if (fdat[ZPAD] > 0)
		add_to_buf(d, NULL, '0', fdat[ZPAD]);
	add_to_buf(d, l->buf, 0, l->n);
	if (fdat[SPAD] < 0)
		add_to_buf(d, NULL, ' ', fdat[SPAD] * -1);
}

void		format_data_str(t_pdata *d, t_pdata *l, t_params *conv, int size)
{
	int		fdat[4];

	size = l->n;
	fdat[SPAD] = 0;
	fdat[ZPAD] = 0;
	fdat[SIGN] = 0;
	fdat[HEX] = 0;
	if (ft_strchr("dbBouxXpP", conv->type))
		int_format(conv, l, fdat, &size);
	apply_sign(l, conv, fdat, &size);
	apply_fw(l, conv, fdat, &size);
	if (fdat[SPAD] > 0)
		add_to_buf_str(d, NULL, ' ', fdat[SPAD]);
	if (fdat[SIGN])
		add_to_buf_str(d, NULL, fdat[SIGN], 1);
	if (fdat[HEX] && fdat[HEX] < 3)
		add_to_buf_str(d, fdat[HEX] == 1 ? "0x" : "0X", 0, 2);
	if (fdat[HEX] > 2)
		add_to_buf_str(d, fdat[HEX] == 3 ? "0b" : "0B", 0, 2);
	if (fdat[ZPAD] > 0)
		add_to_buf_str(d, NULL, '0', fdat[ZPAD]);
	add_to_buf_str(d, l->buf, 0, l->n);
	if (fdat[SPAD] < 0)
		add_to_buf_str(d, NULL, ' ', fdat[SPAD] * -1);
}

void		format_data_alloc(t_pdata *d, t_pdata *l, t_params *conv, int size)
{
	int		fdat[4];

	size = l->n;
	fdat[SPAD] = 0;
	fdat[ZPAD] = 0;
	fdat[SIGN] = 0;
	fdat[HEX] = 0;
	if (ft_strchr("dbBouxXpP", conv->type))
		int_format(conv, l, fdat, &size);
	apply_sign(l, conv, fdat, &size);
	apply_fw(l, conv, fdat, &size);
	if (fdat[SPAD] > 0)
		add_to_buf_alloc(d, NULL, ' ', fdat[SPAD]);
	if (fdat[SIGN])
		add_to_buf_alloc(d, NULL, fdat[SIGN], 1);
	if (fdat[HEX] && fdat[HEX] < 3)
		add_to_buf_alloc(d, fdat[HEX] == 1 ? "0x" : "0X", 0, 2);
	if (fdat[HEX] > 2)
		add_to_buf_alloc(d, fdat[HEX] == 3 ? "0b" : "0B", 0, 2);
	if (fdat[ZPAD] > 0)
		add_to_buf_alloc(d, NULL, '0', fdat[ZPAD]);
	add_to_buf_alloc(d, l->buf, 0, l->n);
	if (fdat[SPAD] < 0)
		add_to_buf_alloc(d, NULL, ' ', fdat[SPAD] * -1);
}

void		format_data_pbuf(t_pbuf *buf, t_pdata *l, t_params *conv, int size)
{
	int		fdat[4];

	size = l->n;
	fdat[SPAD] = 0;
	fdat[ZPAD] = 0;
	fdat[SIGN] = 0;
	fdat[HEX] = 0;
	if (ft_strchr("dbBouxXpP", conv->type))
		int_format(conv, l, fdat, &size);
	apply_sign(l, conv, fdat, &size);
	apply_fw(l, conv, fdat, &size);
	if (fdat[SPAD] > 0)
		add_to_pbuf(buf, NULL, ' ', fdat[SPAD]);
	if (fdat[SIGN])
		add_to_pbuf(buf, NULL, fdat[SIGN], 1);
	if (fdat[HEX] && fdat[HEX] < 3)
		add_to_pbuf(buf, fdat[HEX] == 1 ? "0x" : "0X", 0, 2);
	if (fdat[HEX] > 2)
		add_to_pbuf(buf, fdat[HEX] == 3 ? "0b" : "0B", 0, 2);
	if (fdat[ZPAD] > 0)
		add_to_pbuf(buf, NULL, '0', fdat[ZPAD]);
	add_to_pbuf(buf, l->buf, 0, l->n);
	if (fdat[SPAD] < 0)
		add_to_pbuf(buf, NULL, ' ', fdat[SPAD] * -1);
}
