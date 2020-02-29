/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_collector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:58:47 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/20 14:21:57 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_collector.h"

void	ft_closedir(void *dirp)
{
	closedir((DIR *)dirp);
}

t_stack	*ft_dir_container(void)
{
	static t_stack	*st = NULL;

	if (!st)
	{
		st = ft_secmalloc(sizeof(t_stack));
		st->stack = NULL;
		st->size = 0;
		st->i = 0;
		st->cleanf = ft_closedir;
	}
	return (st);
}

void	ft_close_dir_stack(void)
{
	ft_collector(ft_dir_container(), NULL, FT_COLLEC_FREE);
}

DIR		*ft_dir_collector(DIR *dirp, int ds_do)
{
	return ((DIR *)ft_collector(ft_dir_container(), dirp, ds_do));
}
