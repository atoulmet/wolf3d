/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:44:45 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/22 17:15:34 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int *tab, int length)
{
	int i;
	int max;

	i = 0;
	max = tab[i];
	while (i < length)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			i++;
		}
		else
			i++;
	}
	return (max);
}
