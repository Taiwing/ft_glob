/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_farg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:21:29 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/25 19:34:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FARG_H
# define T_FARG_H

# include <stdarg.h>

typedef struct	s_farg
{
	void		*arr;
	int			i;
	int			j;
	va_list		cur;
	va_list		ref;
}				t_farg;

#endif
