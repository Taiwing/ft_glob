/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_formats.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 22:10:02 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/13 23:10:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_FORMATS_H
# define FLOAT_FORMATS_H

# include "t_pdata.h"
# include "dragon4.h"

void	e_format(t_pdata *loc, char *buf, int size, t_fltinf *info);
void	f_format(t_pdata *loc, char *buf, int size, t_fltinf *info);
void	g_format(t_pdata *loc, char *buf, int size, t_fltinf *info);

#endif
