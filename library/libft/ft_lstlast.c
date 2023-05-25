/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:30:09 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:30:10 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*begin;

	if (!lst)
		return (NULL);
	begin = lst;
	while (begin -> next != NULL)
	{
		if (!begin -> next)
			return (begin);
		begin = begin -> next;
	}
	return (begin);
}
