#include "builtin_cmds.h"

void	ft_write(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
