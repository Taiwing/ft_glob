/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_unsigned.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 00:11:53 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/20 00:04:03 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_UNSIGNED_H
# define ITOA_UNSIGNED_H

# include <inttypes.h>
# include "t_pdata.h"
# include "t_params.h"

void	itoa_uint(t_pdata *loc, unsigned int ui, int base, int type);
void	itoa_ulint(t_pdata *loc, unsigned long int ui, int base, int type);
void	itoa_ullint(t_pdata *loc, unsigned long long int ui,
					int base, int type);
void	itoa_usize_t(t_pdata *loc, size_t ui, int base, int type);
void	itoa_uintmax_t(t_pdata *loc, uintmax_t ui, int base, int type);

#endif
