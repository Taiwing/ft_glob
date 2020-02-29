/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:15:53 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 18:17:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

#ifdef NO_COLLEC

int	ft_asprintf(char **str, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf_alloc(&data, str);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser_alloc(&data, (char **)&format, &args);
	if (data.n != -1)
	{
		*str = data.buf;
		(*str)[data.n] = 0;
	}
	else
		free(data.buf);
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

#else

int	ft_asprintf(char **str, const char *format, ...)
{
	t_pdata	data;
	t_farg	args;

	init_buf_alloc(&data, str);
	args.arr = NULL;
	va_start(args.cur, format);
	va_copy(args.ref, args.cur);
	while (*format && data.n != -1)
		parser_alloc(&data, (char **)&format, &args);
	if (data.n != -1)
	{
		*str = data.buf;
		(*str)[data.n] = 0;
	}
	else
		free(ft_heap_collector(data.buf, FT_COLLEC_GET));
	va_end(args.cur);
	va_end(args.ref);
	return (data.n);
}

#endif
