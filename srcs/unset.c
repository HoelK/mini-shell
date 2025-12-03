/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:35:54 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/02 20:41:08 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

static int	check_arg(char *var)
{
	if (!var || !*var || !env_name_standard(var))
		return (FUNC_FAIL);
	if (get_env_var_id(var) == VAR_UNFOUND)
		return (FUNC_FAIL);
	return (FUNC_SUCCESS);
}

int	delete_var(char *var)
{
	int			i;
	int			j;
	int			size;
	char		**vars;
	extern char	**environ;

	j = 0;
	i = 0;
	size = get_env_size();
	vars = malloc(sizeof(char *) * size);
	if (!vars)
		return (HEAP_ERROR);
	while (i < size)
	{
		if (i == get_env_var_id(var))
			j++;
		vars[i++] = environ[j++];
	}
	vars[i] = NULL;
	free(environ[get_env_var_id(var)]);
	free(environ);
	environ = vars;
	return (FUNC_SUCCESS);
}

int	unset(char **av)
{
	int			i;
	int			error;

	i = 1;
	while (av[i])
	{
		error = check_arg(av[i]);
		if (!error)
			delete_var(av[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
