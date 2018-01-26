/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:58:22 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/24 17:52:46 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*add_following_part(char *beginning, char *following)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (beginning)
		i = ft_strlen(beginning);
	while (following[j] && following[j] != '\n')
		j++;
	if ((output = ft_memalloc(i + j + 1)) == NULL)
		return (NULL);
	if (beginning)
	{
		ft_strcpy(output, beginning);
		free(beginning);
	}
	ft_strncpy(output + i, following, j);
	output[i + j] = '\0';
	return (output);
}

static t_buffer		*new_buffer(int fd)
{
	t_buffer	*new;

	if ((new = (t_buffer*)ft_memalloc(sizeof(t_buffer))) == NULL)
		return (NULL);
	if ((new->str = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (NULL);
	new->fd = fd;
	new->offset = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static int			get_buffer(int fd, t_buffer **buf)
{
	if (!*buf)
	{
		if (!((*buf) = new_buffer(fd)))
			return (0);
		return (1);
	}
	while ((*buf)->fd != fd && (*buf)->prev != NULL)
		(*buf) = (*buf)->prev;
	while ((*buf)->fd != fd && (*buf)->next != NULL)
		(*buf) = (*buf)->next;
	if ((*buf)->fd != fd)
	{
		if (!((*buf)->next = new_buffer(fd)))
			return (0);
		(*buf)->next->prev = *buf;
		*buf = (*buf)->next;
	}
	else if ((*buf)->offset != NULL)
	{
		(*buf)->offset++;
		if (*(*buf)->offset == '\0')
			(*buf)->offset = NULL;
	}
	return (1);
}

static int			reader(t_buffer *buf)
{
	int		ret;

	ret = read(buf->fd, buf->str, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	*(buf->str + ret) = '\0';
	if (ret != 0)
		buf->offset = buf->str;
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static t_buffer	*buf = NULL;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	get_buffer(fd, &buf);
	*line = NULL;
	while (buf->offset || (ret = reader(buf)))
	{
		if (ret < 0)
			return (-1);
		if (buf->offset)
		{
			*line = add_following_part(*line, buf->offset);
			buf->offset = ft_strchr(buf->offset, '\n');
			if (buf->offset != NULL)
				return (1);
		}
	}
	return (*line != NULL ? 1 : 0);
}
