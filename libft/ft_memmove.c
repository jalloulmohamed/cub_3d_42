/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:56:08 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/05 16:44:06 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	char	*p;
	char	*k;

	k = (char *)dest;
	p = (char *)src;
	if (p == NULL && k == NULL)
		return (0);
	if (p < k)
		while (n--)
			*(k + n) = *(p + n);
	else
		k = ft_memcpy(k, p, n);
	return (k);
}
