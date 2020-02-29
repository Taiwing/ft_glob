#ifndef FT_GLOB_H
# define FT_GLOB_H

# include <sys/types.h>

/*
** ft_glob flags
*/

# define FT_GLOB_APPEND		0x01	/* Append matches to previous glob output */
# define FT_GLOB_DOOFFS		0x02	/* Set gl_offs NULL to prepend to gl_pathv*/
# define FT_GLOB_ERR		0x04	/* Cause glob to return an error */
# define FT_GLOB_MARK		0x08	/* Append a '/' to matched directories */
# define FT_GLOB_NOCHECK	0x10	/* If pattern does not match return it */
# define FT_GLOB_NOESCAPE	0x20	/* Disable backslash escaping */
# define FT_GLOB_NOSORT		0x40	/* Do not sort the resulting pathnames */

/*
** ft_glob errors
*/

# define FT_GLOB_ABORTED	0x01	/* ERR is set or errfunc returns non-zero */
# define FT_GLOB_NOMATCH	0x02	/* No match and NOCHECK is not set */
# define FT_GLOB_NOSPACE	0x03	/* An attempt to allocate memory failde */

/*
** ft_glob data structure
*/

typedef struct	s_glob
{
	size_t		gl_pathc;			/* Count of paths matched by pattern */
	char		**gl_pathv;			/* Pointer to an array of matched paths */
	size_t		gl_offs;			/* Offset of reserved slots in gl_pathv */
}				t_glob;

int				ft_glob(const char *restrict pattern, int flags, 
					int (*errfunc)(const char *epath, int eerno),
					t_glob *restrict pglob);

void			ft_globfree(t_glob *pglob);
#endif
