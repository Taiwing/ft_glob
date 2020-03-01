#include "libft.h"
#include "ft_fnmatch.h"
#include "ft_fnmatch_internal.h"

int		explicit_match(char string, t_flags *flags)
{
	return ((string == '/' && (flags->cur & FT_FNM_PATHNAME))
		|| (string == '.' && (flags->cur & FT_IFNM_LEADING_PERIOD)));

}

int		match_qmark(const char **pattern, const char **string,
			t_flags *flags)
{
	int	match;

	match = !!**string && !explicit_match(**string, flags);
	*pattern = *pattern + 1;
	*string = **string ? *string + 1 : *string;
	return (match);
}

int		match_reg(const char **pattern, const char **string)
{
	int	match;

	match = **pattern == **string;
	*pattern = *pattern + 1;
	*string = **string ? *string + 1 : *string;
	return (match);
}


int		match_star(const char **pattern, const char **string,
				t_flags *flags)
{
	int	match;
	char	*string_end;
	char	*pattern_end;

	if (explicit_match(**string, flags))
	{
		while (**pattern == '*')
			++(*pattern);
		return (**pattern && match_reg(pattern, string));
	}
	match = 0;
	string_end = ft_strchr(*string, 0);
	pattern_end = ft_strchr(*pattern, 0);
	match = !ft_fnmatch_internal(*pattern + 1, *string, *flags)
	|| (**string && !ft_fnmatch_internal(*pattern, *string + 1, *flags));
	*string = string_end;
	*pattern = pattern_end;
	return (match);
}
