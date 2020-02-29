/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:29:22 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/08 20:47:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include "t_farg.h"
# include "t_pdata.h"
# include "t_params.h"

void	itoa_cast(t_pdata *loc, t_farg *args, t_params *conv);
void	efg_conversions(t_pdata *loc, t_farg *args, t_params *conv);
void	p_conversion(t_pdata *loc, t_farg *args, t_params *conv);
void	c_conversion(t_pdata *loc, t_farg *args, t_params *conv);
void	lc_conversion(t_pdata *loc, t_farg *args, t_params *conv);
void	s_conversion(t_pdata *loc, t_farg *args, t_params *conv);
void	ls_conversion(t_pdata *loc, t_farg *args, t_params *conv);
void	t_conversion(t_pdata *loc, t_farg *args, t_params *conv, char **fmt);

#endif
