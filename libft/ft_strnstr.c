/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:36:01 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/23 15:26:04 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (len == 0)
		return (0);
	if ((s1[i] == '\0' && s2[j] == '\0') || s2[j] == '\0')
		return ((char*)s1);
	while (s1[i] && i < (int)len)
	{
		while (s1[i + j] == s2[j] && s2[j] && j + i < (int)len)
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		j = 0;
		i++;
	}
	return (0);
}
