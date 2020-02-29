/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:23:17 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 16:09:25 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "t_farg.h"
# include "t_pbuf.h"
# include "t_pdata.h"
# include "t_params.h"

void	parser(t_pdata *data, char **fmt, t_farg *args);
void	parser_str(t_pdata *data, char **fmt, t_farg *args);
void	parser_alloc(t_pdata *data, char **fmt, t_farg *args);
void	parser_pbuf(t_pbuf *buf, char **fmt, t_farg *args);
void	init_conv(t_params *conv);

#endif
