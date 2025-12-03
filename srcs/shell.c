/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:20:15 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 04:06:32 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

int	exit_shell(t_shell *shell, uint8_t return_status)
{
	ft_double_free(shell->env);
	exit (return_status);
}

void	init_shell(t_shell *shell, char **env)
{
	extern char	**environ;

	shell->last_exit = 0;
	shell->env = ft_doubledup(env);
}
