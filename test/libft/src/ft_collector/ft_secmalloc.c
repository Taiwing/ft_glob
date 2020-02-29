/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 08:10:46 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 17:56:04 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_collector.h"

#ifdef NO_COLLEC

void	*ft_secmalloc(size_t size)
{
	return (malloc(size));
}

#else

void	*ft_secmalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		ft_exit("malloc failure", EXIT_FAILURE);
	ft_heap_collector(ptr, FT_COLLEC_ADD);
	return (ptr);
}

#endif
