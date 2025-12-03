/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmds.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:38:29 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 04:06:51 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_CMDS_H
# define BUILTIN_CMDS_H
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# ifndef SHELL
#  define SHELL "mini-shell"
# endif

enum e_return_status
{
	VAR_UNFOUND = -3,
	ENV_UNFOUND = -2,
	HEAP_ERROR = -1,
	FUNC_SUCCESS,
	FUNC_FAIL
};

enum e_error_status
{
	TOO_MANY_ARGS,
	MISSING_ARGS,
	NUMERIC_REQUIRED
};

typedef struct s_shell
{
	char	**env;
	int		last_exit;
}	t_shell;

//helper
void	ft_write(char *s);
void	free_double(char **strs);
char	*ft_strchr(const char *s, int c);
void	ft_write_error(char *func, int error);
void	*ft_realloc(void *old, size_t old_size, size_t new_size);
char	**ft_double_realloc(char **old, size_t old_ptr_n, size_t new_ptr_n);

//cmds
int		pwd(void);
int		env(char **env);
int		unset(char **av, char **env);
int		export(char **av);
void	echo(char **av);
int		cd(int ac, char **av, char **env);
int		ft_exit(int ac, char **av, t_shell *shell);

//shell
void	init_shell(t_shell *shell, char **env);
int		exit_shell(t_shell *shell, uint8_t return_status);

//envi
bool	env_name_standard(char *var);

#endif
