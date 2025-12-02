#include "../includes/builtin_cmds.h"

int	main(int ac, char **av)
{
	extern char **environ;
	(void) ac;
	(void) av;

	init_env();
	env();
	export(av);
	cd(ac, av);
	write(1, environ[get_env_var_id("PWD")], ft_strlen(environ[get_env_var_id("PWD")]));
	free_env();
}
