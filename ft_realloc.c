#include "builtin_cmds.h"

void	free_double(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

char	**ft_double_realloc(char **old, size_t old_ptr_n, size_t new_ptr_n)
{
	size_t		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (new_ptr_n + 1));
	if (!new)
		return (free_double(old), NULL);
	while (i < old_ptr_n)
	{
		new[i] = old[i];
		i++;
	}
	while (i <= new_ptr_n)
		new[i++] = NULL;
	free(old);
	return (new);
}

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	unsigned char *new;

	new = malloc(sizeof(char) * new_size);
	if (!new)
		return (free(old), NULL);
	return (ft_memcpy(new, old, old_size), free(old), new);
}
