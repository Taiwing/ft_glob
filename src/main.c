//int	test_fnmatch(void);
int	test_glob(void);

int	main(void)
{
	/*
	int	test_fnmatch_ret = test_fnmatch();
	*/
	int	test_glob_ret;

	//return (test_fnmatch_ret || test_glob_ret);
	test_glob_ret = test_glob();
	return (test_glob_ret);
}
