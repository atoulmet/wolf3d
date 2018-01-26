/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:14:34 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/14 15:13:45 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memchr(const void *dst, int c, unsigned int t)
{
	unsigned char		*s;
	unsigned char		ch;
	unsigned int		i;

	s = (unsigned char *)dst;
	ch = (unsigned char)c;
	i = 0;
	if (t == 0)
		return (0);
	while (i < t)
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	return (0);
}
