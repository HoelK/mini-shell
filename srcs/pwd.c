/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:35:35 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/02 20:35:36 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

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
		path = ft_realloc(path, size, (size * 2));
		if (!path)
			return (HEAP_ERROR);
		size *= 2;
	}
	ft_write(path);
	free(path);
	return (0);
}
