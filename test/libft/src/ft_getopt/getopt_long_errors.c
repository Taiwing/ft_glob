/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_long_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 05:57:41 by yforeau           #+#    #+#             */
/*   Updated: 2019/04/29 18:04:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getopt_errors.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	ambig_option_puterr(char **argv, char *prefix,
								t_optdata *d, unsigned char *ambig_set)
{
	getopt_puterr(*argv);
	getopt_puterr(": option `");
	getopt_puterr(prefix);
	if (ambig_set)
		write(2, d->nextchar, ft_strchr(d->nextchar, '=') - d->nextchar);
	else
		getopt_puterr(d->nextchar);
	getopt_puterr("' is ambiguous");
}

void		print_ambig_error(t_optdata *d, unsigned char *ambig_set,
							char **argv, char *prefix)
{
	int	i;

	if (d->opterr)
	{
		ambig_option_puterr(argv, prefix, d, ambig_set);
		if (ambig_set)
		{
			getopt_puterr("; possiblities:");
			i = -1;
			while (++i < d->lopts_len)
			{
				if (ambig_set[i])
					option_puterr(prefix, d->longopts[i].name);
			}
		}
		getopt_puterr("\n");
	}
	ft_memdel((void **)&ambig_set);
	d->nextchar = "\0";
	++d->optind;
	d->optopt = 0;
}

int			unknown_long_option_error(t_optdata *d, char **argv, char *prefix)
{
	if (!d->longonly || argv[d->optind][1] == '-'
		|| !ft_strchr(d->optstring, *d->nextchar))
	{
		if (d->opterr)
		{
			getopt_puterr(*argv);
			getopt_puterr(": unrecognized option");
			option_puterr(prefix, d->nextchar);
			getopt_puterr("\n");
		}
		d->nextchar = "\0";
		++d->optind;
		d->optopt = 0;
		return ('?');
	}
	return (-1);
}

int			superfluous_arg_error(t_optdata *d, char **argv,
								char *prefix, t_opt *found)
{
	if (d->opterr)
	{
		getopt_puterr(*argv);
		getopt_puterr(": option");
		option_puterr(prefix, found->name);
		getopt_puterr(" doesn't allow an argument\n");
	}
	d->optopt = found->val;
	return ('?');
}

int			missing_arg_error(t_optdata *d, char **argv,
							char *prefix, t_opt *found)
{
	if (d->opterr)
	{
		getopt_puterr(*argv);
		getopt_puterr(": option");
		option_puterr(prefix, found->name);
		getopt_puterr(" requires an argument\n");
	}
	d->optopt = found->val;
	return (*d->optstring == ':' ? ':' : '?');
}
