/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:56:05 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/19 14:24:16 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (*p1 == *p2 && *p1 != '\0' && *p2 != '\0' && n--)
	{
		p1++;
		p2++;
	}
	if (n == 0)
		return (0);
	return (*p1 - *p2);
}
