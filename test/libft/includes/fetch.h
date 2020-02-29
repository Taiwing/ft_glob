/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:32:18 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/27 14:10:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FETCH_H
# define FETCH_H

# include <wchar.h>
# include <stddef.h>
# include <inttypes.h>
# include <sys/types.h>
# include "t_farg.h"

void	fetch(t_farg *args, int n, int cast, void *ptr);

#endif
