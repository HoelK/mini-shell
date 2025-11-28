#include "builtin_cmds.h"

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	unsigned char *new;

	new = malloc(new_size);
	if (!new)
		return (free(old), NULL);
	return (ft_memcpy(new, old, old_size));
}
