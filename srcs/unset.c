/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 03:49:23 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 03:58:14 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

static int	check_arg(char *var)
{
	if (!var || !*var || !env_name_standard(var))
		return (FUNC_FAIL);
	return (FUNC_SUCCESS);
}

int	delete_var(char *var, char **env)
{
	char		**vars;

	vars = ft_split(var, '=');
	if (!vars)
		return (HEAP_ERROR);
	if (ft_get_row_id(vars[0], env) >= 0)
		env = ft_delete_row(ft_get_row_id(vars[0], env), env);
	ft_double_free(vars);
	return (FUNC_SUCCESS);
}

int	unset(char **av, char **env)
{
	int			i;

	i = 1;
	while (av[i])
	{
		if (!check_arg(av[i]))
			delete_var(av[i], env);
		i++;
	}
	return (EXIT_SUCCESS);
}
