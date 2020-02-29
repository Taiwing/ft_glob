/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:34:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 16:02:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_conv.h"
#include "convert.h"

void		init_conv(t_params *conv)
{
	conv->type = 0;
	conv->flags = 0;
	conv->cast = 0;
	conv->arg = 0;
	conv->fw = 0;
	conv->prec = -1;
}

void		parser(t_pdata *data, char **fmt, t_farg *args)
{
	t_params	conv;
	char		*mod;

	mod = ft_strchr(*fmt, '%');
	if (mod == *fmt)
	{
		init_conv(&conv);
		if (get_conv(fmt, args, &conv))
			convert(data, args, &conv, fmt);
	}
	else if (mod)
	{
		add_to_buf(data, *fmt, 0, mod - *fmt);
		*fmt = mod;
	}
	else
	{
		add_to_buf(data, *fmt, 0, ft_strlen(*fmt));
		*fmt = ft_strchr(*fmt, 0);
	}
}

void		parser_str(t_pdata *data, char **fmt, t_farg *args)
{
	t_params	conv;
	char		*mod;

	mod = ft_strchr(*fmt, '%');
	if (mod == *fmt)
	{
		init_conv(&conv);
		if (get_conv(fmt, args, &conv))
			convert_str(data, args, &conv, fmt);
	}
	else if (mod)
	{
		add_to_buf_str(data, *fmt, 0, mod - *fmt);
		*fmt = mod;
	}
	else
	{
		add_to_buf_str(data, *fmt, 0, ft_strlen(*fmt));
		*fmt = ft_strchr(*fmt, 0);
	}
}

void		parser_alloc(t_pdata *data, char **fmt, t_farg *args)
{
	t_params	conv;
	char		*mod;

	mod = ft_strchr(*fmt, '%');
	if (mod == *fmt)
	{
		init_conv(&conv);
		if (get_conv(fmt, args, &conv))
			convert_alloc(data, args, &conv, fmt);
	}
	else if (mod)
	{
		add_to_buf_alloc(data, *fmt, 0, mod - *fmt);
		*fmt = mod;
	}
	else
	{
		add_to_buf_alloc(data, *fmt, 0, ft_strlen(*fmt));
		*fmt = ft_strchr(*fmt, 0);
	}
}

void		parser_pbuf(t_pbuf *buf, char **fmt, t_farg *args)
{
	t_params	conv;
	char		*mod;

	mod = ft_strchr(*fmt, '%');
	if (mod == *fmt)
	{
		init_conv(&conv);
		if (get_conv(fmt, args, &conv))
			convert_pbuf(buf, args, &conv, fmt);
	}
	else if (mod)
	{
		add_to_pbuf(buf, *fmt, 0, mod - *fmt);
		*fmt = mod;
	}
	else
	{
		add_to_pbuf(buf, *fmt, 0, ft_strlen(*fmt));
		*fmt = ft_strchr(*fmt, 0);
	}
}
