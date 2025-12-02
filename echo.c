#include "builtin_cmds.h"

void	echo(char **av)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	while (av[i] && !ft_strncmp(av[i], "-n", ft_strlen(av[i])))
	{
		option = 1;
		i++;
	}
	while (av[i])
	{
		write(1, av[i], ft_strlen(av[i]));
		if (av[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!option)
		write(1, "\n", 1);
}
