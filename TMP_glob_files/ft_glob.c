#include "ft_glob.h"

static t_list	*ft_path_match(const char *path, char *pattern, int flags,
					t_glob *restrict pglob)
{
	char	**sub_patterns;
	sub_patterns = split_path_patterns(pattern);
	while (sub_patterns && part_matches = (
	while ((dir_patterns = split_path(&current_paths, pattern)))
	{
	while (dirs)
		current_paths = ft_glob_dir_match(dir, pattern, flags, pglob);
	while (part_matches)
	
	}
}

int				ft_glob(const char *restrict pattern, int flags, 
					int (*errfunc)(const char *epath, int eerno),
					t_glob *restrict pglob)
{
	char	**sub_patterns;
	
	(void)errfunc; // do nothing for now
	if (!(sub_patterns = split_pattern(pattern)))
		return (no_match(pattern, int flags, pglob));
	while (patterns_count
	if (is_path(pattern))
		matches = ft_path_match(dir, pattern, flags, pblob)
	else
		matches = ft_glob_dir_match(".", pattern, flags, pglob)
}
