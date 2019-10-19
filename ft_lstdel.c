/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:39:11 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/20 11:43:11 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *node;
	t_list *next;

	node = *alst;
	while (node)
	{
		next = node->next;
		(*del)(node->content, node->content_size);
		free(node);
		node = next;
	}
	*alst = NULL;
}
