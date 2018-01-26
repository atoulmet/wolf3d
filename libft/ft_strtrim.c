/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:27:41 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/21 16:00:31 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		st;
	int		end;
	char	*str;

	i = 0;
	st = 0;
	if (s == NULL)
		return (0);
	end = ft_strlen(s) - 1;
	while (s[st] && (s[st] == ' ' || s[st] == '\n' || s[st] == '\t'))
		st++;
	while (end > 0 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
	{
		i++;
		end--;
	}
	if ((end = ft_strlen(s) - (st + i) + 1) <= 0)
		end = 1;
	str = ft_strsub(s, st, end - 1);
	return (str);
}
