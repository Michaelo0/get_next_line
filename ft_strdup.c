/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:27:23 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/19 14:03:24 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = 0;
	while (s1[len])
		len++;
	copy = (char*)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		copy[len] = s1[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}
