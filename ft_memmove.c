/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:35:39 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/21 15:39:58 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptr;
	unsigned char *str;

	ptr = (unsigned char*)dst;
	str = (unsigned char*)src;
	if (ptr > str)
	{
		while (len--)
			ptr[len] = str[len];
	}
	else
		while (len--)
			*(ptr++) = *(str++);
	return (dst);
}
