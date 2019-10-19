/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:23:49 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/23 15:10:27 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnum(int n)
{
	int i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		minus;
	int		num;
	int		k;

	minus = 0;
	if (n < 0)
		minus = 1;
	num = ft_getnum(n);
	str = ft_strnew(num + minus);
	if (!str)
		return (NULL);
	if (minus)
		str[0] = '-';
	k = num + minus - 1;
	while (k >= minus)
	{
		if (minus)
			str[k--] = (n % 10 * -1) + '0';
		else
			str[k--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
