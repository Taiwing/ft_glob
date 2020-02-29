/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:36:04 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/19 23:48:13 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fetch.h"
#include "libft.h"
#include "itoa_unsigned.h"

void	c_conversion(t_pdata *loc, t_farg *args, t_params *conv)
{
	unsigned char	nb;

	fetch(args, conv->arg, C_CHAR | C_UNSIGNED, (void *)(&nb));
	add_to_buf(loc, NULL, (char)nb, 1);
}

void	s_conversion(t_pdata *loc, t_farg *args, t_params *conv)
{
	char	*str;

	fetch(args, conv->arg, C_CHAR_P, (void *)(&str));
	if (!str)
		add_to_buf(loc, "(null)", 0,
		(conv->prec > 5 || conv->prec < 0) ? 6 : conv->prec);
	else if (str && (conv->prec < 0 || ft_memchr((void *)str, 0, conv->prec)))
		add_to_buf(loc, str, 0, ft_strlen(str));
	else if (str)
		add_to_buf(loc, str, 0, conv->prec);
}

void	p_conversion(t_pdata *loc, t_farg *args, t_params *conv)
{
	unsigned long int	ptr;

	fetch(args, conv->arg, C_INT | C_LONG | C_UNSIGNED, (void *)(&ptr));
	itoa_ulint(loc, ptr, 16, conv->type == 'P');
}
