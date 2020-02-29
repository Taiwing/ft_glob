/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:56:36 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 15:59:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_DATA_UTILS_H
# define FORMAT_DATA_UTILS_H

# include "t_pdata.h"
# include "t_params.h"

void	int_format(t_params *conv, t_pdata *l, int fdat[4], int *size);
void	apply_fw(t_pdata *l, t_params *conv, int fdat[4], int *size);
void	apply_sign(t_pdata *l, t_params *conv, int fdat[4], int *size);

#endif
