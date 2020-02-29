/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:43:57 by yforeau           #+#    #+#             */
/*   Updated: 2020/02/23 15:35:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fnmatch.h"
#include "ft_fnmatch_internal.h"

static int	match_qmark(const char **pattern, const char **string)
{
	int	match;

	match = !!**string;
	*pattern = *pattern + 1;
	*string = **string ? *string + 1 : *string;
	return (match);
}

static int	match_reg(const char **pattern, const char **string)
{
	int	match;

	match = **pattern == **string;
	*pattern = *pattern + 1;
	*string = **string ? *string + 1 : *string;
	return (match);
}

int		set_flags(char pattern, char string, int flags)
{
	static int	next_flags = 0;

	flags &= FT_FNM_EXTMASK;
	if (next_flags)
	{
		flags |= next_flags;
		next_flags = 0;
		if (flags & FT_IFNM_FORCE_REG)
			return (flags);
	}
	if (pattern == '\\' && !(flags & FT_FNM_NOESCAPE))
	{
		next_flags = FT_IFNM_FORCE_REG;
		flags |= FT_IFNM_SKIP;
	}
	else if (string == '/' && (flags & FT_FNM_PATHNAME)
		&& (flags & FT_FNM_PERIOD))
		next_flags = FT_IFNM_LEADING_PERIOD;
	return (flags);
}

int		ft_fnmatch_internal(const char *pattern, const char *string, int flags)
{
	int					match;

	match = 1;
	while (*pattern && match)
	{
		flags = set_flags(*pattern, *string, flags);
		if (flags & FT_IFNM_SKIP)
			++pattern;
		else if ((flags & FT_IFNM_FORCE_REG)
			|| (*string == '.' && (flags & FT_IFNM_LEADING_PERIOD)))
			match = match_reg(&pattern, &string);
		else if (*pattern == '?')
			match = match_qmark(&pattern, &string);
		else if (*pattern == '[')
			match = match_brack(&pattern, &string, flags);
		else if (*pattern == '*')
			match = match_star(&pattern, &string, flags);
		else
			match = match_reg(&pattern, &string);
	}
	return (*pattern || *string || !match);
}

int		ft_fnmatch(const char *pattern, const char *string, int flags)
{
	flags = set_flags(0, '/', flags);
	return (ft_fnmatch_internal(pattern, string, flags));
}
