/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:35:47 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/04 07:59:34 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	(void) env;
	t_shell		shell;

	init_shell(&shell, env);
	shell.last_exit = cd(ac, av, &shell);
	ft_double_write(shell.env);
	exit_shell(&shell, 0);
}
