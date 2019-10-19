/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:51:59 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/19 16:44:37 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i])
	{
		s1[len] = s2[i];
		++len;
		++i;
	}
	s1[len] = '\0';
	return (s1);
}