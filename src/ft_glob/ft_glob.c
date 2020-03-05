#include "ft_glob_internal.h"
#include "ft_fnmatch.h"

static int	set_fnmflags(int flags)
{
	int	fnmflags;

	fnmflags = FT_FNM_PATHNAME;
	if (flags & FT_GLOB_NOESCAPE)
		fnmflags |= FT_FNM_NOESCAPE;
	if (!(flags & FT_GLOB_PERIOD))
		fnmflags |= FT_FNM_PERIOD;
	return (fnmflags);
}

void		*check_mem(t_glob_internal *gl, void *mem)
{
	if (!mem)
		gl->ret = FT_GLOB_NOSPACE;
	return (mem);
}


void		ft_globfree(t_glob *pglob)
{
	size_t	i;

	i = pglob->gl_offs;
	while (i < pglob->gl_offs + pglob->gl_pathc)
		ft_memdel((void **)pglob->gl_pathv + i++);
	ft_memdel((void **)&pglob->gl_pathv);
	ft_bzero((void *)pglob, sizeof(t_glob));
}

t_list		*ft_glob_internal(t_glob_internal *gl, const char *pattern,
				const char *path)
{
	enum e_pathtype	type;
	t_list		*match;
	const char	*cur_pattern;

	match = NULL;
	cur_pattern = NULL;
	type = slash_path(&pattern, &cur_pattern, gl);
	if (type == GL_END)
		match = add_file_lst(NULL, path, 1, gl);
	else if (type == GL_RAWPATH)
		match = find_file(path, cur_pattern, *pattern != '/', gl);
	else if (type == GL_WILDCARD)
		match = match_files(path, cur_pattern, *pattern != '/', gl);
	/*
	else if (type == GL_BRACKS)
		return (parse_brackets(path, cur_pattern, pattern, gl));
	*/
	ft_memdel((void **)&cur_pattern);
	if (!gl->ret && match && *pattern)
		return (match_next_pattern(gl, pattern, match));
	return (match);
}

/*
** TODO: Think about a clean way to handle memory allocations
*/

int			ft_glob(const char *pattern, int flags,
				int (*errfunc)(const char *epath, int eerrno),
				t_glob *pglob)
{
	t_glob_internal	gl;
	const char	*path;
	t_list		*match;

	gl.errf = errfunc;
	gl.flags = flags;
	gl.fnmflags = set_fnmflags(flags);
	path = NULL;
	gl.ret = 0;
	if (pattern[0] == '/')
		path = (const char *)check_mem(&gl, (void *)ft_strdup("/"));
	match = !gl.ret ? ft_glob_internal(&gl, pattern, path) : NULL;
	ft_memdel((void **)&path);
	if (!gl.ret && !match)
	{
		if (flags & FT_GLOB_NOCHECK)
			match = (t_list *)check_mem(&gl,
				(void *)ft_lstnew((void *)pattern,
				ft_strlen(pattern + 1)));
		else
			return (FT_GLOB_NOMATCH);
	}
	return (gl.ret ? gl.ret : store_match_list(pglob, &gl, match));
}
