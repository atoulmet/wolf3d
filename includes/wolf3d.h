/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <atoulmet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:41:58 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/23 12:07:00 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_HEIGHT 1200
# define WIN_WIDTH 1200
# define H 1200
# define W 1200
# define GRASS 0X002F942F
# define SKY 0X0089C9FF
# define NORTH 0X00645650
# define SOUTH 0X00625750
# define EAST 0X004B4240
# define WEST 0X00433C3A
# define STRING 0X00FFFFFF

typedef struct	s_img
{
	int		**map;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	oldposx;
	double	oldposy;
	double	olddirx;
	double	olddiry;
	double	oldplanex;
	double	oldplaney;
	double	planex;
	double	planey;
	double	camerax;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	pwall;
	int		hit;
	int		side;
	int		stepx;
	int		stepy;
	int		lineh;
	int		drawstart;
	int		drawend;
	int		color;
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*data_addr;
	int		param;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	double	rot;
	int		y;
	int		i;
	double	move;
	int		speed;
}				t_img;

enum
{
	GRAPH_FAIL,
	ERROR_PARAM,
	MALLOC_ERROR,
};

void			ft_error(int flag);
int				events(t_img *img);
t_img			*init_img(t_img *img);
t_img			*env_init(t_img *img);
void			put_string(t_img *r);
int				init_raycast(t_img *r);
void			init_env(t_img *e);
int				map(int mapx, int mapy);
void			trace_line(t_img *r);
void			init_ray_value(t_img *r);
t_img			*restart_img(t_img *r);
t_img			*generate_map(t_img *r);
void			exit_success(void *r);

#endif
