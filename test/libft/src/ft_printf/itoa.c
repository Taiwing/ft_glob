/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:44:40 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/19 23:59:59 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fetch.h"
#include "itoa_signed.h"
#include "itoa_unsigned.h"

/*
** TODO: Change the cast for the fetch (INT by default is alright if va_arg is
** used buf if get_arr_val is used, values are not properly accessed in the
** array because the type is wrong), test it with conv->cast and check if it
** still works with other conversions. Maybe clean up the code and make sure
** that the cast is good when arriving here, which should already be the case
** with the "check_cast function".
** change made but untested yet
*/

void	itoa_int(t_pdata *loc, t_farg *args, t_params *conv)
{
	int				s;
	unsigned int	u;
	int				base;
	int				type;

	type = (conv->type == 'X' || conv->type == 'P');
	base = conv->type == 'b' || conv->type == 'B' ? 2 : 10;
	base = conv->type == 'o' ? 8 : base;
	base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
	if (conv->cast & C_UNSIGNED)
		fetch(args, conv->arg, conv->cast, (void *)&u);
	else
		fetch(args, conv->arg, conv->cast, (void *)&s);
	if (conv->cast == (C_CHAR | C_UNSIGNED))
		itoa_uint(loc, (unsigned char)u, base, type);
	else if (conv->cast == (C_INT | C_SHORT | C_UNSIGNED))
		itoa_uint(loc, (unsigned short int)u, base, type);
	else if (conv->cast == (C_INT | C_UNSIGNED))
		itoa_uint(loc, u, base, type);
	else if (conv->cast & C_CHAR)
		itoa_sint(loc, (char)s);
	else if (conv->cast & C_SHORT)
		itoa_sint(loc, (short int)s);
	else if (conv->cast & C_INT)
		itoa_sint(loc, s);
}

void	itoa_long(t_pdata *loc, t_farg *args, t_params *conv)
{
	long int			si;
	unsigned long int	ui;
	int					base;
	int					type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'b' || conv->type == 'B' ? 2 : 10;
		base = conv->type == 'o' ? 8 : base;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(args, conv->arg, conv->cast, (void *)&ui);
		itoa_ulint(loc, ui, base, type);
	}
	else
	{
		fetch(args, conv->arg, conv->cast, (void *)&si);
		itoa_slint(loc, si);
	}
}

void	itoa_long_long(t_pdata *loc, t_farg *args, t_params *conv)
{
	long long int			si;
	unsigned long long int	ui;
	int						base;
	int						type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'b' || conv->type == 'B' ? 2 : 10;
		base = conv->type == 'o' ? 8 : base;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(args, conv->arg, conv->cast, (void *)&ui);
		itoa_ullint(loc, ui, base, type);
	}
	else
	{
		fetch(args, conv->arg, conv->cast, (void *)&si);
		itoa_sllint(loc, si);
	}
}

void	itoa_size_t(t_pdata *loc, t_farg *args, t_params *conv)
{
	ssize_t	si;
	size_t	ui;
	int		base;
	int		type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'b' || conv->type == 'B' ? 2 : 10;
		base = conv->type == 'o' ? 8 : base;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(args, conv->arg, conv->cast, (void *)&ui);
		itoa_usize_t(loc, ui, base, type);
	}
	else
	{
		fetch(args, conv->arg, conv->cast, (void *)&si);
		itoa_ssize_t(loc, si);
	}
}

void	itoa_intmax_t(t_pdata *loc, t_farg *args, t_params *conv)
{
	intmax_t	si;
	uintmax_t	ui;
	int			base;
	int			type;

	if (conv->cast & C_UNSIGNED)
	{
		type = (conv->type == 'X' || conv->type == 'P');
		base = conv->type == 'b' || conv->type == 'B' ? 2 : 10;
		base = conv->type == 'o' ? 8 : base;
		base = conv->type == 'x' || conv->type == 'p' || type ? 16 : base;
		fetch(args, conv->arg, conv->cast, (void *)&ui);
		itoa_uintmax_t(loc, ui, base, type);
	}
	else
	{
		fetch(args, conv->arg, conv->cast, (void *)&si);
		itoa_sintmax_t(loc, si);
	}
}
