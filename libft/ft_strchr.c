/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:30:38 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/14 17:18:22 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;
	int		i;

	str = (char *)s;
	ch = c;
	i = 0;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == '\0' && c != 0)
		return (0);
	else
		return (str + i);
}
