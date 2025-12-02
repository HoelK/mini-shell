#include "builtin_cmds.h"

char	**sort_ascii(char **strs)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (strs[++i])
	{
		j = i;
		while (j > 0 && strs[j] < strs[j - 1])
		{
			tmp = strs[i];
			strs[i] = strs[i - 1];
			strs[i - 1] = tmp;
			j--;
		}
	}
	return (strs);
}

void	ft_doublewrite(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		write(1, "declare -x ", 11);
		ft_write(strs[i]);
	}
}

void empty_handle(void)
{
	int			i;
	int			size;
	char		**tmp;
	extern char **environ;

	i = -1;
	size = get_env_size();
	tmp = malloc(sizeof(char *) * (size + 1));
	while (environ[++i])
		tmp[i] = environ[i];
	tmp[i] = NULL;
	tmp = sort_ascii(tmp);
	ft_doublewrite(tmp);
	free(tmp);
}

bool	equal_presence(char *s)
{
	while (*s)
	{
		if (*s == '=')
			return (true);
		s++;
	}
	return (false);
}

int	export(char **av)
{
	int		i;
	char	**vars;

	i = 1;
	if (!av[1])
	{
		empty_handle();
		return (0);
	}
	while (av[i])
	{
		vars = ft_split(av[i], '=');
		if (vars[0] && env_name_standard(vars[0]) && equal_presence(av[i]))
		{
			if (get_env_var_id(vars[0]) == VAR_UNFOUND)
				add_env_var(ft_strdup(av[i]));
			else
				mod_env_var(ft_strdup(av[i]));
		}
		else
		{
			write(1, "mini-shell: ", 12);
			write(1, "export: `", 9);
			write(1, vars[0], ft_strlen(vars[0]));
			ft_write("': not a valid identifier");
		}
		free_double(vars);
		i++;
	}
	return (EXIT_SUCCESS);
}
