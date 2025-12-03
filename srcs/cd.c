/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:35:05 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 04:05:28 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

int	cd(int ac, char **av, char **env)
{
	char	*var;

	if (ac != 2)
		return (EXIT_FAILURE);
	if (access(av[1], F_OK | X_OK))
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	if (av[1][0] == '/')
		var = ft_strjoin(env[ft_get_row_id(("PATH="), env)], av[1]);
	var = ft_strjoin("PWD=", av[1]);
	env = ft_replace_row(ft_get_row_id("PATH=", env), var, env);
	return (EXIT_SUCCESS);
}
