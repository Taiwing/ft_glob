/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 05:00:00 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/11 06:47:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_ERRORS_H
# define GETOPT_ERRORS_H

# include "ft_getopt.h"

void	getopt_puterr(const char *str);
void	option_puterr(const char *prefix, const char *name);
void	print_short_error(int missing, char *prog_name, char c);
void	print_ambig_error(t_optdata *d, unsigned char *ambig_set,
						char **argv, char *prefix);
int		unknown_long_option_error(t_optdata *d, char **argv, char *prefix);
int		superfluous_arg_error(t_optdata *d, char **argv,
							char *prefix, t_opt *found);
int		missing_arg_error(t_optdata *d, char **argv,
						char *prefix, t_opt *found);

#endif
