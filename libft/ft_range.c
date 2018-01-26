/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:15:02 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/22 17:13:58 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *tab;
	int len;
	int i;
	int a;

	i = min;
	a = 0;
	len = max - min;
	tab = (int*)malloc(sizeof(int) * len);
	if (i >= max)
		return (0);
	while (i < max)
	{
		tab[a] = i;
		i++;
		a++;
	}
	return (tab);
}
