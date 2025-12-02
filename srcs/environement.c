#include "../includes/builtin_cmds.h"

int	init_env(void)
{
	int			i;
	int			size;
	char		**tmp;
	extern char **environ;

	size = get_env_size();
	if (size < 0)
		return (ENV_UNFOUND);
	tmp = malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (HEAP_ERROR);
	i = 0;
	while (i < size)
		tmp[i++] = NULL;
	i = 0;
	while (i < size)
	{
		tmp[i] = ft_strdup(environ[i]);
		if (!tmp[i])
			return (free_env(), HEAP_ERROR);
		i++;
	}
	tmp[i] = NULL;
	environ = tmp;
	return (EXIT_SUCCESS);
}

int	get_env_size(void)
{
	size_t		i;
	extern char **environ;

	if (!environ)
		return (ENV_UNFOUND);
	i = 0;
	while (environ[i])
		i++;
	return (i);
}

//[a-zA-Z_]+[a-zA-Z0-9_]*
bool		env_name_standard(char *var)
{
	if (!ft_isalpha(*var) && *var != '_')
		return (false);
	var++;
	while (*var && (ft_isalnum(*var) || *var == '_'))
		var++;
	if (*var)
		return (false);
	return (true);
}

char *get_env_var(char *var)
{
	int			id;
	extern char **environ;

	id = get_env_var_id(var);
	if (id < 0)
		return (NULL);
	return (environ[id]);
}

int	get_env_var_id(char *var)
{
	size_t		i;
	extern char **environ;

	if (!environ)
		return (ENV_UNFOUND);
	i = 0;
	while (environ[i] && !ft_strnstr(environ[i], var, (ft_strlen(var) + 1)))
		i++;
	if (!environ[i])
		return (VAR_UNFOUND);
	return (i);
}

void	free_env(void)
{
	size_t		i;
	extern char **environ;

	if (!environ)
		return ;
	i = 0;
	while (environ[i])
		free(environ[i++]);
	free(environ);
}

//for both function we assume var is malloced
//we assume var is formated with the %s=%s format
int	mod_env_var(char *var)
{
	int			id;
	char		**vars;
	extern char **environ;

	vars = ft_split(var, '=');
	if (!vars)
		return (HEAP_ERROR);
	id = get_env_var_id(vars[0]);
	if (id < 0)
		return (id);
	if (environ[id])
		free(environ[id]);
	environ[id] = var;
	free_double(vars);
	return (EXIT_SUCCESS);
}

int add_env_var(char *var)
{
	int			size;
	char		**new_env;
	extern char **environ;

	size = get_env_size();
	if (size < 0)
		return (size);
	new_env = ft_double_realloc(environ, size, size + 1);
	if (!new_env)
		return (HEAP_ERROR);
	new_env[size] = var;
	environ = new_env;
	return (EXIT_SUCCESS);
}
