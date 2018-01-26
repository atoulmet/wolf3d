/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:03:11 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/22 14:06:54 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_ray_value(t_img *r)
{
	r->posx = 10;
	r->posy = 12;
	r->dirx = -1;
	r->diry = 0;
	r->planex = 0;
	r->planey = 0.66;
	r->move = 0.15;
	r->rot = 0.05;
	r->speed = 0;
}

int		main(int ac, char **av)
{
	t_img	*r;

	(void)av;
	r = NULL;
	if (ac != 1)
		ft_error(ERROR_PARAM);
	r = env_init(r);
	r = init_img(r);
	r = generate_map(r);
	init_ray_value(r);
	init_raycast(r);
	mlx_put_image_to_window(r->mlx, r->win, r->img_ptr, 0, 0);
	put_string(r);
	events(r);
	mlx_loop(r->mlx);
}
