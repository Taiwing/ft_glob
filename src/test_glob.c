#include "ft_glob.h"
#include "c_colors.h"
#include <string.h>
#include <stdio.h>
#include <glob.h>

char		*glob_tests[] =
{
	"{}*",
	"{,}*",
	"{,,,,}*",
	"{\\{,\\,,}*",
	"{{{}}*",
	"*/{*}.c",
	"{*,*/*.c}",
	"{*,{*}}",
	"{*,*{*}}",
	"{*,*/{*}}",
	"{*,*/{*}.c}",
	"{*,l*/{*}.c}",
	"{[!l]*,l*/{*}.c}",
	"*/{*}.cl*/{*}.c",
	"*/*.c*",
	"*/*.c[!l]*",
	"*/{*}.c[!l]*",
	"*/{*}.c{[!l]*,l*/{*}.c}",
	"*/{*,*/*}[!hoc]",
	"*/{*,*/*}{,/*}[!hoc]",
	"*/{*,*/*}{,/*}",
	"/*",
	"/{???,/*}",
	"{/{???,/*}}",
	"{/{???,/*},}",
	"globtest-dir/*file6",
	"globtest-dir/-file3",
	"globtest-dir/\\file9b\\",
	"globtest-dir/\\{file8\\}",
	"globtest-dir/\\{file9\\,file9b\\}",
	"globtest-dir/dir1",
	"globtest-dir/dir2",
	"globtest-dir/file1",
	"globtest-dir/file2",
	"globtest-dir/filea,",
	"globtest-dir/fileb}c",
	"globtest-dir/link1",
	"globtest-dir/noread",
	"globtest-dir/{file7,}",
	"globtest-dir/~file4",
	"globtest-dir/file{1,2}",
	"globtest-dir/{file{1,2},-file3}",
	"globtest-dir/{",
	"globtest-dir/abc",
	"globtest-dir/*/does-not-exist",
	"globtest-dir/*/*",
	"globtest-dir/*/1",
	"globtest-dir/*/*1_1",
	"globtest-dir/*/*?_?",
	"globtest-dir/*/file1_1",
	"globtest-dir/*-/*",
	"globtest-dir/*-",
	"globtest-dir/*/file1_[12]",
	"globtest-dir/dir1/file_1[]12]",
	"globtest-dir/\\**",
	"globtest-dir/\\*file6",
	"globtest-dir/a*/*",
	"globtest-dir/noread/*",
	"globtest-dir/noread*/*",
	"globtest-dir/[[:punct:]]*",
	"globtest-dir/dir*6/file1[ab]",
	"globtest-dir/dir1/file1_1",
	"globtest-dir/dir1/file\\1_9",
	"globtest-dir/dir2/",
	"globtest-dir/dir3*/file1",
	"globtest-dir/dir3\\*/file2",
	"globtest-dir/dir4[a/file1",
	"globtest-dir/dir4[a/file2",
	"globtest-dir/dir5[ab]/file[12]",
	"globtest-dir/dir6/fi*l[ab]",
	"globtest-dir/dir6/file1[a",
	"globtest-dir/dir6/file1[a",
	"globtest-dir/dir6/file1[a",
	"globtest-dir/dir6/file1[ab]",
	"globtest-dir/nondir\\/",
	"./*",
	"../*/*",
	"../*/..",
	NULL
};

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
	puts("");
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
	puts("");
}

static int	exec_glob_test(const char *teststr)
{
	size_t	mi;
	size_t	oi;
	int	diff;
	t_glob	mygl;
	int	myret;
	int	myflags;
	glob_t	origgl;
	int	origret;
	int	origflags;

	memset((void *)&mygl, 0, sizeof(t_glob));
	memset((void *)&origgl, 0, sizeof(glob_t));
	printf("pattern '%s':", teststr);
	myflags = FT_GLOB_BRACE;
	origflags = GLOB_BRACE;
	myret = ft_glob(teststr, myflags, NULL, &mygl);
	origret = glob(teststr, origflags, NULL, &origgl);
	diff = 0;
	diff += !!myret != !!origret;
	diff += mygl.gl_pathc != origgl.gl_pathc;
	if (!diff)
	{
		mi = mygl.gl_offs;
		oi = origgl.gl_offs;
		while (mi < mygl.gl_pathc && oi < origgl.gl_pathc)
		{
			if (strcmp(mygl.gl_pathv[mi], origgl.gl_pathv[oi]))
			{
				diff = 1;
				break;
			}
			++mi;
			++oi;
		}
	}
	if (!diff)
		printf(C_GREEN" OK"C_RESET"\n");
	else
	{
		printf(C_RED" KO: orig = %d, mine = %d"C_RESET"\n", origret, myret);
		print_ft_glob(myret, &mygl);
		print_glob(origret, &origgl);
		puts("");
	}
	ft_globfree(&mygl);
	globfree(&origgl);
	return (diff);
}

int		test_glob(void)
{
	int	ret;
	int	i = -1;

	ret = 0;
	puts("");
	while (glob_tests[++i])
		ret += exec_glob_test(glob_tests[i]);
	return (ret);
}
