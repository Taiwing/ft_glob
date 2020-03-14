#include "ft_glob_internal.h"

static t_list	*exec_curl_patterns(const char *path,
			const char **curl_patterns, t_glob_internal *gl)
{
	const char	**wt;
	t_list		*next;
	t_list		*match;

	match = NULL;
	wt = curl_patterns;
	while (!gl->ret && *wt)
	{
		next = ft_glob_internal(gl, *wt, path);
		ft_lst_merge(&match, next);
		++wt;
	}
	if (gl->ret)
		ft_lstdel(&match, del_match);
	ft_wtfree((char **)curl_patterns);
	return (match);
}

t_list		*match_curls(const char *path, const char *pattern,
			t_glob_internal *gl)
{
	const char	**curl_patterns;
	const char	*start;
	const char	*end;
	const char	*exp;

	if (!(exp = get_curl_expression(gl, pattern, &start, &end)))
		return (NULL);
	if (!(start = (const char *)check_mem(gl, ft_strndup(
		pattern, start - pattern))))
	{
		ft_memdel((void **)&exp);
		return (NULL);
	}
	if (!(end = (const char *)check_mem(gl, ft_strdup(end + 1))))
	{
		ft_memdel((void **)&exp);
		ft_memdel((void **)&start);
		return (NULL);
	}
	curl_patterns = build_curl_patterns(start, end, exp, gl);
	ft_memdel((void **)&start);
	ft_memdel((void **)&end);
	ft_memdel((void **)&exp);
	return (exec_curl_patterns(path, curl_patterns, gl));
}
