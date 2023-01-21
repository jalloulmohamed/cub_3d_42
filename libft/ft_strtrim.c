/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:23:01 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 17:22:11 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check1(char const *s1, char const *set)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (set[k])
	{	
		if (set[k] == s1[i])
		{
			i++;
			k = 0;
		}
		else
			k++;
	}
	return (i);
}

static int	ft_check2(char const *s1, char const *set, int j)
{
	int	k;

	k = 0;
	while (set[k])
	{	
		if (set[k] == s1[j])
		{
			j--;
			k = 0;
		}
		else
			k++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*p;
	int		j;
	int		k;

	k = 0;
	i = 0;
	if (s1 == NULL)
		return ((char *)s1);
	j = ft_strlen(s1) - 1;
	i = ft_check1(s1, set);
	j = ft_check2(s1, set, j);
	k = j - i + 1;
	if (k <= 0)
		return (ft_strdup("\0"));
	j = k;
	p = malloc(sizeof(*s1) * (k + 1));
	if (!p)
		return (0);
	while (k--)
		*p++ = s1[i++];
	*p = '\0';
	return (p - j);
}
