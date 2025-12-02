#ifndef BUILTIN_CMDS_H
# define BUILTIN_CMDS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/libft.h"

enum return_status
{
	VAR_UNFOUND = -3,
	ENV_UNFOUND = -2,
	HEAP_ERROR = -1,
	FUNC_SUCCESS,
	FUNC_FAIL
};

//helper
void	ft_write(char *s);
void	free_double(char **strs);
char	*ft_strchr(const char *s, int c);
void	*ft_realloc(void *old, size_t old_size, size_t new_size);
char	**ft_double_realloc(char **old, size_t old_ptr_n, size_t new_ptr_n);

//cmds
int		pwd(void);
int		env(void);
int		unset(char **av);
int		export(char **av);
void	echo(char **av);
int		cd(int ac, char **av);

//envi
int			init_env(void);
int			get_env_size(void);
int			get_env_var_id(char *var);
char		*get_env_var(char *var);
void		free_env(void);
int			mod_env_var(char *var);
int			add_env_var(char *var);
bool		env_name_standard(char *var);

#endif
