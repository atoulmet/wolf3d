/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:12:18 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/23 12:08:43 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		up_down(int keycode, t_img *r)
{
	if (keycode == 126)
	{
		if ((r->map[(int)(r->posx + r->dirx * r->move)][(int)(r->posy)]) == 0)
			r->posx += r->dirx * r->move;
		if ((r->map[(int)r->posx][(int)(r->posy + r->diry * r->move)]) == 0)
			r->posy += r->diry * r->move;
		restart_img(r);
	}
	if (keycode == 125)
	{
		if ((r->map[(int)(r->posx - r->dirx * r->move)][(int)(r->posy)]) == 0)
			r->posx -= r->dirx * r->move;
		if ((r->map[(int)r->posx][(int)(r->posy - r->diry * r->move)]) == 0)
			r->posy -= r->diry * r->move;
		restart_img(r);
	}
}

static void		left_right(int keycode, t_img *r)
{
	if (keycode == 124)
	{
		r->olddirx = r->dirx;
		r->dirx = r->dirx * cos(-r->rot) - r->diry * sin(-r->rot);
		r->diry = r->olddirx * sin(-r->rot) + r->diry * cos(-r->rot);
		r->oldplanex = r->planex;
		r->planex = r->planex * cos(-r->rot) - r->planey * sin(-r->rot);
		r->planey = r->oldplanex * sin(-r->rot) + r->planey * cos(-r->rot);
		restart_img(r);
	}
	if (keycode == 123)
	{
		r->olddirx = r->dirx;
		r->dirx = r->dirx * cos(r->rot) - r->diry * sin(r->rot);
		r->diry = r->olddirx * sin(r->rot) + r->diry * cos(r->rot);
		r->oldplanex = r->planex;
		r->planex = r->planex * cos(r->rot) - r->planey * sin(r->rot);
		r->planey = r->oldplanex * sin(r->rot) + r->planey * cos(r->rot);
		restart_img(r);
	}
}

static int		key_hook(int keycode, t_img *r)
{
	if (keycode == 53)
		exit_success(r);
	up_down(keycode, r);
	left_right(keycode, r);
	if (keycode == 3 && r->rot < 0.4)
	{
		r->rot += 0.005;
		r->move += 0.015;
		(r->speed)++;
		restart_img(r);
	}
	if (keycode == 1 && r->rot > 0.01)
	{
		r->rot -= 0.005;
		r->move -= 0.015;
		(r->speed)--;
		restart_img(r);
	}
	if (keycode == 49)
	{
		init_ray_value(r);
		restart_img(r);
	}
	return (0);
}

static int		close_win(t_img *r)
{
	exit_success(r);
	return (0);
}

int				events(t_img *r)
{
	mlx_hook(r->win, 2, 3, key_hook, r);
	mlx_hook(r->win, 17, 0, close_win, r);
	return (0);
}
