#include <stdio.h>
#include <fnmatch.h>
#include "c_colors.h"
#include "ft_fnmatch.h"

#define	MAX_NAME_STRINGS	32

char	*tests[][MAX_NAME_STRINGS] =
{
	{
		"[:alpha:]o[\\:][!\\!]ol",
		"lo:!ol",
		"lo:xol",
		NULL
	},
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
	},
	{
		"[[:alpha:]]*o*[\\:]*[adfxsfsf]ol*",
		"lo:!ol",
		"lo:xol",
		"aRANDOMoRANDOM:RANDaolRAND",
		"ARANDoRAND::::aol",
		"ARANDoRAND::::ao",
		"lRANDoRAND::::aol",
		"pRANDoRAND::::ao",
		NULL
	},
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
	},
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
	},
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
	},
	{
		"_---[\\-][!a-z][\\-]---_",
		"_----A----_",
		"_----B----_",
		"_----a----_",
		"_----b----_",
		NULL
	},
	{
		"_---[\\-][-----][\\-]---_",
		"_---------_",
		"_----B----_",
		"_----a----_",
		"_----b----_",
		NULL
	},
	{
		"_---[\\-][-][\\-]---_",
		"_---------_",
		"_----B----_",
		"_----a----_",
		"_----b----_",
		NULL
	},
	{
		"_---[\\-][--][\\-]---_",
		"_---------_",
		"_----B----_",
		"_----a----_",
		"_----b----_",
		NULL
	},
	{
		"_---[\\-][---][\\-]---_",
		"_---------_",
		"_----B----_",
		"_----a----_",
		"_----b----_",
		NULL
	},
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
	},
	{
		"[a-y\\-z-~]",
		"a",
		"b",
		"z",
		"~",
		"-",
		"{",
		"|",
		"}",
		"A",
		"B",
		"C",
		NULL
	},
	{
		"[a-yz-~]",
		"a",
		"b",
		"z",
		"~",
		"-",
		"{",
		"|",
		"}",
		"A",
		"B",
		"C",
		NULL
	},
	{
		"[!]",
		"!",
		"a",
		"C",
		"",
		NULL
	},
	{
		"[]",
		"!",
		"a",
		"C",
		"",
		NULL
	},
	{
		"[-z]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[z-]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[z-a]",
		"c",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[!-z]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[!z-]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[!z-a]",
		"c",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[--9]",
		"0",
		"-",
		"9",
		"a",
		NULL
	},
	{
		"[!--9]",
		"0",
		"-",
		"9",
		"a",
		NULL
	},
	{
		"[a-a]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[!a-a]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[a-az]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[a-az-]",
		"a",
		"-",
		"z",
		NULL
	},
	{
		"[a-",
		"[",
		"a",
		"-",
		"c",
		NULL
	},
	{
		"[a-z",
		"[",
		"a",
		"-",
		"z",
		"t",
		"y",
		NULL
	},
	{
		"[!a-",
		"[",
		"a",
		"-",
		"c",
		NULL
	},
	{
		"[!a-z",
		"[",
		"a",
		"-",
		"z",
		"t",
		"y",
		NULL
	},
	{
		"[!-a]",
		"!",
		"-",
		"a",
		"b",
		"c",
		NULL
	},
	{
		"[!-]",
		"!",
		"-",
		"a",
		"b",
		"c",
		NULL
	},
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
	},
	{
		"[a-y~-z]",
		"a",
		"m",
		"y",
		"~",
		"-",
		"z",
		NULL
	},
	{
		"abc\\\\[abc]\\\\[def]\\\\[ghi]\\\\\\*\\*\\*\\",
		"abc\\a\\d\\g\\***\\\\",
		"abc\\a\\d\\g\\***\\",
		"abc\\b\\e\\h\\***",
		"abc\\c\\f\\i\\***",
		NULL
	},
	{
		"abc\\\\[abc]\\\\[def]\\\\[ghi]\\\\\\*\\*\\*\\\\",
		"abc\\a\\d\\g\\***\\\\",
		"abc\\a\\d\\g\\***\\",
		"abc\\b\\e\\h\\***",
		"abc\\c\\f\\i\\***",
		NULL
	},
	{
		"abc\\\\[abc]\\\\[def]\\\\[ghi]\\\\\\*\\*\\*",
		"abc\\a\\d\\g\\***",
		"abc\\b\\e\\h\\***",
		"abc\\c\\f\\i\\***",
		NULL
	},
	{
		"[[[[[[[[[[[",
		"[[[[[[[[[[[",
		NULL
	},
	{
		"[[[[[[[[[[[????",
		"[[[[[[[[[[[asdf",
		NULL
	},
	{
		"[[[[[[[[[[[]????*lol",
		"[[[[[[[[[[[]asdf123456789lol",
		NULL
	},
	{
		"/.root/.*/*/[a-z0-9]ol",
		"/.root/.invisible_subdir/other_subdir/lol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		"*.root/.invisible_subdir/other_subdir/9ol",
		"*/.root/.invisible_subdir/other_subdir/9ol",
		"/.root/.invisible_subdir/extra_subdir/other_subdir/9ol",
		NULL
	},
	{
		"/.root/?invisible_subdir/other_subdir/9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},
	{
		"/?root/.invisible_subdir/other_subdir/9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},
	{
		"/.root/.invisible_subdir/other_subdir?9ol",
		"/.root/.invisible_subdir?other_subdir/9ol",
		NULL
	},
	{
		"/.*/.invisible_subdir/*/9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},
	{
		"/.root/.invisible_subdir/other_subdir*9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},
	{
		"/.root/.invisible_subdir/other_subdi*/9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},
	{
		"*root/.invisible_subdir/other_subdir/9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},
	{
		"/.root??invisible_subdir/other_subdir/9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},

	{
		"??root??invisible_subdir?other_subdir?9ol",
		"/.root/.invisible_subdir/other_subdir/9ol",
		NULL
	},
	{
		"/.*/.*/*/*",
		"/.root/.invisible_subdir/other_subdir/9ol",
		"/.root/.invisible_subdir/other_subdir/9ol.",
		"/.root/.invisible_subdir/other_subdir/9ol/",
		"/.root/.invisible_subdir/other_subdir/9ol//",
		"/.root/.invisible_subdir/other_subdir//9ol",
		NULL
	},
	{
		".*/.*/*/*",
		".root/.invisible_subdir/other_subdir/9ol",
		".root/.invisible_subdir/other_subdir/9ol.",
		".root/.invisible_subdir/other_subdir/9ol/",
		".root/.invisible_subdir/other_subdir/9ol//",
		".root/.invisible_subdir/other_subdir//9ol",
		NULL
	},
	{
		"*/.*/*/*",
		"root/.invisible_subdir/other_subdir/9ol",
		"root/.invisible_subdir/other_subdir/9ol.",
		"root/.invisible_subdir/other_subdir/9ol/",
		"root/.invisible_subdir/other_subdir/9ol//",
		"root/.invisible_subdir/other_subdir//9ol",
		NULL
	},
	{
		"lol/myass/wut",
		"lol/myass/wut",
		NULL
	},
	{
		"*/myass/wut",
		"lol/myass/wut",
		NULL
	},
	{
		"lol/*/wut",
		"lol/myass/wut",
		NULL
	},
	{
		"lol/myass/*",
		"lol/myass/wut",
		NULL
	},
	{
		"*/myass/*",
		"lol/myass/wut",
		NULL
	},
	{
		"*/*/wut",
		"lol/myass/wut",
		NULL
	},
	{
		"*/*/*",
		"lol/myass/wut",
		NULL
	},
	{
		"lol/wut",
		"lol/wut",
		NULL
	},
	{
		"*/wut",
		"lol/wut",
		NULL
	},
	{
		"lol/*",
		"lol/wut",
		NULL
	},
	{
		"lol/*/",
		"lol/wut/",
		"lol/w/",
		"lol//",
		"lol/wut",
		NULL
	},
	{
		"*/*",
		"lol/wut",
		"lol/wut/",
		"lol//",
		NULL
	},
	{
		"*lol/wut*",
		"lol/wut",
		"lol/wut/",
		NULL
	},
	{
		"*/",
		"l/",
		"lol/",
		NULL
	},
	{
		"a*b",
		"ab",
		"aabb",
		"aaabbb",
		"aaaabbbb",
		NULL
	},
	{
		"a*b*c",
		"abc",
		"aabbcc",
		"aaabbbccc",
		"aaaabbbbcccc",
		NULL
	},
	{
		"a*b*c*",
		"ab",
		"aabb",
		"aaabbb",
		"aaaabbbb",
		NULL
	},
	{
		"a*bb*",
		"abb",
		"aabb",
		"aaabbb",
		"aaaabbbb",
		NULL
	},
	{
		"a*bb",
		"abb",
		"aabb",
		"aaabbb",
		"aaaabbbb",
		NULL
	},
	{
		"a*b*c*d*e*f*g*h*i*j*k*l*m*",
		"abcdefghijklm",
		"aabbccddeeffgghhiijjkkllmm",
		"aaabbbcccdddeeefffggghhhiiijjjkkklllmmm",
		"aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmm",
		NULL
	},
	{
		"a*b*c*d*e*f*g*h*i*j*k*l*m*n*",
		"abcdefghijklm",
		"aabbccddeeffgghhiijjkkllmm",
		"aaabbbcccdddeeefffggghhhiiijjjkkklllmmm",
		"aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmm",
		NULL
	},
	{
		"a*b*c*d*e*f*g*h*i*j*k*l*m*n",
		"abcdefghijklm",
		"aabbccddeeffgghhiijjkkllmm",
		"aaabbbcccdddeeefffggghhhiiijjjkkklllmmm",
		"aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmm",
		NULL
	},
	{
		"a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*",
		"aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmm"
		"nnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyy",
		NULL
	},
	{
		"a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y***",
		"aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmm"
		"nnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyy",
		NULL
	},
	{
		"a*b/*",
		"abbb/.x",
		"abbb/xy",
		NULL
	},
	{
		"[",
		"[",
		NULL
	},
	{NULL}
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
	while (tests[++i][0])
	{
		pattern = tests[i][0];
		printf("pattern '%s':\n", pattern);
		name_string = tests[i];
		while (*++name_string)
			ret += exec_fnmatch_test(pattern, *name_string);
		if (tests[i + 1][0])
			puts("");
	}
	return (ret);
}
