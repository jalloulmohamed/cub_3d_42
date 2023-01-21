/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:04:44 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/13 20:32:24 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_convert(char *p, int n, int lenp)
{
	int	k;

	k = 0;
	if (n < 0)
	{
		p[0] = '-';
		k++;
		n = n * -1;
	}
	while (n != 0)
	{
		p[lenp - 1] = (n % 10) + 48;
		n = n / 10;
		k++;
		lenp--;
	}
	p[k] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*p;

	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_intlen(n);
	p = (char *) malloc(sizeof(char) * (i + 1));
	if (!p)
		return (0);
	return (ft_convert(p, n, i));
}
