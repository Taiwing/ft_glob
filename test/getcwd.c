#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE	1024

extern char	**environ;

int	main(void)
{
	char	**ptr;
	char	buf[BUFSIZE];

	ptr = environ;
	while (*ptr && strncmp("PWD", *ptr, 3))
		++ptr;
	if (getcwd(buf, BUFSIZE))
		printf("getcwd: %s\n", buf);
	if (*ptr)
		printf("environ: %s\n", *ptr + 4);
	return (0);
}
