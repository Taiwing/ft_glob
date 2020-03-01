int	test_fnmatch(void);

int	main(void)
{
	int	test_fnmatch_ret = test_fnmatch();
	int	test_glob_ret = 0;

	return (test_fnmatch_ret || test_glob_ret);
}
