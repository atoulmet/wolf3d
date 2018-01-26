/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:33:28 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/21 12:27:17 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	char	ch;
	size_t	i;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (s);
}
