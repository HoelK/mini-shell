#include "builtin_cmds.h"

static int	check_arg(char *var)
{
	char	**vars;

	if (!var || !*var || !ft_is_env_standard(var))
		return (FUNC_FAIL);
	vars = ft_split(var, '=');
	if (!vars)
		return (HEAP_ERROR);
	if (get_env_var_id(vars[0]) == VAR_UNFOUND);
		return (free_double(vars), FUNC_FAIL);
	return (free_double(vars), FUNC_SUCCESS);
}

int	delete_var(int id, char *var)
{
	int			i;
	int			j;
	int			size;
	char		**vars;
	extern char **environ;

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
		vars[i++] = environ[j++];
	}
	vars[i] = NULL;
	free(environ[id]);
	free(environ);
	environ = vars;
	return (FUNC_SUCCESS);
}

int	unset(char ac, char **av)
{
	int			i;
	int			error;
	int			exit_status;

	i = -1;
	exit_status = 0;
	while (av[++i])
	{
		error = check_arg(av[i])
		if (!error)
			error = delete_var(id, av[i]);
		if (error)
		{
			ft_write("error");
			exit_status = 1;
		}
		i++;
	}
	return (exit_status);
}
