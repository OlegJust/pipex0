/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:49:23 by opidhorn          #+#    #+#             */
/*   Updated: 2024/11/14 13:21:18 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size * count);
	if (ptr)
	{
		while ((int)(count * size) > i)
		{
			*(char *)(ptr + i) = 0;
			i++;
		}
		return (ptr);
	}
	return (0);
}
