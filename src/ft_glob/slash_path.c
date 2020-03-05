#include "ft_glob_internal.h"

static const char	*go_to_closing_bracket(const char *pattern,	
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
		skip = skip == 1 ? 0 : skip;
	}
	return (*ptr ? ptr : pattern);
}

static const char	*go_to_end_of_pattern(const char *pattern,
				enum e_pathtype *type, t_glob_internal *gl)
{
	int	skip;

	*type = GL_RAWPATH;
	skip = gl->flags & FT_GLOB_NOESCAPE ? -1 : 0;
	while (*pattern && *pattern != '/')
	{
		if (skip != 1 && ft_strchr(META_CHARS, *pattern))
		{
			if (*pattern == '{' && (gl->flags & FT_GLOB_BRACE))
			{
				pattern = go_to_closing_bracket(pattern, gl);
				*type = *pattern == '}' ? GL_BRACKS : *type;
			}
			else if (*pattern != '{')
			{
				*type = *type != GL_BRACKS ?
					GL_WILDCARD : *type;
				skip = *pattern == '\\' && !skip ? 1 : skip;
			}
		}
		skip = skip == 1 ? 0 : skip;
		++pattern;
	}
	return (pattern);
}

enum e_pathtype		slash_path(const char **pattern,
				const char **cur_pattern, t_glob_internal *gl)
{
	enum e_pathtype	type;
	const char	*end;

	if (!**pattern)
		return (GL_NONE);
	while (**pattern == '/')
		++(*pattern);
	if (!**pattern)
		return (GL_END);
	end = go_to_end_of_pattern(*pattern, &type, gl);
	*cur_pattern = (const char *)check_mem(gl,
		ft_strndup(*pattern, end - *pattern));
	*pattern = end;
	return (*cur_pattern ? type : GL_NONE);
}
