/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:18:11 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/08 10:20:06 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t	n)
{
	size_t	i;
	char	*p;
	char	*k;

	p = (char *)dest;
	k = (char *)src;
	i = 0;
	if (p == NULL && k == NULL)
		return (0);
	while (n)
	{
		p[i] = k[i];
		i++;
		n--;
	}
	return (p);
}
