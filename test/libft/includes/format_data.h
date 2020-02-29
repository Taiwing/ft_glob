/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:10:53 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 16:11:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_DATA_H
# define FORMAT_DATA_H

# include "t_params.h"
# include "t_pdata.h"
# include "t_pbuf.h"

enum	e_fdat {SPAD, ZPAD, SIGN, HEX};

void	format_data(t_pdata *d, t_pdata *l, t_params *conv, int size);
void	format_data_str(t_pdata *d, t_pdata *l, t_params *conv, int size);
void	format_data_alloc(t_pdata *d, t_pdata *l, t_params *conv, int size);
void	format_data_pbuf(t_pbuf *buf, t_pdata *l, t_params *conv, int size);

#endif
