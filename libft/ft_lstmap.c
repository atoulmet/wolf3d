/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:06:52 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/23 15:17:27 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*beginlst;
	t_list	*tmp;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = (f)(lst);
	beginlst = ft_lstnew(tmp->content, tmp->content_size);
	if (beginlst == NULL)
		return (NULL);
	new = beginlst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = (f)(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!new)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (beginlst);
}
