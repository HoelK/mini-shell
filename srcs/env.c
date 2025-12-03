/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:34:39 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/02 20:37:19 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

int	env(void)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i])
		ft_write(environ[i++]);
	return (0);
}
