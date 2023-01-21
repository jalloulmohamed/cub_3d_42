/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:33:00 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/05 17:35:55 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	int		i;
	int		j;

	j = 0;
	i = count * size;
	p = (char *)malloc (sizeof(char) * i);
	if (!p)
		return (0);
	while (i)
	{
		p[j] = '\0';
		i--;
		j++;
	}
	return (p);
}
