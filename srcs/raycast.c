/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:34:01 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/22 14:24:21 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			ray_position(t_img *r)
{
	r->camerax = 2 * r->i / (double)W - 1;
	r->rayposx = r->posx;
	r->rayposy = r->posy;
	r->raydirx = r->dirx + r->planex * r->camerax;
	r->raydiry = r->diry + r->planey * r->camerax;
	r->mapx = (int)r->rayposx;
	r->mapy = (int)r->rayposy;
	r->deltadistx = sqrt(1 + (r->raydiry * r->raydiry)
			/ (r->raydirx * r->raydirx));
	r->deltadisty = sqrt(1 + (r->raydirx * r->raydirx)
			/ (r->raydiry * r->raydiry));
	r->hit = 0;
}

static void			calcul_step(t_img *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->rayposx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->rayposx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->rayposy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - r->rayposy) * r->deltadisty;
	}
}

static void			perform_dda(t_img *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if ((r->map[r->mapx][r->mapy]) > 0)
			r->hit = 1;
	}
}

static void			distance_project(t_img *r)
{
	if (r->side == 0)
		r->pwall = (r->mapx - r->rayposx
				+ (1 - r->stepx) / 2) / r->raydirx;
	else
		r->pwall = (r->mapy - r->rayposy
				+ (1 - r->stepy) / 2) / r->raydiry;
	r->lineh = (int)(H / r->pwall);
	r->drawstart = (-1 * r->lineh) / 2 + H / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineh / 2 + H / 2;
	if (r->drawend >= H)
		r->drawend = H - 1;
}

int					init_raycast(t_img *r)
{
	r->i = 0;
	while (r->i < W)
	{
		ray_position(r);
		calcul_step(r);
		perform_dda(r);
		distance_project(r);
		r->y = 0;
		trace_line(r);
		r->i++;
	}
	mlx_put_image_to_window(r->mlx, r->win, r->img_ptr, 0, 0);
	return (0);
}
