/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:42:23 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/23 15:51:43 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fill(const char *s, char **str, char c)
{
	int		i;
	int		j;
	int		w;

	i = 0;
	j = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			j = 0;
			while (s[i + j] && s[j + i] != c)
				j++;
			str[w++] = ft_strsub(s, i, j);
			i = i + j;
		}
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		w;
	char	**str;

	if (!s)
		return (NULL);
	w = ft_wordscount(s, c);
	if ((str = ft_memalloc(sizeof(char*) * (w + 1))) == NULL)
		return (NULL);
	str = ft_fill(s, str, c);
	return (str);
}
