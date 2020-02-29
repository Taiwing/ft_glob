/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_signed.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 00:16:06 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/20 00:03:44 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_SIGNED_H
# define ITOA_SIGNED_H

# include <stddef.h>
# include <inttypes.h>
# include <sys/types.h>
# include "t_pdata.h"

void	itoa_sint(t_pdata *loc, int si);
void	itoa_slint(t_pdata *loc, long int si);
void	itoa_sllint(t_pdata *loc, long long int si);
void	itoa_ssize_t(t_pdata *loc, ssize_t si);
void	itoa_sintmax_t(t_pdata *loc, intmax_t si);

#endif
