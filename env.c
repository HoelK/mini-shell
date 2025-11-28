#include "builtin_cmds.h"

int	env(void)
{
	int	i;
	extern char **environ;

	i = 0;
	if (!environ)
		return (1);
	while (environ[i])
		ft_write(environ[i++]);
	return (0);
}
