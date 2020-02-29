/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:16:55 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 17:57:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef NO_COLLEC
# include "ft_collector.h"
#endif

/*
** This is the maximum allowed of functions to execute at exit time. In practice
** this limit should never be reached, since atexit functions are supposed to
** each get rid of a type of object requiring a specific function to do the job
** (like "close" for open files). Anyway, if this is really needed, ATEXIT_MAX
** can always be increased.
*/

#define ATEXIT_MAX	1024

/*
** ft_exitmsg stores the begining of the exit message (typically the name
** of the program) and returns it.
*/

char	*ft_exitmsg(char *str)
{
	static char	*msg = NULL;

	msg = str ? str : msg;
	return (msg);
}

/*
** ft_atexit stores the list of function to execute at the end of the program.
** This should typically be wrappers for simple call to ft_collector with the
** instruction FT_COLLEC_FREE on each instances of "objects", but it can be
** something else since the prototype is really not restrictive (void input,
** void output).
*/

void	ft_atexit(t_atexitf handler)
{
	static t_atexitf	farr[ATEXIT_MAX];
	static size_t		i = 0;

	if (!handler)
	{
		while (i > 0)
			farr[--i]();
	}
	else if (i < ATEXIT_MAX)
		farr[i++] = handler;
	else
	{
		handler();
		ft_exit("ft_atexit: no space left", EXIT_FAILURE);
	}
}

void	ft_exit(char *err, int ret)
{
	char	*msg;

	if (err)
	{
		if ((msg = ft_exitmsg(NULL)))
		{
			ft_putstr_fd(msg, 2);
			if (*err)
				ft_putstr_fd(": ", 2);
		}
		ft_putstr_fd(err, 2);
		ft_putchar_fd('\n', 2);
	}
	ft_atexit(NULL);
	ft_heap_collector(NULL, FT_COLLEC_FREE);
	exit(ret);
}
