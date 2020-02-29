/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:59:48 by yforeau           #+#    #+#             */
/*   Updated: 2019/11/08 18:00:44 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define START_STATE 0xACE1u

unsigned int	ft_rand(void)
{
	static unsigned int	lfsr = START_STATE;
	unsigned int		bit;

	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5));
	lfsr = (lfsr >> 1) | (bit << 15);
	return (lfsr);
}
