#include "ft_fnmatch_internal.h"
#include "libft.h"

int		match_star(const char **pattern, const char **string,
				int flags)
{
	int	match;
	char	*string_end;
	char	*pattern_end;

	match = 0;
	string_end = ft_strchr(*string, 0);
	pattern_end = ft_strchr(*pattern, 0);
	match = !ft_fnmatch_internal(*pattern + 1, *string, flags) || (**string
		&& !ft_fnmatch_internal(*pattern, *string + 1, flags));
	*string = string_end;
	*pattern = pattern_end;
	return (match);
}
