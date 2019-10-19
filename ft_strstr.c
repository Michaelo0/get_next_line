/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:33:47 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/21 13:44:26 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		n_len;
	int		h_len;

	if (*needle == '\0')
		return ((char*)haystack);
	n_len = ft_strlen(needle);
	h_len = ft_strlen(haystack);
	i = 0;
	while (i <= h_len - n_len)
	{
		j = 0;
		while (j < n_len && haystack[i + j] == needle[j])
			j++;
		if (j == n_len)
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
