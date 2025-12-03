/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:20:15 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 03:20:37 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

int	exit_shell(t_shell *shell, uint8_t return_status)
{
	ft_double_free(shell->env);
	exit (return_status);
}

void	init_shell(t_shell *shell)
{
	extern char	**environ;

	init_env();
	shell->last_exit = 0;
	shell->env = environ;
}
