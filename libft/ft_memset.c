/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:02:29 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/05 10:20:17 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	char	*ptr;

	ptr = dest;
	while (len > 0)
	{
		*ptr = c;
		ptr++;
		len--;
	}
	return (dest);
}
