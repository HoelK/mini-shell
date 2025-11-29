#include "builtin_cmds.h"

int	export(char *var)
{
	int		id;
	char	**vars;

	vars = ft_split(var, '=');
	id = get_env_var_id(vars[0]);
	if (id == ENV_UNFOUND)
		return (EXIT_FAILURE);
	if (id == -1)
		add_env_var(var);
	else
		mod_env_var(var);
	free_double(vars);
	return (EXIT_SUCCESS);
}
