/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:33:14 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/20 13:02:16 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_img			*env_init(t_img *r)
{
	if ((r = (t_img*)ft_memalloc(sizeof(t_img))) == NULL)
		ft_error(MALLOC_ERROR);
	if ((r->mlx = mlx_init()) == NULL)
		ft_error(GRAPH_FAIL);
	if ((r->win = mlx_new_window(r->mlx, WIN_WIDTH,
					WIN_HEIGHT, "Wolfenstein")) == NULL)
		ft_error(GRAPH_FAIL);
	r->height = WIN_HEIGHT;
	r->width = WIN_WIDTH;
	return (r);
}

t_img			*init_img(t_img *r)
{
	if ((r->img_ptr = mlx_new_image(r->mlx, r->width,
					r->height)) == NULL)
		ft_error(GRAPH_FAIL);
	r->data_addr = mlx_get_data_addr(r->img_ptr, &(r->bits_per_pixel),
			&(r->size_line), &(r->endian));
	return (r);
}
