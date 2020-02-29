/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:38:38 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/25 15:47:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_H
# define ITOA_H

# include "t_farg.h"
# include "t_params.h"
# include "t_pdata.h"

void	itoa_int(t_pdata *loc, t_farg *args, t_params *conv);
void	itoa_long(t_pdata *loc, t_farg *args, t_params *conv);
void	itoa_long_long(t_pdata *loc, t_farg *args, t_params *conv);
void	itoa_size_t(t_pdata *loc, t_farg *args, t_params *conv);
void	itoa_intmax_t(t_pdata *loc, t_farg *args, t_params *conv);

#endif
