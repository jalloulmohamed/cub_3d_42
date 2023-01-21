/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:55:52 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/04 15:55:34 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*p;
	char	*k;

	p = (char *)s1;
	k = (char *)s2;
	while (n)
	{
		if (*p != *k)
			return ((unsigned char)*p - (unsigned char)*k);
		p++;
		k++;
		n--;
	}
	return (0);
}
