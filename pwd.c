#include "builtin_cmds.h"

int	pwd(void)
{
	size_t	size;
	char	*path;

	size = 2;
	path = malloc(sizeof(char) * size);
	if (!path)
		return (1);
	while (!getcwd(path, size))
	{
		size++;
		free(path);
		path = malloc(sizeof(char) * size);
		if (!path)
			return (1);
	}
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
	free(path);
	return (0);
}
