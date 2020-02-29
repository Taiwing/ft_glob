/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:21:53 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/20 00:00:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "itoa.h"

void	check_cast(t_params *conv, int cast)
{
	if ((cast & C_SIZE_T) && (cast & (C_LONG | C_LONG_LONG | C_INTMAX_T)))
		cast = (cast & ~C_SIZE_T) | C_UNSIGNED;
	if ((cast & C_LONG || cast & C_LONG_LONG || cast & C_INTMAX_T
		|| cast & C_SIZE_T) && (cast & C_SHORT || cast & C_CHAR))
		cast &= ~(C_SHORT | C_CHAR);
	if (!(cast >> 4))
		cast |= C_INT;
	conv->cast = cast;
}

void	itoa_cast(t_pdata *loc, t_farg *args, t_params *conv)
{
	check_cast(conv, conv->cast);
	if (conv->cast == C_INT || conv->cast == (C_INT | C_UNSIGNED)
		|| conv->cast & C_CHAR || conv->cast & C_SHORT)
		itoa_int(loc, args, conv);
	else if (conv->cast & C_LONG)
		itoa_long(loc, args, conv);
	else if (conv->cast & C_LONG_LONG)
		itoa_long_long(loc, args, conv);
	else if (conv->cast & C_SIZE_T)
		itoa_size_t(loc, args, conv);
	else if (conv->cast & C_INTMAX_T)
		itoa_intmax_t(loc, args, conv);
}
