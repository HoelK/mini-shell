#include "builtin_cmds.h"

static int extend_env(char *var)
{
	int			i;
	size_t		size;
	char		**n_env;
	export char **environ;

	i = -1;
	size = 0;
	while (environ[size])
		size++;
	n_env = malloc(sizeof(char *) * (size + 2));
	if (!n_env)
		return (HEAP_ERROR);
	while (++i < (size - 1))
		n_env[i] = environ[i];
	n_env[i++] = var;
	n_env[i] = NULL;
	environ = n_env;
	return (EXIT_SUCCES);
}

static void replace_env(char *var, size_t id)
{
	char		*n_var;
	export char **environ;

	n_var = ft_strdup(var);
	if (!n_var)
		return (0);
	environ[id] = n_var;
	return (1);
}

static int search_env(char *var)
{
	size_t		i;
	char		**vars;
	export char **environ;

	i = 0;
	vars = ft_split(var, '=');
	if (!vars || !vars[0])
		return (HEAP_ERROR);
	while (!ft_strchr(var[0], environ[i], ft_strlen(var[0])))
		i++;
	if (environ[i] == NULL)
		return (i);
	return (0);
}

static bool check_format(char *var)
{
	size_t	i;

	i = 0;
	if (!var || !*var || *var == '=')
		return (false);
	while (*var != '=')
	{
		if (!*var)
			return (false);
	}
	return (true);
}

int	export(char *var)
{
	char	*n_var;
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
	return (replace_env(n_var, presence));
}
