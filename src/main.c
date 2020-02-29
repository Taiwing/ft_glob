#include <stdio.h>
#include <fnmatch.h>
#include "c_colors.h"
#include "ft_fnmatch.h"

char	*test1[] =
{
	"[:alpha:]o[\\:][!\\!]ol",
	"lo:!ol",
	"lo:xol",
	NULL
};

char	*test2[] =
{
	"[:alpha:]*o*[\\:]*[adfxsfsf]ol*",
	"lo:!ol",
	"lo:xol",
	"aRANDOMoRANDOM:RANDaolRAND",
	"ARANDoRAND::::aol",
	"ARANDoRAND::::ao",
	"lRANDoRAND::::aol",
	"pRANDoRAND::::ao",
	NULL
};

char	*test3[] =
{
	"[\\][]]]]\\[\\[\\[wut\\?[\\?a-z:digit:]\\????.lol",
	"]]]][[[wut???wut.lol",
	"[]]][[[wut???wut.lol",
	"[]]][[[wut?a?wut.lol",
	"[]]][[[wut?k?wut.lol",
	"[]]][[[wut?z?wut.lol",
	"[]]][[[wut?1?wut.lol",
	"[]]][[[wut?7?wut.lol",
	"[]]][[[wut?9?wut.lol",
	NULL
};

char	*test4[] =
{
	"[\\][]]]]\\[\\[\\[wut\\?[:alnum:]\\????.lol",
	"]]]][[[wut???wut.lol",
	"[]]][[[wut???wut.lol",
	"[]]][[[wut?a?wut.lol",
	"[]]][[[wut?k?wut.lol",
	"[]]][[[wut?z?wut.lol",
	"[]]][[[wut?1?wut.lol",
	"[]]][[[wut?7?wut.lol",
	"[]]][[[wut?9?wut.lol",
	NULL
};

char	*test5[] =
{
	"[a-z345A-Z][a-zCDE0-9][0-9abcA-Z]",
	"ab9",
	"aE9",
	"aEa",
	"45b",
	"BCE",
	"2ab",
	"aF0",
	"aaa",
	"aaaa",
	"bbb",
	"bbba",
	NULL
};

char	*test6[] =
{
	"_---[\\-][!a-z][\\-]---_",
	"_----A----_",
	"_----B----_",
	"_----a----_",
	"_----b----_",
	NULL
};

char	*test7[] =
{
	"_---[\\-][-----][\\-]---_",
	"_---------_",
	"_----B----_",
	"_----a----_",
	"_----b----_",
	NULL
};

char	*test8[] =
{
	"_---[\\-][-][\\-]---_",
	"_---------_",
	"_----B----_",
	"_----a----_",
	"_----b----_",
	NULL
};

char	*test9[] =
{
	"_---[\\-][--][\\-]---_",
	"_---------_",
	"_----B----_",
	"_----a----_",
	"_----b----_",
	NULL
};

char	*test10[] =
{
	"_---[\\-][---][\\-]---_",
	"_---------_",
	"_----B----_",
	"_----a----_",
	"_----b----_",
	NULL
};

char	*test11[] =
{
	"[a-z-~]",
	"a",
	"b",
	"~",
	"-",
	"{",
	"|",
	"}",
	"A",
	"B",
	"C",
	NULL
};

char	*test12[] =
{
	"[a-z\\-z-~]",
	"a",
	"b",
	"~",
	"-",
	"{",
	"|",
	"}",
	"A",
	"B",
	"C",
	NULL
};

char	*test13[] =
{
	"[z-a\\-~-z]",
	"a",
	"b",
	"~",
	"-",
	"{",
	"|",
	"}",
	"A",
	"B",
	"C",
	NULL
};

char	*test14[] =
{
	"abc\\\\[abc]\\\\[def]\\\\[ghi]\\\\\\*\\*\\*\\",
	"abc\\a\\d\\g\\***\\",
	"abc\\b\\e\\h\\***",
	"abc\\c\\f\\i\\***",
	NULL
};

char	*test15[] =
{
	"abc\\\\[abc]\\\\[def]\\\\[ghi]\\\\\\*\\*\\*",
	"abc\\a\\d\\g\\***",
	"abc\\b\\e\\h\\***",
	"abc\\c\\f\\i\\***",
	NULL
};

char	*test16[] =
{
	"[[[[[[[[[[[",
	"[[[[[[[[[[[",
	NULL
};

char	*test17[] =
{
	"[[[[[[[[[[[????",
	"[[[[[[[[[[[asdf",
	NULL
};

char	*test18[] =
{
	"[[[[[[[[[[[]????*lol",
	"[[[[[[[[[[[]asdf123456789lol",
	NULL
};

char	**tests[] =
{
	test1,
	test2,
	test3,
	test4,
	test5,
	test6,
	test7,
	test8,
	test9,
	test10,
	test11,
	test12,
	test13,
	test14,
	test15,
	test16,
	test17,
	test18,
	NULL
};

int	test_fnmatch(const char *pattern, const char *name)
{
	int	orig;
	int	mine;

	printf("'%s' -> ", name);
	orig = fnmatch(pattern, name, FNM_PATHNAME);
	mine = ft_fnmatch(pattern, name, FT_FNM_PATHNAME);
	if (orig == mine)
		printf(C_GREEN"OK: %d\n"C_RESET, orig);
	else
	{
		printf(C_RED"KO: orig = %d, mine = %d\n"C_RESET, orig, mine);
		return (1);
	}
	return (0);
}

int 	main(void)
{
	int	ret;
	int	i = -1;
	char	*pattern;
	char	**name_string;

	ret = 0;
	while (tests[++i])
	{
		pattern = tests[i][0];
		printf("pattern '%s':\n", pattern);
		name_string = tests[i];
		while (*++name_string)
			ret += test_fnmatch(pattern, *name_string);
	}
	return (ret);
}
