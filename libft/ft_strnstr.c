/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:12:23 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/05 11:09:42 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *stack, const char *need, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(need))
		return ((char *)stack);
	while (len && *stack)
	{	
		if (stack[i] == need[i])
		{
			i++;
			if (need[i] == 0 && i == ft_strlen(need))
				return ((char *)(stack));
			len--;
		}
		else
		{
			len = len + i;
			i = 0;
			stack++;
			len--;
		}
	}
	return (NULL);
}
