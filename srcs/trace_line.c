/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:36:46 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/22 14:25:16 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_img	*put_pixel(t_img *img, int x, int y, int color)
{
	int		index;
	int		i;

	i = 0;
	index = y * img->size_line + x * (img->bits_per_pixel / 8);
	while (i < (img->bits_per_pixel / 8))
	{
		img->data_addr[index + i] = *((char*)&(color) + i);
		i++;
	}
	return (img);
}

static void		colors(t_img *r)
{
	if (r->side == 0 && r->raydirx > 0)
		r->color = NORTH;
	if (r->side == 0 && r->raydirx < 0)
		r->color = SOUTH;
	if (r->side == 1 && r->raydiry < 0)
		r->color = EAST;
	if (r->side == 1 && r->raydiry > 0)
		r->color = WEST;
}

void			trace_line(t_img *r)
{
	while (r->y < r->drawstart)
	{
		r->color = SKY;
		put_pixel(r, r->i, r->y, r->color);
		r->y++;
	}
	r->y = r->drawstart;
	while (r->y < r->drawend)
	{
		colors(r);
		put_pixel(r, r->i, r->y, r->color);
		r->y++;
	}
	r->y = r->drawend;
	while (r->y < H)
	{
		r->color = GRASS;
		put_pixel(r, r->i, r->y, r->color);
		r->y++;
	}
}
