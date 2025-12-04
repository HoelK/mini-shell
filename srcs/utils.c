/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:03:15 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/04 08:13:03 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

void	ft_write_error(char *func, int error)
{
	write(1, SHELL, ft_strlen(SHELL));
	write(1, ": ", 2);
	write(1, func, ft_strlen(func));
	write(1, ": ", 2);
	if (error == TOO_MANY_ARGS)
		ft_write("Too Many Arguments");
	else if (error == MISSING_ARGS)
		ft_write("Missing Arguments");
	else if (error == NUMERIC_REQUIRED)
		ft_write("numeric argument required");
}

//[a-zA-Z_]+[a-zA-Z0-9_]*
bool	env_name_standard(char *var)
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

char	*get_env_var_value(char *name, char **env)
{
	int		i;
	int		id;
	char	*value;

	i = 0;
	id = ft_get_row_id(name, env);
	if (id == -1)
		return (NULL);
	while (env[id][i] != '=')
		i++;
	value = ft_strdup(&env[id][++i]);
	if (!value)
		return (NULL);
	return (value);
}

bool	var_exist(char *name, char **env)
{
	if (ft_get_row_id(name, env) == -1)
		return (false);
	return (true);
}

char	*get_pwd(void)
{
	size_t	size;
	char	*path;
	char	*res;

	size = 2;
	path = malloc(sizeof(char) * size);
	if (!path)
		return (NULL);
	while (!getcwd(path, size))
	{
		path = ft_realloc(path, size, (size * 2));
		if (!path)
			return (NULL);
		size *= 2;
	}
	res = ft_strjoin(path, "/");
	free(path);
	return (res);
}
