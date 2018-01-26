/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:20:17 by atoulmet          #+#    #+#             */
/*   Updated: 2016/12/17 12:20:30 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *src, int len)
{
	char	*dest;
	int		l;
	int		i;

	l = ft_strlen(src);
	i = 0;
	dest = (char *)malloc(sizeof(char) * l + 1);
	if (dest == NULL)
		return (0);
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	if (src == NULL)
		dest = NULL;
	return (dest);
}
