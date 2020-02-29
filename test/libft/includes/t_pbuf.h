/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pbuf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:30:14 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 17:26:16 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PBUF_H
# define T_PBUF_H

# define PBUF_SIZE 1048576

# include <stddef.h>

typedef struct	s_pbuf
{
	char		b[PBUF_SIZE];
	int			fd;
	int			n;
}				t_pbuf;

void			init_pbuf(t_pbuf *buf, int fd);
void			add_to_pbuf(t_pbuf *buf, char *add, int c, size_t size);
void			flush_pbuf(t_pbuf *buf);

#endif
