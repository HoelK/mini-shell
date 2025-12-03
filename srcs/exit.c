/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:20:25 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 01:20:26 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

bool	check_arg(char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		arg++;
	}
	return (true);
}

int	ft_exit(int ac, char **av, t_shell *shell)
{
	uint8_t	return_status;

	if (ac > 2)
		return (ft_write_error("exit", TOO_MANY_ARGS), 1);
	if (ac < 2 || !av[1][0])
		return (exit_shell(shell, 0), 0);
	if (!check_arg(av[1]))
	{
		ft_write_error("exit", NUMERIC_REQUIRED);
		return_status = 2;
	}
	return_status = ft_atoi(av[1]);
	return (exit_shell(shell, return_status), 0);
}
