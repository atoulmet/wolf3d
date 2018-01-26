/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:35:25 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/22 14:22:04 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		*get_map_line(char *line)
{
	int	*map_line;
	int	i;
	int j;

	i = 0;
	j = 0;
	if ((map_line = (int*)ft_memalloc(sizeof(int) * 22)) == NULL)
		ft_error(MALLOC_ERROR);
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
		{
			map_line[j] = ft_atoi(line + i);
			j++;
			i++;
		}
		else
			i++;
	}
	return (map_line);
}

static int		**get_map(int fd)
{
	int		**map;
	int		j;
	char	*line;

	j = 0;
	if ((map = (int**)ft_memalloc(sizeof(int*) * 22)) == NULL)
		ft_error(MALLOC_ERROR);
	while (get_next_line(fd, &line) == 1)
	{
		map[j] = get_map_line(line);
		j++;
	}
	close(fd);
	return (map);
}

t_img			*generate_map(t_img *r)
{
	int		fd;

	if ((fd = open("map1", O_RDONLY)) == 0)
		ft_error(GRAPH_FAIL);
	r->map = get_map(fd);
	return (r);
}
