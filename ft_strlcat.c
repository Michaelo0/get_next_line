/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:19:52 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/23 14:06:34 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		src_len += size;
	else
		src_len += dst_len;
	j = 0;
	while (src[j] && dst_len + 1 < size)
	{
		dst[dst_len] = src[j];
		dst_len++;
		j++;
	}
	dst[dst_len] = '\0';
	return (src_len);
}
