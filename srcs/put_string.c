/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:28:11 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/20 18:08:07 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_string(t_img *r)
{
	char	*speed;

	speed = ft_itoa(r->speed);
	mlx_string_put(r->mlx, r->win, 10, 30, STRING, "Wolfenstein 3D");
	mlx_string_put(r->mlx, r->win, 10, 50, STRING, "Speed change");
	mlx_string_put(r->mlx, r->win, 140, 50, STRING, speed);
	ft_strdel(&speed);
}
