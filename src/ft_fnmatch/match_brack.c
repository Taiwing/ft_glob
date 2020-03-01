#include "libft.h"
#include "g_char_classes.h"
#include "ft_fnmatch_internal.h"

/*
TODO: maybe treat invalid globbing syntax explicitly as an error
and return -1 or something like that (this should be handled in
parent functions then)
*/

static char	*find_end(char *pattern, t_flags *flags)
{
	while (*pattern && (*pattern != ']' || (flags->cur & FT_IFNM_SKIP)))
	{
		set_flags(*pattern, 0, flags);
		++pattern;
	}
	if (*pattern == ']')
		++pattern;
	return (pattern);
}

static int	match_char_class(char **pattern, char string)
{
	size_t	len;
	int	match;
	char	name[MAX_CHAR_CLASS_NAME + 1];

	len = 0;
	while (len < MAX_CHAR_CLASS_NAME && *++(*pattern) != ':' && **pattern)
		name[len++] = **pattern;
	name[len] = 0;
	match = get_char_class(string, name);
	*pattern = **pattern ? *pattern + 1 : *pattern;
	return (match);
}

static int	match_range(char *last_char, char **pattern, char string,
			t_flags *flags)
{
	int	match;
	int	next_char;

	++(*pattern);
	next_char = 0;
	if (set_flags(**pattern, string, flags) & FT_IFNM_SKIP)
	{
		++(*pattern);
		set_flags(**pattern, string, flags);
	}
	if (!(next_char = **pattern))
		return (0);
	match = string >= *last_char && string <= next_char;
	*last_char = next_char;
	++(*pattern);
	return (match);
}

//TODO: normify
int		match_brack(const char **pattern, const char **string,
			t_flags *flags)
{
	int	not;
	char	*ptr;
	int	match;
	char	last_char;

	match = 0;
	if (explicit_match(**string, flags))
		return (match);
	last_char = 0;
	not = *++(*pattern) == '!';
	ptr = (char *)(not ? *pattern + 1 : *pattern);
	while (!match && *ptr && (*ptr != ']' || (flags->cur & FT_IFNM_SKIP)))
	{
		if (set_flags(*ptr, **string, flags) & FT_IFNM_SKIP)
			++ptr;
		else if (*ptr == '-' && !(flags->cur & FT_IFNM_FORCE_REG))
			match = match_range(&last_char, &ptr, **string, flags);
		else if (*ptr == ':' && !(flags->cur & FT_IFNM_FORCE_REG))
			match = match_char_class(&ptr, **string);
		else
		{
			last_char = *ptr;
			match = *ptr++ == **string;
		}
	}
	*pattern = find_end(ptr, flags);
	*string = **string ? *string + 1 : *string;
	return (not ? !match : match);
}
