/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:42:41 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/19 13:20:31 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t size;

	size = 0;
	while (src[size] && size < len)
	{
		dst[size] = src[size];
		++size;
	}
	while (size < len)
	{
		dst[size] = '\0';
		++size;
	}
	return (dst);
}
