/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:22:29 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/14 16:49:04 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		flag;

	ptr = (char*)s;
	flag = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			ptr = (char*)s;
			flag = 1;
		}
		s++;
	}
	if (flag)
		return (ptr);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
