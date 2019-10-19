/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:18:57 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/21 13:24:42 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	int		i;

	nlen = ft_strlen(needle);
	if (nlen == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0' && i <= (int)(len - nlen))
	{
		if (haystack[i] == needle[0])
			if (!ft_strncmp(haystack + i, needle, nlen))
				return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
