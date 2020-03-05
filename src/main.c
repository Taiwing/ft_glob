//int	test_fnmatch(void);
int	test_glob(char **argv);

int	main(int argc, char **argv)
{
	/*
	int	test_fnmatch_ret = test_fnmatch();
	*/
	int	test_glob_ret;

	//return (test_fnmatch_ret || test_glob_ret);
	(void)argc;
	if (*++argv)
		test_glob_ret = test_glob(argv);
	return (test_glob_ret);
}
