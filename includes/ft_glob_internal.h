#ifndef FT_GLOB_INTERNAL_H
# define FT_GLOB_INTERNAL_H

# include "ft_glob.h"
# include "libft.h"

typedef struct	s_glob_internal
{
	int	(*errf)(const char *epath, int eerrno);
	int	fnmflags;
	int	flags;
	int	ret;
}		t_glob_internal;

enum e_pathtype {GL_NONE, GL_END, GL_RAWPATH, GL_WILDCARD, GL_BRACKS};

# define META_CHARS	"\\{?[*"

int			store_match_list(t_glob *pglob, t_glob_internal *gl,
				t_list *match);
void			del_match(void *string, size_t size);
t_list			*match_next_pattern(t_glob_internal *gl,
				const char *pattern, t_list *match);
void			*check_mem(t_glob_internal *gl, void *mem);
char			*add_to_path(const char *path, const char *to_add);
t_list			*find_file(const char *path, const char *cur_pattern,
				int only_dir, t_glob_internal *gl);
t_list			*add_file_lst(const char *path, const char *file,
				int add_slash, t_glob_internal *gl);
t_list			*match_files(const char *path, const char *cur_pattern,
				int only_dir, t_glob_internal *gl);
enum e_pathtype		slash_path(const char **pattern,
				const char **cur_pattern, t_glob_internal *gl);
t_list			*ft_glob_internal(t_glob_internal *gl,
				const char *pattern, const char *path);

#endif
