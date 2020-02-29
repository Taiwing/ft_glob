/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:24:34 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 16:13:03 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "t_farg.h"
# include "t_pbuf.h"
# include "t_pdata.h"
# include "t_params.h"

void	convert(t_pdata *data, t_farg *args, t_params *conv, char **fmt);
void	convert_str(t_pdata *data, t_farg *args, t_params *conv, char **fmt);
void	convert_alloc(t_pdata *data, t_farg *args, t_params *conv, char **fmt);
void	convert_pbuf(t_pbuf *buf, t_farg *args, t_params *conv, char **fmt);

#endif
