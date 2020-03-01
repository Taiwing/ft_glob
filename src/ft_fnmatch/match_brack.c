#include "libft.h"
#include "ft_fnmatch.h"
#include "g_char_classes.h"
#include "ft_fnmatch_internal.h"

static t_char_class_fct	valid_char_class(char **cur, char *end)
{
	t_char_class_fct	f;
	size_t			len;
	char			*ptr;
	char			name[MAX_CHAR_CLASS_NAME + 1];

	len = 0;
	ptr = *cur + 1;
	while (len < MAX_CHAR_CLASS_NAME && ptr != end && *ptr != ':')
		name[len++] = *ptr++;
	name[len] = 0;
	f = ptr == end ? NULL : get_char_class_fct(name);
	if (f)
		*cur = ptr;
	return (f);
}

static int		set_cur(char **cur, char **beg, char **end, int *skip)
{
	*end = *beg;
	while (**end && (**end != ']' || *skip > 0))
	{
		*skip = *skip == -1 ? *skip : **end == '\\';
		++(*end);
	}
	*skip = *skip == -1 ? *skip : (*beg)[1] == '\\';
	*cur = *beg + 1 + (*skip > 0);
	return (**end != ']' || *end == *beg + 1);
}

static int		exec_match(char **cur, char *end, char string, int skip)
{
	t_char_class_fct	f;
	int			match;
	char			*next_char;

	if ((*cur)[1] == '-' && *cur + 2 != end)
	{
		next_char = (*cur)[2] != '\\' || skip < 0 ?
			*cur + 2 : *cur + 3;
		match = (string >= **cur && string <= *next_char);
		*cur = next_char;
		return (match);
	}
	else if (**cur == ':' && skip != 1 && (f = valid_char_class(cur, end)))
		return (f(string));
	return (**cur == string);
}

int			match_brack(const char **pattern, const char **string,
				t_flags *flags)
{
	char	*beg;
	char	*end;
	char	*cur;
	int	skip;
	int	match;

	match = 0;
	beg = (char *)(*pattern)++;
	beg = **pattern == '!' ? (char *)(*pattern)++ : beg;
	skip = flags->cur & FT_FNM_NOESCAPE ? -1 : 0;
	if (explicit_match(**string, flags) || set_cur(&cur, &beg, &end, &skip))
		return (match);
	while (!match && cur < end)
	{
		if (skip || !(skip = *cur == '\\'))
		{
			match = exec_match(&cur, end, **string, skip);
			skip = skip > 0 ? 0 : skip;
		}
		++cur;
	}
	*pattern = end + 1;
	*string = **string ? *string + 1 : *string;
	return (*beg == '!' ? !match : match);
}
