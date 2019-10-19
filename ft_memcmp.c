/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:41:47 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/19 16:22:59 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*str;

	ptr = (unsigned char*)s1;
	str = (unsigned char*)s2;
	while (n--)
	{
		if (*ptr != *str)
			return (*ptr - *str);
		++ptr;
		++str;
	}
	return (0);
}
