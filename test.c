#include "builtin_cmds.h"

int	main(int ac, char **av)
{
	extern char **environ;
	(void) ac;
	(void) av;

	init_env();
	//char *var = ft_strdup(av[1]);
	if (unset(av) == EXIT_FAILURE)
		return (/*free(var), */EXIT_FAILURE);
	//env();
	//free(var);
	free_env();
}
