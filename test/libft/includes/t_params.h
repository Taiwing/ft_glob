/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_params.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:03:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/27 16:17:59 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PARAMS_H
# define T_PARAMS_H

# define F_HASH			0x01
# define F_ZERO			0x02
# define F_MINUS		0x04
# define F_SPACE		0x08
# define F_PLUS			0x10

# define C_UNSIGNED		0x01
# define C_SHORT		0x02
# define C_LONG			0x04
# define C_LONG_LONG	0x08
# define C_INT			0x10
# define C_CHAR			0x20
# define C_SIZE_T		0x40
# define C_INTMAX_T		0x80
# define C_WINT_T		0x100
# define C_WCHAR_T_P	0x200
# define C_CHAR_P		0x400
# define C_DOUBLE		0x800

typedef struct			s_params
{
	char				type;
	char				flags;
	int					cast;
	int					arg;
	int					fw;
	int					prec;
}						t_params;

#endif
