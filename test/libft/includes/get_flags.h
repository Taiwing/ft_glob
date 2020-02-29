/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:04:30 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/25 15:32:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_FLAGS_H
# define GET_FLAGS_H

# include "t_farg.h"
# include "t_params.h"

int	get_flags(char **fmt, t_farg *args, t_params *conv);

#endif
