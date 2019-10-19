/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:48:08 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/23 15:14:19 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_clean(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		ft_memdel((void**)&lst);
		lst = temp;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*new_list;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst);
	new_list = ft_lstnew(temp->content, temp->content_size);
	if (!new_list)
		return (NULL);
	node = new_list;
	while (lst->next)
	{
		lst = lst->next;
		temp = f(lst);
		node->next = ft_lstnew(temp->content, temp->content_size);
		if (!node->next)
		{
			ft_clean(new_list);
			return (NULL);
		}
		node = node->next;
	}
	return (new_list);
}
