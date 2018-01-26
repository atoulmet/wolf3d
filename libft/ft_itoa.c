/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:30:05 by atoulmet          #+#    #+#             */
/*   Updated: 2016/11/21 16:22:32 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*convert_itoc(int n, int neg, int i, char *str)
{
	char	c;

	str[i + 1] = '\0';
	while (n > 9)
	{
		c = n % 10 + '0';
		str[i] = c;
		i--;
		n = n / 10;
	}
	str[i] = n + '0';
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		neg;
	int		d;

	i = 1;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n = -n;
		i++;
	}
	d = n;
	while (d > 9)
	{
		d = d / 10;
		i++;
	}
	if ((str = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (0);
	str = convert_itoc(n, neg, i - 1, str);
	return (str);
}
