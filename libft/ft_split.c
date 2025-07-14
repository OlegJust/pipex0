/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:16:09 by opidhorn          #+#    #+#             */
/*   Updated: 2024/11/14 09:55:31 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char
	**ft_alloc_split(char const *s, char c)
{
	size_t	i;
	size_t	total;
	char	**split;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			total++;
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (total + 1));
	if (!split)
		return (NULL);
	return (split);
}

void
	*ft_free_all_split_alloc(char **split, size_t elts)
{
	size_t	i;

	i = 0;
	while (i < elts)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static void
	*ft_split_range(char **split, char const *s,
		t_split_next *st, t_split_next *lt)
{
	split[lt->length] = ft_substr(s, st->start, st->length);
	if (!split[lt->length])
		return (ft_free_all_split_alloc(split, lt->length));
	lt->length++;
	return (split);
}

static void
	*ft_split_by_char(char **split, char const *s, char c)
{
	size_t			i;
	t_split_next	st;
	t_split_next	lt;

	i = 0;
	lt.length = 0;
	lt.start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			st.start = lt.start;
			st.length = i - lt.start;
			if (i > lt.start && !ft_split_range(split, s, &st, &lt))
				return (NULL);
			lt.start = i + 1;
		}
		i++;
	}
	st.start = lt.start;
	st.length = i - lt.start;
	if (i > lt.start && !ft_split_range(split, s, &st, &lt))
		return (NULL);
	split[lt.length] = NULL;
	return (split);
}

char
	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_alloc_split(s, c);
	if (!split)
		return (NULL);
	if (!ft_split_by_char(split, s, c))
		return (NULL);
	return (split);
}
