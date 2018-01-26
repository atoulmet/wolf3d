/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:51:29 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/21 12:36:19 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*s;
	char			*d;
	int				i;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if (s == d || n == 0)
		return (dest);
	else if (s > d)
	{
		while (++i < (int)n)
			d[i] = s[i];
	}
	else if (s < d)
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
