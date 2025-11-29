#include "builtin_cmds.h"

int	unset(char *var)
{
	int			id;
	char		**vars;
	extern char **environ;

	vars = ft_split(var, '=');
	if (!vars)
		return (HEAP_ERROR);
	id = get_env_var_id(vars[0]);
	free_double(vars);
	if (id == -2)
		return (HEAP_ERROR);
	if (id == -1)
		return (EXIT_FAILURE);

	int	i;
	int	j;
	int	size;

	j = 0;
	i = 0;
	size = get_env_size();
	vars = malloc(sizeof(char *) * size);
	if (!vars)
		return (HEAP_ERROR);
	while (i < size)
	{
		if (i == id)
			j++;
		vars[i] = environ[j];
		i++;
		j++;
	}
	vars[i] = NULL;
	free(environ[id]);
	free(environ);
	environ = vars;
	return (EXIT_SUCCESS);
}
