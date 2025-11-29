#ifndef BUILTIN_CMDS_H
# define BUILTIN_CMDS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# ifndef EXIT_SUCCCES
#  define EXIT_SUCCCES 1
# endif
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 0
# endif
# ifndef HEAP_ERROR
#  define HEAP_ERROR -1
# endif
# ifndef ENV_UNFOUND
#  define ENV_UNFOUND -2
# endif

//helper
void	ft_write(char *s);
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
int		export(char *new_arg);

//envi
int			init_env(void);
int			get_env_size(void);
int			get_env_var_id(char *var);
char		*get_env_var(char *var);
void		free_env(void);
int			mod_env_var(char *var);
int			add_env_var(char *var);

#endif
