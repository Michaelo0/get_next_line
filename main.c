/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:48:32 by vmarilli          #+#    #+#             */
/*   Updated: 2019/10/19 22:12:26 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "gnl/get_next_line.h"

int		main(int ac, char *av[])
{
	int		fd;
	int		ret;
	int		line;
	char	*buff;

	line = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("--------------\nError\n");
		else if (ret == 0)
			printf("--------------\nEnd of file\n");
		close (fd);
	}
	if (ac == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("---------\nError\n");
		else if (ret == 0)
			printf("---------\nEnd of stdin\n");
		close(fd);
	}
	return (0);
}
