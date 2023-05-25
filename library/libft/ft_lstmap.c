/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:30:13 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:30:14 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	void	*content;
	t_list	*new;
	t_list	*new_first;

	content = f (lst -> content);
	new_first = ft_lstnew(content);
	if (!new_first || !content)
	{
		del(content);
		return (NULL);
	}
	lst = lst -> next;
	while (lst)
	{
		content = f(lst -> content);
		new = ft_lstnew(content);
		if (!new || !content)
		{
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_first, new);
		lst = lst -> next;
	}
	return (new_first);
}
