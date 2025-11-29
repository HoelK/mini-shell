#include "builtin_cmds.h"

int	export(char *var)
{
	(void) var;
	/*char	*n_var;
	int		presence;

	if (!check_format(var))
		return (EXIT_FAILURE);
	presence = search_env(var);
	if (presence < 0)
		return (HEAP_ERROR);
	n_var = ft_strdup(var);
	if (!n_var)
		return (HEAP_ERROR);
	if (!presence)
		return (extend_env(n_var));
	return (replace_env(n_var, presence));*/
	return (1);
}
