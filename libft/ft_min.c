/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:44:45 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/23 16:15:32 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int *tab, int length)
{
	int i;
	int min;

	i = 0;
	min = tab[i];
	while (i < length)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			i++;
		}
		else
			i++;
	}
	return (min);
}
