/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:34:46 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/19 23:57:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_flags.h"
#include "libft.h"

static int	get_type(char **fmt, t_params *conv)
{
	char	*t;

	if (!(t = ft_strchr("dDibBoOuUxXeEfFgGcCsSpPt%", **fmt)) || !*t)
	{
		if (!t)
			conv->type = *(*fmt)++;
		return (!t);
	}
	if (*t == 'D' || *t == 'O' || *t == 'U')
	{
		conv->cast = *t == 'D' ? C_LONG : C_LONG | C_UNSIGNED;
		conv->type = *t + 32;
	}
	else if (ft_strchr("bBouxX", *t))
	{
		conv->cast |= C_UNSIGNED;
		conv->type = *t;
	}
	else if ((*t == 'c' || *t == 's') && conv->cast & C_LONG)
		conv->type = *t - 32;
	else
		conv->type = *t == 'i' ? 'd' : *t;
	(*fmt)++;
	return (1);
}

static int	get_cast(char **fmt, t_params *conv)
{
	int	ret;

	ret = 0;
	while (ft_strchr("hljzL", **fmt) && **fmt)
	{
		if (**fmt == 'h' && !(conv->cast & C_SHORT))
			conv->cast |= C_SHORT;
		else if (**fmt == 'h')
			conv->cast = (conv->cast | C_CHAR) & ~C_SHORT;
		else if (**fmt == 'l' && !(conv->cast & C_LONG))
			conv->cast |= C_LONG;
		else if (**fmt == 'l' || **fmt == 'L')
			conv->cast = (conv->cast | C_LONG_LONG) & ~C_LONG;
		else if (**fmt == 'j')
			conv->cast |= C_INTMAX_T;
		else if (**fmt == 'z')
			conv->cast |= C_SIZE_T;
		(*fmt)++;
		ret = 1;
	}
	return (ret);
}

int			get_conv(char **fmt, t_farg *args, t_params *conv)
{
	int		f;
	int		c;

	(*fmt)++;
	f = 1;
	c = 1;
	while (f || c)
	{
		if ((f = get_flags(fmt, args, conv)) < 0)
			return (0);
		c = get_cast(fmt, conv);
	}
	return (get_type(fmt, conv));
}
