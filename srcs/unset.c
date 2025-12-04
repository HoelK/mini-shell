/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 03:49:23 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 21:25:05 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

static bool	check_arg(char *var)
{
	if (!var || !*var || !env_name_standard(var))
		return (false);
	return (true);
}

char	**delete_var(char *var, char **env)
{
	char		**vars;

	vars = ft_split(var, '=');
	if (!vars || !env)
		return (NULL);
	if (ft_get_row_id(vars[0], env) >= 0)
		env = ft_delete_row(ft_get_row_id(vars[0], env), env);
	ft_double_free(vars);
	return (env);
}

int	unset(char **av, t_shell *shell)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (check_arg(av[i]))
			shell->env = delete_var(av[i], shell->env);
		if (!shell->env)
			return (HEAP_ERROR);
	}
	return (EXIT_SUCCESS);
}
