/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <vmarilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:30:41 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/17 14:14:02 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*str;

	i = 0;
	ptr = (unsigned char*)dst;
	str = (unsigned char*)src;
	while (i < n)
	{
		ptr[i] = str[i];
		if (str[i] == (unsigned char)c)
			return ((void*)(ptr + i + 1));
		i++;
	}
	return (NULL);
}
