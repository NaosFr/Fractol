/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:32:18 by ncella            #+#    #+#             */
/*   Updated: 2017/11/13 15:32:21 by ncella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *current;

	if (!lst || !f)
		return (NULL);
	result = (*f)(lst);
	current = result;
	while (lst->next)
	{
		current->next = (*f)(lst->next);
		current = current->next;
		lst = lst->next;
	}
	return (result);
}
