/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:22:28 by atoulmet          #+#    #+#             */
/*   Updated: 2017/03/20 13:06:34 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_error(int flag)
{
	if (flag == GRAPH_FAIL)
	{
		ft_putendl("Graphic failure.");
		exit(0);
	}
	if (flag == MALLOC_ERROR)
	{
		ft_putendl("Malloc failure.");
		exit(0);
	}
	if (flag == ERROR_PARAM)
	{
		ft_putendl("Usage Error");
		exit(0);
	}
}
