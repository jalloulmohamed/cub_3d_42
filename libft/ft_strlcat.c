/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:58:07 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/09 14:32:39 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *des, const char *src, size_t destsize)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (des[x] != '\0' && x != destsize)
	{
		x++;
	}
	while (src[y] != '\0' )
	{
		if ((x + 1) < destsize)
		{
			des[x] = src[y];
			des[x + 1] = '\0';
		}
		y++;
		x++;
	}
	return (x);
}
