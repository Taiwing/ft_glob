/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pdata_stralloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:13:36 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 18:13:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pdata.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	init_buf_str(t_pdata *data, char *str, int size)
{
	data->buf = str;
	data->abuf = NULL;
	data->bufsize = size;
	data->n = 0;
}

void	add_to_buf_str(t_pdata *data, char *add, int c, size_t size)
{
	size_t	to_add;

	if (data->n == -1 || (!data->bufsize
		&& (size_t)data->n == data->bufsize - 1))
		return ;
	to_add = !data->bufsize || data->n + size < data->bufsize ?
		size : data->bufsize - data->n - 1;
	if (add)
		ft_memcpy((void *)(data->buf + data->n), (void *)add, to_add);
	else
		ft_memset((void *)(data->buf + data->n), c, to_add);
	data->n += to_add;
}

void	init_buf_alloc(t_pdata *data, char **str)
{
	if (!(*str = (char *)ft_secmalloc(BLOCK_SIZE)))
	{
		data->n = -1;
		return ;
	}
	data->buf = *str;
	data->bufsize = BLOCK_SIZE;
	data->n = 0;
}

#ifdef NO_COLLEC

void	add_to_buf_alloc(t_pdata *data, char *add, int c, size_t size)
{
	char	*newbuf;
	size_t	newsize;

	if (data->n == -1)
		return ;
	newsize = data->n + size + 1;
	if (data->bufsize < newsize)
	{
		newsize = (newsize + BLOCK_SIZE - 1) & ~(BLOCK_SIZE - 1);
		if (!(newbuf = (char *)ft_secmalloc(newsize)))
		{
			data->n = -1;
			return ;
		}
		ft_memcpy((void *)newbuf, (void *)data->buf, data->n);
		free(data->buf);
		data->buf = newbuf;
		data->bufsize = newsize;
	}
	if (add)
		ft_memcpy((void *)(data->buf + data->n), (void *)add, size);
	else
		ft_memset((void *)(data->buf + data->n), c, size);
	data->n += size;
}

#else

void	add_to_buf_alloc(t_pdata *data, char *add, int c, size_t size)
{
	char	*newbuf;
	size_t	newsize;

	if (data->n == -1)
		return ;
	newsize = data->n + size + 1;
	if (data->bufsize < newsize)
	{
		newsize = (newsize + BLOCK_SIZE - 1) & ~(BLOCK_SIZE - 1);
		if (!(newbuf = (char *)ft_secmalloc(newsize)))
		{
			data->n = -1;
			return ;
		}
		ft_memcpy((void *)newbuf, (void *)data->buf, data->n);
		free(ft_heap_collector(data->buf, FT_COLLEC_GET));
		data->buf = newbuf;
		data->bufsize = newsize;
	}
	if (add)
		ft_memcpy((void *)(data->buf + data->n), (void *)add, size);
	else
		ft_memset((void *)(data->buf + data->n), c, size);
	data->n += size;
}

#endif
