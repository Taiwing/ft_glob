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
	"abc\\a\\d\\g\\***\\\\",
	"abc\\a\\d\\g\\***\\",
	"abc\\b\\e\\h\\***",
	"abc\\c\\f\\i\\***",
	NULL
};

char	*test15[] =
{
	"abc\\\\[abc]\\\\[def]\\\\[ghi]\\\\\\*\\*\\*\\\\",
	"abc\\a\\d\\g\\***\\\\",
	"abc\\a\\d\\g\\***\\",
	"abc\\b\\e\\h\\***",
	"abc\\c\\f\\i\\***",
	NULL
};


char	*test16[] =
{
	"abc\\\\[abc]\\\\[def]\\\\[ghi]\\\\\\*\\*\\*",
	"abc\\a\\d\\g\\***",
	"abc\\b\\e\\h\\***",
	"abc\\c\\f\\i\\***",
	NULL
};

char	*test17[] =
{
	"[[[[[[[[[[[",
	"[[[[[[[[[[[",
	NULL
};

char	*test18[] =
{
	"[[[[[[[[[[[????",
	"[[[[[[[[[[[asdf",
	NULL
};

char	*test19[] =
{
	"[[[[[[[[[[[]????*lol",
	"[[[[[[[[[[[]asdf123456789lol",
	NULL
};

char	*test20[] =
{
	"/.root/.*/*/[a-z0-9]ol",
	"/.root/.invisible_subdir/other_subdir/lol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	"*.root/.invisible_subdir/other_subdir/9ol",
	"*/.root/.invisible_subdir/other_subdir/9ol",
	"/.root/.invisible_subdir/extra_subdir/other_subdir/9ol",
	NULL
};

char	*test21[] =
{
	"/.root/?invisible_subdir/other_subdir/9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test22[] =
{
	"/?root/.invisible_subdir/other_subdir/9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test23[] =
{
	"/.root/.invisible_subdir/other_subdir?9ol",
	"/.root/.invisible_subdir?other_subdir/9ol",
	NULL
};

char	*test24[] =
{
	"/.*/.invisible_subdir/*/9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test25[] =
{
	"/.root/.invisible_subdir/other_subdir*9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test26[] =
{
	"/.root/.invisible_subdir/other_subdi*/9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test27[] =
{
	"*root/.invisible_subdir/other_subdir/9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test28[] =
{
	"/.root??invisible_subdir/other_subdir/9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test29[] =
{
	"??root??invisible_subdir?other_subdir?9ol",
	"/.root/.invisible_subdir/other_subdir/9ol",
	NULL
};

char	*test30[] =
{
	"/.*/.*/*/*",
	"/.root/.invisible_subdir/other_subdir/9ol",
	"/.root/.invisible_subdir/other_subdir/9ol.",
	"/.root/.invisible_subdir/other_subdir/9ol/",
	"/.root/.invisible_subdir/other_subdir/9ol//",
	"/.root/.invisible_subdir/other_subdir//9ol",
	NULL
};

char	*test31[] =
{
	".*/.*/*/*",
	".root/.invisible_subdir/other_subdir/9ol",
	".root/.invisible_subdir/other_subdir/9ol.",
	".root/.invisible_subdir/other_subdir/9ol/",
	".root/.invisible_subdir/other_subdir/9ol//",
	".root/.invisible_subdir/other_subdir//9ol",
	NULL
};

char	*test32[] =
{
	"*/.*/*/*",
	"root/.invisible_subdir/other_subdir/9ol",
	"root/.invisible_subdir/other_subdir/9ol.",
	"root/.invisible_subdir/other_subdir/9ol/",
	"root/.invisible_subdir/other_subdir/9ol//",
	"root/.invisible_subdir/other_subdir//9ol",
	NULL
};

char	*test33[] =
{
	"lol/myass/wut",
	"lol/myass/wut",
	NULL
};

char	*test34[] =
{
	"*/myass/wut",
	"lol/myass/wut",
	NULL
};

char	*test35[] =
{
	"lol/*/wut",
	"lol/myass/wut",
	NULL
};

char	*test36[] =
{
	"lol/myass/*",
	"lol/myass/wut",
	NULL
};

char	*test37[] =
{
	"*/myass/*",
	"lol/myass/wut",
	NULL
};

char	*test38[] =
{
	"*/*/wut",
	"lol/myass/wut",
	NULL
};

char	*test39[] =
{
	"*/*/*",
	"lol/myass/wut",
	NULL
};

char	*test40[] =
{
	"lol/wut",
	"lol/wut",
	NULL
};

char	*test41[] =
{
	"*/wut",
	"lol/wut",
	NULL
};

char	*test42[] =
{
	"lol/*",
	"lol/wut",
	NULL
};

char	*test43[] =
{
	"lol/*/",
	"lol/wut/",
	"lol/w/",
	"lol//",
	"lol/wut",
	NULL
};

char	*test44[] =
{
	"*/*",
	"lol/wut",
	"lol/wut/",
	"lol//",
	NULL
};

char	*test45[] =
{
	"*lol/wut*",
	"lol/wut",
	"lol/wut/",
	NULL
};

char	*test46[] =
{
	"*/",
	"l/",
	"lol/",
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
	test19,
	test20,
	test21,
	test22,
	test23,
	test24,
	test25,
	test26,
	test27,
	test28,
	test29,
	test30,
	test31,
	test32,
	test33,
	test34,
	test35,
	test36,
	test37,
	test38,
	test39,
	test40,
	test41,
	test42,
	test43,
	test44,
	test45,
	test46,
	NULL
};

static int	exec_fnmatch_test(const char *pattern, const char *name)
{
	int	orig;
	int	mine;

	printf("'%s' -> ", name);
	orig = fnmatch(pattern, name, FNM_PATHNAME | FNM_PERIOD);
	mine = ft_fnmatch(pattern, name, FT_FNM_PATHNAME | FT_FNM_PERIOD);
	if (orig == mine)
		printf(C_GREEN"OK: %d"C_RESET"\n", orig);
	else
	{
		printf(C_RED"KO: orig = %d, mine = %d"C_RESET"\n", orig, mine);
		return (1);
	}
	return (0);
}

int	 	test_fnmatch(void)
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
			ret += exec_fnmatch_test(pattern, *name_string);
		if (tests[i + 1])
			puts("");
	}
	return (ret);
}
