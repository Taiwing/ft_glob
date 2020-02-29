#include "libft.h"
#include "g_char_classes.h"

const t_char_class	g_char_classes[] =
{
	{"alnum", ft_fnm_is_alnum},
	{"digit", ft_fnm_is_digit},
	{"punct", ft_fnm_is_punct},
	{"alpha", ft_fnm_is_alpha},
	{"graph", ft_fnm_is_graph},
	{"space", ft_fnm_is_space},
	{"blank", ft_fnm_is_blank},
	{"lower", ft_fnm_is_lower},
	{"upper", ft_fnm_is_upper},
	{"cntrl", ft_fnm_is_cntrl},
	{"print", ft_fnm_is_print},
	{"xdigit", ft_fnm_is_xdigit},
	{NULL, NULL}
};

int			get_char_class(char c, const char *name)
{
	int	i;

	i = -1;
	while (g_char_classes[++i].name)
	{
		if (!ft_strcmp(name, g_char_classes[i].name))
			return (g_char_classes[i].f(c));
	}
	return (0);
}
