
int	ft_fnm_is_print(char c)
{
	return ((c >= '!' && c <= '~') || (c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_fnm_is_xdigit(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}
