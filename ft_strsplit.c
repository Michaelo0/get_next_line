/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:23:04 by vmarilli          #+#    #+#             */
/*   Updated: 2019/09/23 13:26:35 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		++i;
	return (i);
}

static int		ft_wc(char const *s, char c)
{
	int		i;
	int		j;

	if (s[0] == '\0')
		return (0);
	j = 0;
	if (s[0] != c)
		j++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			j++;
		i++;
	}
	return (j);
}

static char		**ft_free(char **tab, int i)
{
	while (i > 0)
	{
		free(*(tab--));
		i--;
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**buf;
	int		word_number;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	word_number = ft_wc(s, c);
	if (!(buf = (char**)malloc(sizeof(char*) * (word_number + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_number)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		if (!(buf[i] = ft_strsub(s, j, ft_len(s + j, c))))
			return (ft_free(&(buf[i]), i));
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	buf[i] = NULL;
	return (buf);
}
