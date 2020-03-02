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
		"[\\][]]]]\\[\\[\\[wut\\?[\\?a-z[:digit:]]\\????.lol",
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
		"[\\][]]]]\\[\\[\\[wut\\?[[:alnum:]]\\????.lol",
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
		"[!]",
		"!",
		"a",
		"C",
		"",
		NULL
	},
	{
		"[]",
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
		"[!a-",
		"[",
		"a",
		"-",
		"c",
		NULL
	},
	{
		"[!a-z",
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
		"a*****b*************c***************d****************e"
		"*****************f*****************g*****************h"
		"***********i**j*k*l**m*n*o*p*q*r*s*t*u*v*w*x*y********"
		"******************************************************",
		"aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmm"
		"nnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyy",
		NULL
	},
	{
		"a*****b*************c***************d****************e"
		"*****************f*****************g*****************h"
		"***********i**j*k*l**m*n*o*p*q*r*s*t*u*v*w*x*y********"
		"*****************************************************z",
		"aaaabbbbccccddddeeeeffffgggghhhhiiiijjjjkkkkllllmmmm"
		"nnnnooooppppqqqqrrrrssssttttuuuuvvvvwwwwxxxxyyyy",
		NULL
	},
	{
		"a*****b*************c***************d****************e"
		"*****************f*****************g*****************h"
		"***********i**j*k*l**m*n*o*p*q*r*s*t*u*v*w*x*y********"
		"****************************************************z*",
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
	{
		"!#%+,-./01234567889",
		"!#%+,-./01234567889",
		NULL
	},
	{
		":;=@ABCDEFGHIJKLMNO",
		":;=@ABCDEFGHIJKLMNO",
		NULL
	},
	{
		"PQRSTUVWXYZ]abcdefg",
		"PQRSTUVWXYZ]abcdefg",
		NULL
	},
	{
		"hijklmnopqrstuvwxyz",
		"hijklmnopqrstuvwxyz",
		NULL
	},
	{
		"^_{}~",
		"^_{}~",
		NULL
	},
	{
		"\\\"\\$\\&\\'\\(\\)",
		"\"$&'()",
		NULL
	},
	{
		"\\*\\?\\[\\\\\\`\\|",
		"*?[\\`|",
		NULL
	},
	{
		"\\<\\>",
		"<>",
		NULL
	},
	{
		"[?*[][?*[][?*[]",
		"?*[",
		NULL
	},
	{
		"?/b",
		"a/b",
		NULL
	},
	{
		"a?b",
		"a/b",
		NULL
	},
	{
		"a/?",
		"a/b",
		NULL
	},
	{
		"?/b",
		"aa/b",
		NULL
	},
	{
		"a?b",
		"aa/b",
		NULL
	},
	{
		"a/?",
		"a/bb",
		NULL
	},
	{
		"[abc]",
		"abc",
		NULL
	},
	{
		"[abc]",
		"x",
		NULL
	},
	{
		"[abc]",
		"a",
		NULL
	},
	{
		"[[abc]",
		"[",
		NULL
	},
	{
		"[][abc]",
		"[][abc]",
		"a",
		NULL
	},
	{
		"[]a]]",
		"a]",
		NULL
	},
	{
		"[!abc]",
		"xyz",
		NULL
	},
	{
		"[!abc]",
		"x",
		NULL
	},
	{
		"[!abc]",
		"a",
		NULL
	},
	{
		"[][abc]",
		"]",
		NULL
	},
	{
		"[][abc]",
		"abc]",
		NULL
	},
	{
		"[][]abc",
		"[]abc",
		NULL
	},
	{
		"[!]]",
		"]",
		NULL
	},
	{
		"[!]a]",
		"aa]",
		NULL
	},
	{
		"[!a]",
		"]",
		NULL
	},
	{
		"[!a]]",
		"]]",
		NULL
	},
	{"[a-c0-9]","a",NULL},
	{"[a-c0-9]","d",NULL},
	{"[a-c0-9]","B",NULL},
	{"[-a]","-",NULL},
	{"[-b]","a",NULL},
	{"[!-a]","-",NULL},
	{"[!-b]","a",NULL},
	{"[a-c-0-9]","-",NULL},
	{"[a-c-0-9]","b",NULL},
	{"a[0-9-a]","a:",NULL},
	{"a[09-a]","a:",NULL},
	{"*","",NULL},
	{"*","asd/sdf",NULL},
	{"[a-c][a-z]","as",NULL},
	{"??","as",NULL},
	{"as*df","asd/sdf",NULL},
	{"as*","asd/sdf",NULL},
	{"*df","asd/sdf",NULL},
	{"as*dg","asd/sdf",NULL},
	{"as*df","asdf",NULL},
	{"as*df?","asdf",NULL},
	{"as*??","asdf",NULL},
	{"a*???","asdf",NULL},
	{"*????","asdf",NULL},
	{"????*","asdf",NULL},
	{"??*?","asdf",NULL},
	{"/","/",NULL},
	{"/*","/",NULL},
	{"*/","/",NULL},
	{"/?","/",NULL},
	{"?/","/",NULL},
	{"?","/",NULL},
	{"?",".",NULL},
	{"??","/.",NULL},
	{"[!a-c]","/",NULL},
	{"[!a-c]",".",NULL},
	{"/","/",NULL},
	{"//","//",NULL},
	{"/*","/.a",NULL},
	{"/?a","/.a",NULL},
	{"/[!a-z]a","/.a",NULL},
	{"/*/?b","/.a/.b",NULL},
	{"?","/",NULL},
	{"*","/",NULL},
	{"a?b","a/b",NULL},
	{"/*b","/.a/.b",NULL},
	{"\\/\\$","/$",NULL},
	{"\\/\\[","/[",NULL},
	{"\\/[","/[",NULL},
	{"\\/\\[]","/[]",NULL},
	{"\\/\\$","/$",NULL},
	{"\\/\\$","/\\$",NULL},
	{"\\/\\$","\\/\\$",NULL},
	{".*",".asd",NULL},
	{"*","/.asd",NULL},
	{"*/?*f","/as/.df",NULL},
	{".[!a-z]*","..asd",NULL},
	{"*",".asd",NULL},
	{"?asd",".asd",NULL},
	{"[!a-z]*",".asd",NULL},
	{"/.","/.",NULL},
	{"/.*/.*","/.a./.b.",NULL},
	//{"/.??/.??","/.a./.b.",NULL},
	{"*","/.",NULL},
	{"/*","/.",NULL},
	{"/?","/.",NULL},
	{"/[!a-z]","/.",NULL},
	{"/*/*","/a./.b.",NULL},
	//{"/??/???","/a./.b.",NULL},
	{"foo*[abc]z","foobar",NULL},
	{"foo*[abc][xyz]","foobaz",NULL},
	{"foo?*[abc][xyz]","foobaz",NULL},
	{"foo?*[abc][x/yz]","foobaz",NULL},
	{"foo?*[abc]/[xyz]","foobaz",NULL},
	{"a/","a",NULL},
	{"a","a/",NULL},
	{"/a","//a",NULL},
	{"//a","/a",NULL},
	{"[a-]z","az",NULL},
	{"[ab-]z","bz",NULL},
	{"[ab-]z","cz",NULL},
	{"[ab-]z","-z",NULL},
	{"[-a]z","az",NULL},
	{"[-ab]z","bz",NULL},
	{"[-ab]z","cz",NULL},
	{"[-ab]z","-z",NULL},
	{"[\\\\-a]","\\",NULL},
	{"[\\\\-a]","_",NULL},
	{"[\\\\-a]","a",NULL},
	{"[\\\\-a]","-",NULL},
	{"[\\]-a]","\\",NULL},
	{"[\\]-a]","_",NULL},
	{"[\\]-a]","a",NULL},
	{"[\\]-a]","]",NULL},
	{"[\\]-a]","-",NULL},
	{"[!\\\\-a]","\\",NULL},
	{"[!\\\\-a]","_",NULL},
	{"[!\\\\-a]","a",NULL},
	{"[!\\\\-a]","-",NULL},
	{"[\\!-]","!",NULL},
	{"[\\!-]","-",NULL},
	{"[\\!-]","\\",NULL},
	{"[Z-\\\\]","Z",NULL},
	{"[Z-\\\\]","[",NULL},
	{"[Z-\\\\]","\\",NULL},
	{"[Z-\\\\]","-",NULL},
	{"[Z-\\]]","Z",NULL},
	{"[Z-\\]]","[",NULL},
	{"[Z-\\]]","\\",NULL},
	{"[Z-\\]]","]",NULL},
	{"[Z-\\]]","-",NULL},
	{"[[:alnum:]]","a",NULL},
	{"[![:alnum:]]","a",NULL},
	{"[[:alnum:]]","-",NULL},
	{"[[:alnum:]]a","a]a",NULL},
	{"[[:alnum:]-]","-",NULL},
	{"[[:alnum:]]a","aa",NULL},
	{"[![:alnum:]]","-",NULL},
	{"[!][:alnum:]]","]",NULL},
	{"[![:alnum:][]","[",NULL},
	{"[[:alnum:]]","a",NULL},
	{"[[:alnum:]]","b",NULL},
	{"[[:alnum:]]","c",NULL},
	{"[[:alnum:]]","d",NULL},
	{"[[:alnum:]]","e",NULL},
	{"[[:alnum:]]","f",NULL},
	{"[[:alnum:]]","g",NULL},
	{"[[:alnum:]]","h",NULL},
	{"[[:alnum:]]","i",NULL},
	{"[[:alnum:]]","j",NULL},
	{"[[:alnum:]]","k",NULL},
	{"[[:alnum:]]","l",NULL},
	{"[[:alnum:]]","m",NULL},
	{"[[:alnum:]]","n",NULL},
	{"[[:alnum:]]","o",NULL},
	{"[[:alnum:]]","p",NULL},
	{"[[:alnum:]]","q",NULL},
	{"[[:alnum:]]","r",NULL},
	{"[[:alnum:]]","s",NULL},
	{"[[:alnum:]]","t",NULL},
	{"[[:alnum:]]","u",NULL},
	{"[[:alnum:]]","v",NULL},
	{"[[:alnum:]]","w",NULL},
	{"[[:alnum:]]","x",NULL},
	{"[[:alnum:]]","y",NULL},
	{"[[:alnum:]]","z",NULL},
	{"[[:alnum:]]","A",NULL},
	{"[[:alnum:]]","B",NULL},
	{"[[:alnum:]]","C",NULL},
	{"[[:alnum:]]","D",NULL},
	{"[[:alnum:]]","E",NULL},
	{"[[:alnum:]]","F",NULL},
	{"[[:alnum:]]","G",NULL},
	{"[[:alnum:]]","H",NULL},
	{"[[:alnum:]]","I",NULL},
	{"[[:alnum:]]","J",NULL},
	{"[[:alnum:]]","K",NULL},
	{"[[:alnum:]]","L",NULL},
	{"[[:alnum:]]","M",NULL},
	{"[[:alnum:]]","N",NULL},
	{"[[:alnum:]]","O",NULL},
	{"[[:alnum:]]","P",NULL},
	{"[[:alnum:]]","Q",NULL},
	{"[[:alnum:]]","R",NULL},
	{"[[:alnum:]]","S",NULL},
	{"[[:alnum:]]","T",NULL},
	{"[[:alnum:]]","U",NULL},
	{"[[:alnum:]]","V",NULL},
	{"[[:alnum:]]","W",NULL},
	{"[[:alnum:]]","X",NULL},
	{"[[:alnum:]]","Y",NULL},
	{"[[:alnum:]]","Z",NULL},
	{"[[:alnum:]]","0",NULL},
	{"[[:alnum:]]","1",NULL},
	{"[[:alnum:]]","2",NULL},
	{"[[:alnum:]]","3",NULL},
	{"[[:alnum:]]","4",NULL},
	{"[[:alnum:]]","5",NULL},
	{"[[:alnum:]]","6",NULL},
	{"[[:alnum:]]","7",NULL},
	{"[[:alnum:]]","8",NULL},
	{"[[:alnum:]]","9",NULL},
	{"[[:alnum:]]","!",NULL},
	{"[[:alnum:]]","#",NULL},
	{"[[:alnum:]]","%",NULL},
	{"[[:alnum:]]","+",NULL},
	{"[[:alnum:]]",",",NULL},
	{"[[:alnum:]]","-",NULL},
	{"[[:alnum:]]",".",NULL},
	{"[[:alnum:]]","/",NULL},
	{"[[:alnum:]]",":",NULL},
	{"[[:alnum:]]",";",NULL},
	{"[[:alnum:]]","=",NULL},
	{"[[:alnum:]]","@",NULL},
	{"[[:alnum:]]","[",NULL},
	{"[[:alnum:]]","\\",NULL},
	{"[[:alnum:]]","]",NULL},
	{"[[:alnum:]]","^",NULL},
	{"[[:alnum:]]","_",NULL},
	{"[[:alnum:]]","{",NULL},
	{"[[:alnum:]]","}",NULL},
	{"[[:alnum:]]","~",NULL},
	{"[[:alnum:]]","\"",NULL},
	{"[[:alnum:]]","$",NULL},
	{"[[:alnum:]]","&",NULL},
	{"[[:alnum:]]","'",NULL},
	{"[[:alnum:]]","(",NULL},
	{"[[:alnum:]]",")",NULL},
	{"[[:alnum:]]","*",NULL},
	{"[[:alnum:]]","?",NULL},
	{"[[:alnum:]]","`",NULL},
	{"[[:alnum:]]","|",NULL},
	{"[[:alnum:]]","<",NULL},
	{"[[:alnum:]]",">",NULL},
	{"[[:cntrl:]]","\t",NULL},
	{"[[:cntrl:]]","t",NULL},
	{"[[:lower:]]","t",NULL},
	{"[[:lower:]]","\t",NULL},
	{"[[:lower:]]","T",NULL},
	{"[[:space:]]","\t",NULL},
	{"[[:space:]]","t",NULL},
	{"[[:alpha:]]","t",NULL},
	{"[[:alpha:]]","\t",NULL},
	{"[[:digit:]]","0",NULL},
	{"[[:digit:]]","\t",NULL},
	{"[[:digit:]]","t",NULL},
	{"[[:print:]]","\t",NULL},
	{"[[:print:]]","t",NULL},
	{"[[:upper:]]","T",NULL},
	{"[[:upper:]]","\t",NULL},
	{"[[:upper:]]","t",NULL},
	{"[[:blank:]]","\t",NULL},
	{"[[:blank:]]","t",NULL},
	{"[[:graph:]]","\t",NULL},
	{"[[:graph:]]","t",NULL},
	{"[[:punct:]]",".",NULL},
	{"[[:punct:]]","t",NULL},
	{"[[:punct:]]","\t",NULL},
	{"[[:xdigit:]]","0",NULL},
	{"[[:xdigit:]]","\t",NULL},
	{"[[:xdigit:]]","a",NULL},
	{"[[:xdigit:]]","A",NULL},
	{"[[:xdigit:]]","t",NULL},
	{"[[alpha]]","a",NULL},
	{"[[alpha:]]","a",NULL},
	{"[[alpha]]","a]",NULL},
	{"[[alpha:]]","a]",NULL},
	{"[[:alpha:][:digit:]]","a",NULL},
	{"[[:digit:][:alpha:]]","a",NULL},
	{"[[:lol:] abc]","a","b","c","l","o"," ",NULL},
	{"[[:lol:] abc]*","a","b","c","l","o"," ",NULL},
	{"[[:alpha:] ]","a","z"," ",NULL},
	{"[[:alpha:]","a","z"," ",NULL},
	{"[[:alpha]","a","z"," ",NULL},
	{"[[\\:alpha:] ]","a","z"," ",NULL},
	{"[\\[:alpha:] ]","a","z"," ",NULL},
	{"[[:alpha\\:] ]","a","z"," ","a ]",NULL},
	{"[[:alpha :]]","a","z"," ",NULL},
	{"[[: alpha:]]","a","z"," ",NULL},
	{"[[ :alpha:]]","a",NULL},
	{"[[:alpha: ]]","a",NULL},
	{"[[ :alpha: ]]","a",NULL},
	{"[[ : alpha: ]]","a",NULL},
	{"[[ : alpha   : ]]","a",NULL},
	{"[[:al pha:]]","a",NULL},
	{"[[:al\\pha:]]","a",NULL},
	{"[[:alpha: ]","a","l","z",":"," ",NULL},
	{"[[:alpha ]","a","p","z",":"," ",NULL},
	{"[[:b:]]","a","b",":","[",NULL},
	{"[[::]]","a",":","]",NULL},
	{"[[:]","a",":","[","]",NULL},
	{"[[:]]","a",":","[","]","[]",":]",NULL},
	{"[[]]","a",":","[","]",NULL},
	{"[[]a:]","z","a",":","[","]","[a:]",NULL},
	{"[[:z:]]","a","z",":","]",NULL},
	{"[![:b:]]","a","b",":","[",NULL},
	{"[![::]]","a",":","]",NULL},
	{"[![:]","a",":","[","]",NULL},
	{"[![:]a","a","aa",":a","[","a[","[a","]","za",NULL},
	{"[![:]a]","a","c","aa",":a","[","a[","[a","]","[a]","za]",NULL},
	{"[![:]]","a",":","[","]",NULL},
	{"[![]]","a",":","[","]",NULL},
	{"[![]a:]","z","a",":","[","]","za:]",NULL},
	{"[![:z:]]","a","z",":","]","z]","a]",NULL},
	{"[![:z:]]a","a","z",":","]","z]a","a]a",NULL},
	{"[![:b:]]a","za","ba",":a","[","b]a","c]a",NULL},
	{"[![::]]z","z",":z","]zz","z]z",NULL},
	{"[]","[","]","[]",NULL},
	{"[a-\\","a","b","\\","[a-\\",NULL},
	{"[Z-]z]","Z","]","z","a","Zz]","-z]",NULL},
	{"da*da*da*","daaadabadmanda",NULL},
	{"*?","xx",NULL},
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
