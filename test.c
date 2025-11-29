#include "builtin_cmds.h"

int	main(int ac, char **av)
{
	//extern char **environ;
	(void) ac;
	(void) av;
	pwd();
	init_env();
	char *var = ft_strdup(av[1]);
	add_env_var(var);
	env();
	free_env();
}
