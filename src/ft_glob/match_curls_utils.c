#include "ft_glob_internal.h"

const char		*go_to_closing_curl(const char *pattern,	
				t_glob_internal *gl)
{
	const char	*ptr;
	int		skip;
	int		bracket;

	bracket = 1;
	ptr = pattern;
	skip = gl->flags & FT_GLOB_NOESCAPE ? -1 : 0;
	while (bracket && *++ptr)
	{
		if (skip != 1)
		{
			if (*ptr == '\\')
				skip = !skip ? 1 : skip;
			if (*ptr == '{')
				++bracket;
			else if (*ptr == '}')
				--bracket;
		}
		else
			skip = 0;
	}
	return (*ptr ? ptr : pattern);
}

const char		*get_curl_expression(t_glob_internal *gl, const char *pattern,
				const char **start, const char **end)
{
	int	skip;

	skip = gl->flags & FT_GLOB_NOESCAPE ? -1 : 0;
	while (*pattern && (*pattern != '{' || skip > 0
		|| *(*end = go_to_closing_curl(pattern, gl)) != '}'))
	{
		if (skip != -1)
			skip = !skip && *pattern == '\\';
		++pattern;
	}
	*start = pattern;
	return ((const char *)check_mem(gl, ft_strndup(
		*start + 1, *end - *start - 1)));
}

static const char	*get_cur_exp(const char *start, const char *end,
		const char **exp, t_glob_internal *gl)
{
	const char	*cur_exp;
	int		length;
	int		skip;
	
	length = 0;
	skip = gl->flags & FT_GLOB_NOESCAPE ? -1 : 0;
	while ((*exp)[length] && ((*exp)[length] != ',' || skip > 0))
	{
		if ((*exp)[length] == '{' && skip != 1)
			length += go_to_closing_curl(*exp + length, gl)
				- (*exp + length);
		else
		{
			skip = skip == -1 ? skip :
				!skip && (*exp)[length] == '\\';
			++length;
		}
	}
	if ((cur_exp = (const char *)check_mem(gl,
		ft_strnew(ft_strlen(start) + length + ft_strlen(end)))))
		ft_strcat((char *)ft_strncat((char *)ft_strcat(
			(char *)cur_exp, start), *exp, length), end);
	*exp = *exp + length;
	return (cur_exp);
}

const char		**build_curl_patterns(const char *start, const char *end,
				const char *exp, t_glob_internal *gl)
{
	static int	size = 0;
	const char	**tb;
	const char	*p;

	p = NULL;
	tb = NULL;
	size = size == -1 ? 1 : size + 1;
	if (*exp || size == 1)
	{
		exp = size > 1 && *exp == ',' ? exp + 1 : exp;
		if (!(p = get_cur_exp(start, end, &exp, gl)))
			size = -1;
	}
	if (size != -1 && !(tb = p ? build_curl_patterns(start, end, exp,
		gl) : (const char **)check_mem(gl, ft_secmalloc(
		size * sizeof(char *)))))
		size = -1;
	if (size == -1 && p)
		ft_memdel((void **)&p);
	else if (size != -1)
		tb[--size] = p;
	return (tb);
}

