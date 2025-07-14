/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstmap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: opidhorn <opidhorn@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/13 14:12:39 by opidhorn		  #+#	#+#			 */
/*   Updated: 2024/11/21 11:59:57 by opidhorn		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	free_new(t_list *first, void (*del)(void *))
{
	t_list	*temp;

	while (first)
	{
		temp = first->next;
		(*del)(first->content);
		free(first);
		first = temp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*content;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			(*del)(content);
			free_new(first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
