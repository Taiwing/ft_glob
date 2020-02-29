/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:27:13 by yforeau           #+#    #+#             */
/*   Updated: 2019/11/27 16:29:33 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_find_index(t_list *lst, void *content_ref, int (*cmp)())
{
	int	i;

	if (!lst || !content_ref || !cmp)
		return (-1);
	i = 0;
	while (lst)
	{
		if ((*cmp)(content_ref, lst->content) == 0)
			return (i);
		lst = lst->next;
		++i;
	}
	return (-1);
}
