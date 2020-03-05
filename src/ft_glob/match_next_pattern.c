#include "ft_glob_internal.h"

void	del_match(void *string, size_t size)
{
	(void)size;
	ft_memdel(&string);
}

t_list	*match_next_pattern(t_glob_internal *gl, const char *pattern,
			t_list *match)
{
	t_list	*result;
	t_list	*next_lst;

	result = NULL;
	while (!gl->ret && match)
	{
		next_lst = ft_glob_internal(gl, pattern, match->content);
		ft_lst_merge(&result, next_lst);
		match = match->next;
	}
	ft_lstdel(&match, del_match);
	if (gl->ret)
		ft_lstdel(&result, del_match);
	return (result);
}