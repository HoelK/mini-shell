#ifndef BUILTIN_CMDS_H
# define BUILTIN_CMDS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int		ft_isalnum(int c);
int		ft_isalpha(int c);
void	free_double(char **strs);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	**ft_split(const char *str, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *old, size_t old_size, size_t new_size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	**ft_double_realloc(char **old, size_t old_ptr_n, size_t new_ptr_n);

//cmds
int		pwd(void);
int		env(void);
int		unset(char **av);
int		export(char *new_arg);

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
