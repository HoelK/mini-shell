#include "../includes/builtin_cmds.h"

int	cd(int ac, char **av)
{
	char	*var;

	if (ac != 2)
	{
		//too many arguments
		return (EXIT_FAILURE);
	}
	if (access(av[1], F_OK | X_OK))
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	var = ft_strjoin("PWD=", av[1]);
	mod_env_var(var);
	return (EXIT_SUCCESS);
}
