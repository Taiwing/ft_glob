/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:23:28 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/28 13:01:02 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_collector.h"

void	*ft_heap_collector(void *ptr, int hs_do)
{
	static void		**heap_stack = NULL;
	static size_t	size = 0;
	static size_t	i = 0;

	if (hs_do == FT_COLLEC_ADD)
	{
		if (!(heap_stack = ft_check_stack_size(heap_stack, &size, i)))
		{
			free(ptr);
			ft_exit("ft_heap_collector: no space left", EXIT_FAILURE);
		}
		else
			heap_stack[i++] = ptr;
	}
	else if (hs_do == FT_COLLEC_GET)
		return (ft_get_stack_ptr(heap_stack, &i, ptr));
	else if (hs_do == FT_COLLEC_FREE)
	{
		while (i > 0)
			free(heap_stack[--i]);
		free(heap_stack);
	}
	return (NULL);
}
