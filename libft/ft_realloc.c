/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeromne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:36:13 by hkeromne          #+#    #+#             */
/*   Updated: 2025/12/03 01:14:54 by hkeromne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	size_t			smallest;
	unsigned char	*new;

	smallest = old_size;
	if (new_size < old_size)
		smallest = new_size;
	new = malloc(sizeof(char) * (new_size + 1));
	if (!new)
		return (free(old), NULL);
	return (ft_memcpy(new, old, smallest), free(old), new);
}
