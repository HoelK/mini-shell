
#ifndef BUILTIN_CMDS_H
# define BUILTIN_CMDS_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# ifndef EXIT_SUCCCES
#  define EXIT_SUCCCES 0
# endif
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif
# ifndef HEAP_ERROR
#  define HEAP_ERROR -1
# endif

//helper
void	ft_write(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *old, size_t old_size, size_t new_size);

//cmds
int		pwd(void);
int		env(void);
int		export(char *new_arg);

#endif
