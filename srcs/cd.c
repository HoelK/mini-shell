/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:35:05 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/04 08:14:53 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

bool try_path(char *av, char *path)
{
	if (access(path, X_OK | F_OK))
	{
		free(path);
		write(1, "mini-shell: ", 12);
		write(1, "cd: ", 4);
		write(1, av, ft_strlen(av));
		ft_write(": No such file or directory");
		return (false);
	}
	return (true);
}

char	**update_pwd(char *path, char **env)
{
	char	*res;

	res = ft_strjoin("PWD=", path);
	if (!res)
		return (NULL);
	return (ft_replace_row(ft_get_row_id("PWD=", env), res, env));
}

char	*create_path(char *path, char **env)
{
	char	*res;
	char	*pwd;
	
	if (!path && !var_exist("HOME=", env))
	{
		write(1, "mini-shell: ", 12);
		write(1, "cd: ", 4);
		ft_write("HOME not set");
		return (NULL);
	}
	else if (!path)
		return (get_env_var_value("HOME=", env));
	else if (path[0] == '/')
		return (ft_strdup(path));
	pwd = get_pwd();
	res = ft_strjoin(pwd, path);
	return (free(pwd), res);
}

int	cd(int ac, char **av, t_shell *shell)
{
	char	*res;

	if (ac > 2)
		return (ft_write_error("cd", TOO_MANY_ARGS), EXIT_FAILURE);
	if (av[1] && !av[1][0])
		return (EXIT_SUCCESS);
	res = create_path(av[1], shell->env);
	if (!res || !try_path(av[1], res))
		return (EXIT_FAILURE);
	if (var_exist("PATH=", shell->env))
		shell->env = update_pwd(res, shell->env);
	chdir(res);
	free(res);
	return (EXIT_SUCCESS);
}
