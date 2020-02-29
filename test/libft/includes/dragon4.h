/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:12:44 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/14 22:40:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAGON4_H
# define DRAGON4_H

# define LOG10_2		0.30102999566398119521373889472449
# define DBL_EXP_MAX	0x7FF
# define LDBL_EXP_MAX	0x7FFF
# define LDBL_INT_BIT	0x8000000000000000

/*
** Sign, exp and mantissa are defined by extracting theses values
** from the given float or double. Log2 is the numbers of bits of
** the mantissa, prec is the precision wanted to print the float.
** Digit_exp is the power of ten of the first digit of the float.
** Digit is the current digit during the conversion.
*/

typedef struct			s_bit64d
{
	unsigned long int	mantissa: 52;
	unsigned int		exponent: 11;
	unsigned int		sign: 1;
}						t_bit64d;

typedef struct			s_bit80d
{
	unsigned long int	mantissa;
	unsigned int		exponent: 15;
	unsigned int		sign: 1;
}						t_bit80d;

typedef union			u_bitd
{
	t_bit64d			sd;
	t_bit80d			ld;
}						t_bitd;

typedef struct			s_fltinf
{
	unsigned int		sign;
	int					exp;
	long unsigned int	mantissa;
	unsigned int		log2;
	int					prec;
	int					conv;
	int					digit_exp;
	unsigned int		digit;
	int					exp10;
	int					flags;
}						t_fltinf;

int						dragon4(t_fltinf *info, char *buf);

#endif
