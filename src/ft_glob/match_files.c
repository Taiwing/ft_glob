#include "ft_glob_internal.h"
#include "ft_fnmatch.h"
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

char	*add_to_path(const char *path, const char *to_add)
{
	char	*pathname;

	if (!path)
		return (ft_strdup(to_add));
	if (!(pathname = ft_strnew(ft_strlen(path) + ft_strlen(to_add) + 1)))
		return (NULL);
	ft_strcpy(pathname, path);
	ft_strcat(pathname, "/");
	ft_strcat(pathname, to_add);
	return (pathname);
}

t_list	*find_file(const char *path, const char *cur_pattern,
			int only_dir, t_glob_internal *gl)
{
	const char	*pathname;
	struct stat	statbuf;
	t_list		*match;

	path = !ft_strcmp(path, "/") ? "" : path;
	if (!(pathname = (const char *)check_mem(gl,
		(void *)add_to_path(path, cur_pattern))))
		return (NULL);
	match = NULL;
	ft_bzero((void *)&statbuf, sizeof(struct stat));
	if (lstat(pathname, &statbuf) == -1)
	{
		if ((gl->errf && gl->errf(pathname, errno))
			|| (gl->flags & FT_GLOB_ERR))
			gl->ret = FT_GLOB_ABORTED;
		ft_memdel((void **)&pathname);
		return (NULL);
	}
	else if (!only_dir || (statbuf.st_mode & S_IFMT) == S_IFDIR)
		match = (t_list *)check_mem(gl, (void *)ft_lstnew(NULL, 0));
	if (match)
		match->content = (void *)pathname;
	else
		ft_memdel((void **)&pathname);
	return (match);
}

t_list	*add_file_lst(const char *path, const char *file,
			int add_slash, t_glob_internal *gl)
{
	const char	*pathname;
	const char 	*tmp;
	t_list		*lst;

	if (!(pathname = (const char *)check_mem(gl,
		(void *)add_to_path(path, file))))
		return (NULL);
	else if (add_slash)
	{
		tmp = pathname;
		pathname = (const char *)check_mem(gl,
			(void *)ft_strjoin(pathname, "/"));
		ft_memdel((void **)&tmp);
		if (!pathname)
			return (NULL);
	}
	if (!(lst = (t_list *)check_mem(gl, (void *)ft_lstnew(NULL, 0))))
	{
		ft_memdel((void **)&pathname);
		return (NULL);
	}
	lst->content = (void *)pathname;
	return (lst);
}

t_list	*match_files(const char *path, const char *cur_pattern,
			int only_dir, t_glob_internal *gl)
{
	int		add_slash;
	int		eerrno;
	t_list		*match;
	DIR		*dirp;
	struct dirent	*fp;

	match = NULL;
	dirp = opendir(path ? path : ".");
	eerrno = !dirp ? errno : 0;
	while (!eerrno && !gl->ret && (fp = readdir(dirp)))
	{
		add_slash = !only_dir && fp->d_type == DT_DIR
			&& (gl->flags & FT_GLOB_MARK);
		if ((!only_dir || fp->d_type == DT_DIR)
			&& !ft_fnmatch(cur_pattern, fp->d_name, gl->fnmflags))
			ft_lstadd(&match, add_file_lst(path,
				fp->d_name, add_slash, gl));
	}
	if ((eerrno = eerrno || !errno ? eerrno : errno)
		&& ((gl->errf && gl->errf(path, eerrno))
		|| (gl->flags & FT_GLOB_ERR)))
		gl->ret = FT_GLOB_ABORTED;
	if (dirp)
		closedir(dirp);
	return (match);
}
