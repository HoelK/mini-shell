/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 01:03:15 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 04:08:06 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtin_cmds.h"

void	ft_write_error(char *func, int error)
{
	write(1, SHELL, ft_strlen(SHELL));
	write(1, ": ", 2);
	write(1, func, ft_strlen(func));
	write(1, ": ", 2);
	if (error == TOO_MANY_ARGS)
		ft_write("Too Many Arguments");
	else if (error == MISSING_ARGS)
		ft_write("Missing Arguments");
	else if (error == NUMERIC_REQUIRED)
		ft_write("numeric argument required");
}

//[a-zA-Z_]+[a-zA-Z0-9_]*
bool	env_name_standard(char *var)
{
	if (!ft_isalpha(*var) && *var != '_')
		return (false);
	var++;
	while (*var && (ft_isalnum(*var) || *var == '_'))
		var++;
	if (*var)
		return (false);
	return (true);
}
