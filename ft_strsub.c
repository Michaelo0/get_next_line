/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:29:46 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/21 15:21:04 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new_str;

	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
