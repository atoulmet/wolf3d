/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:59:41 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/22 14:24:46 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_img		*restart_img(t_img *r)
{
	mlx_destroy_image(r->mlx, r->img_ptr);
	r = init_img(r);
	init_raycast(r);
	mlx_put_image_to_window(r->mlx, r->win, r->img_ptr, 0, 0);
	put_string(r);
	return (r);
}
