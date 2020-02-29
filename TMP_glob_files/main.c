#include "libft.h"
#include "c_colors.h"
#include "ft_fnmatch.h"

#include <fnmatch.h>
#include <glob.h>

#define OPT_STRING	":f:"
#define STR_MAX		2048

void	test_glob(const char *pattern)
{
	glob_t	g = {0};
	if (!glob(pattern, GLOB_MARK, NULL, &g))
		ft_printf(C_GREEN"OK: "C_RESET"%*t %s\n", g.gl_pathc, g.gl_pathv);
	else
		ft_putstr(C_RED"KO\n"C_RESET);
	globfree(&g);
}

void	test_fnmatch(const char *pattern, const char *name)
{
	ft_printf("'%s' -> ", name);
	if (!fnmatch(pattern, name, FNM_PATHNAME))
		ft_putstr(C_GREEN"OK\n"C_RESET);
	else
		ft_putstr(C_RED"KO\n"C_RESET);
}

int main(int argc, char **argv)
{
	t_optdata	od;
	int			c;
	int			fopt;
	char		*name_string[STR_MAX] = {0};

	fopt = 0;
	init_getopt(&od, OPT_STRING, NULL, NULL);
	od.order = PERMUTE;
	while ((c = ft_getopt(argc, argv, &od)) != -1)
	{
		if (c == 'f')
		{
			++fopt;
			if (fopt == STR_MAX)
			{
				ft_dprintf(2, "error: too many name strings (max is %d)\n",
					STR_MAX);
				return (EXIT_FAILURE);
			}
			name_string[fopt - 1] = od.optarg;
		}
		else if (c == ':')
		{
			ft_dprintf(2, "error: no argument provided for '%c' option\n",
				od.optopt);
			return (EXIT_FAILURE);
		}
		else if (c == '?')
		{
			ft_dprintf(2, "error: unknown option '%c'\n",
				od.optopt);
			return (EXIT_FAILURE);
		}
	}
	argv += od.optind;
	if (!*argv)
	{
		ft_dprintf(2, "error: no pattern provided\n");
		return (EXIT_FAILURE);
	}
	while (*argv)
	{
		ft_printf("test %s: '%s'\n", fopt ? "fnmatch" : "glob", *argv);
		if (fopt)
		{
			for (int i = 0; i < STR_MAX && name_string[i]; ++i)
				test_fnmatch(*argv, name_string[i]);
		}
		else
			test_glob(*argv);
		++argv;
	}
	return (EXIT_SUCCESS);
}
