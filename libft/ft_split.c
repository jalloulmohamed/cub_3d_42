/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:58:34 by mjalloul          #+#    #+#             */
/*   Updated: 2021/11/14 22:24:26 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	ntable(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i + 1] == '\0' && s[i] != c))
			j++;
		i++;
	}
	return (j);
}

static int	ft_strlen_del(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

static char	**alocation(char **p, int k, char c, char const *s)
{
	int	f;
	int	j;

	f = 0;
	j = 0;
	while (k)
	{
		p[f] = (char *)malloc(sizeof(char ) * (ft_strlen_del(s, c) + 1));
		if (!p)
			return (0);
		while (ft_strlen_del(s, c))
			p[f][j++] = *s++;
		p[f][j] = '\0';
		if (p[f][0] == '\0')
			free (p[f]);
		else
		{
			f++;
			k--;
		}
		s++;
		j = 0;
	}
	p[f] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**p;

	if (s == NULL)
		return (0);
	k = ntable(s, c);
	p = (char **)malloc(sizeof(char *) * (k + 1));
	if (!p)
		return (0);
	return (alocation(p, k, c, s));
}
