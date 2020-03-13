#include "ft_glob.h"
#include <string.h>
#include <stdio.h>
#include <glob.h>

static void	print_glob(int origret, glob_t *pglob)
{
	size_t	i;

	printf("original:\n");
	printf("origret = %d\n", origret);
	printf("gl_offs = %zu\n", pglob->gl_offs);
	printf("gl_pathc = %zu\n", pglob->gl_pathc);
	i = pglob->gl_offs;
	while (i < pglob->gl_offs + pglob->gl_pathc)
	{
		printf("pathv[%zu] = '%s'\n", i, pglob->gl_pathv[i]);
		++i;
	}
}


static void	print_ft_glob(int myret, t_glob *pglob)
{
	size_t	i;

	printf("mine:\n");
	printf("myret = %d\n", myret);
	printf("gl_offs = %zu\n", pglob->gl_offs);
	printf("gl_pathc = %zu\n", pglob->gl_pathc);
	i = pglob->gl_offs;
	while (i < pglob->gl_offs + pglob->gl_pathc)
	{
		printf("pathv[%zu] = '%s'\n", i, pglob->gl_pathv[i]);
		++i;
	}
}

int		test_glob(char **argv)
{
	int	mine;
	t_glob	mygl;
	int	myret;
	int	myflags;
	glob_t	origgl;
	int	origret;
	int	origflags;

	mine = 1;
	myflags = FT_GLOB_BRACE;
	origflags = GLOB_BRACE;
	if (!strcmp(*argv, "--original"))
	{
		mine = 0;
		++argv;
	}
	while (*argv)
	{
		if (mine)
			myret = ft_glob(*argv, myflags, NULL, &mygl);
		origret = glob(*argv, origflags, NULL, &origgl);
		if (mine)
		{
			print_ft_glob(myret, &mygl);
			puts("");
		}
		print_glob(origret, &origgl);
		puts("");
		if (mine)
			ft_globfree(&mygl);
		globfree(&origgl);
		++argv;
	}
	return (0);
}
