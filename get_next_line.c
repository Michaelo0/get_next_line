/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:14:02 by vmarilli          #+#    #+#             */
/*   Updated: 2019/10/19 23:25:27 by vmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_verify(char **buff, char **line)
{
	char	*tmp;
	char	*ptr;
	int		i;
	
	i = 0;
	ptr = *buff;
	while (ptr[i] != '\n')
		if (!ptr[i++])
			return (0);
	tmp = &ptr[i];
	*tmp = '\0';
	*line = ft_strdup(*buff);
	*buff = ft_strdup(tmp + 1);
	return (1);
}

static int	ft_read_file(int fd, char *heap, char **stack, char **line)
{
	int		ret;
	char	*tmp_stack;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (ft_verify(stack, line))
			break ;
	}
	return (ret > 0 ? 1 : ret);
}

int		get_next_line(int const fd, char **line)
{
	static char	*stack[2048];
	char		*heap;
	int			ret;
	int			i;

	if (!line || (fd < 0 || fd >= 1024) || (read(fd, stack[fd], 0) < 0) \
			|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (ft_verify(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = ft_read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (-1);
}
