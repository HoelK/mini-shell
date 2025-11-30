#include "builtin_cmds.h"

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	extern char **environ;
	pwd();
	/*init_env();
	char *var = ft_strdup(av[1]);
	unset(var);
	env();
	free(var);
	free_env();*/

	/*char	*s;
	int		size;

	size = ft_strlen(av[1]);
	s = malloc(size + 1);
	ft_memcpy(s, av[1], size);
	s[size] = 0;
	ft_write(s);
	s = ft_realloc(s, size, size / 2);
	s[(size / 2)] = 0;
	ft_write(s);
	free (s);*/
}
