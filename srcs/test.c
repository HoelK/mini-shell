/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:35:47 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 04:08:24 by hkeromne         ###   ########.fr       */
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

	char **s;
	s = ft_doubledup(env);
	s = ft_add_row(ft_strdup(av[1]), s);
	s = ft_replace_row(ft_get_row_id("test=", s), ft_strdup("test=rien"), s);
	s = ft_delete_row(ft_doublelen(s) - 1, s);
	ft_double_write(s);
	ft_double_free(s);
	exit_shell(&shell, 0);
}
