/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:05:59 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/29 20:08:57 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pdata.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	init_buf(t_pdata *data)
{
	data->buf = data->sbuf;
	data->abuf = NULL;
	data->bufsize = BLOCK_SIZE;
	data->n = 0;
}

#ifdef NO_COLLEC

void	add_to_buf(t_pdata *data, char *add, int c, size_t size)
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
		free(data->abuf);
		data->abuf = newbuf;
		data->bufsize = newsize;
		data->buf = data->abuf ? data->abuf : data->sbuf;
	}
	if (add)
		ft_memcpy((void *)(data->buf + data->n), (void *)add, size);
	else
		ft_memset((void *)(data->buf + data->n), c, size);
	data->n += size;
}

void	print_buf(t_pdata *data, int fd)
{
	if (data->n > 0)
		data->n = write(fd, data->buf, data->n);
	free(data->abuf);
}

#else

void	add_to_buf(t_pdata *data, char *add, int c, size_t size)
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
		free(ft_heap_collector(data->abuf, FT_COLLEC_GET));
		data->abuf = newbuf;
		data->bufsize = newsize;
		data->buf = data->abuf ? data->abuf : data->sbuf;
	}
	if (add)
		ft_memcpy((void *)(data->buf + data->n), (void *)add, size);
	else
		ft_memset((void *)(data->buf + data->n), c, size);
	data->n += size;
}

void	print_buf(t_pdata *data, int fd)
{
	if (data->n > 0)
		data->n = write(fd, data->buf, data->n);
	free(ft_heap_collector(data->abuf, FT_COLLEC_GET));
}

#endif
