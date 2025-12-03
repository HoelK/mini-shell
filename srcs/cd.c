/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:35:05 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 00:01:23 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

int	cd(int ac, char **av)
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
		var = ft_strjoin(get_env_var("PATH="), av[1]);
	var = ft_strjoin("PWD=", av[1]);
	mod_env_var(var);
	return (EXIT_SUCCESS);
}
