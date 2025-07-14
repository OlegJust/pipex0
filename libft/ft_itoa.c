/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:22:00 by opidhorn          #+#    #+#             */
/*   Updated: 2024/11/14 13:49:57 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	unsigned int	nbr;
	int				i;

	i = 1;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	else
		nbr = n;
	while (nbr / 10 > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

void	zero( char *str)
{
	str[0] = '0';
	str[1] = '\0';
}

char	*ft_itoa(int n)
{
	size_t			size;
	unsigned int	nb;
	char			*str;

	nb = n;
	size = ft_count(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		zero(str);
	if (n < 0)
	{
		nb = -n;
		*str = '-';
	}
	str[size--] = '\0';
	while (nb != 0)
	{
		str[size--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
