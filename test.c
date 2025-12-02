#include "builtin_cmds.h"

int	main(int ac, char **av)
{
	extern char **environ;
	(void) ac;
	(void) av;

	init_env();
	export(av);
	env();
	free_env();
}
