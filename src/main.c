#include "libft.h"

int	test_fnmatch(void);
int	test_glob(void);

int	main(void)
{
	int	test_fnmatch_ret = 0;
	int	test_glob_ret = 0;

	test_fnmatch_ret = test_fnmatch();
	test_glob_ret = test_glob();
	ft_heap_collector(NULL, FT_COLLEC_FREE);
	return (test_fnmatch_ret || test_glob_ret);
}
