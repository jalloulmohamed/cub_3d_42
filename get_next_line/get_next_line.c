/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:20:49 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 17:20:50 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *s, int fd, int bu)
{
	int		e;
	char	*p;

	e = 0;
	p = malloc(sizeof(char) * (bu + 1));
	if (!p)
		return (0);
	while (1)
	{
		e = read(fd, p, bu);
		if (e == -1 || (e == 0 && s[0] == '\0'))
		{
			free(s);
			s = NULL;
			free(p);
			return (0);
		}
		p[e] = '\0';
		s = ft_strjoin_free(s, p);
		if (ft_strchr1(p, '\n') == 1 || !e)
			break ;
	}
	free(p);
	return (s);
}

char	*get_next_line(int fd)
{
	int				bu;
	static char		*s;
	char			*rest;
	char			*line;

	bu = 1000;
	if (fd < 0 || bu <= 0)
		return (NULL);
	if (!s)
		s = ft_strdup("");
	s = read_line(s, fd, bu);
	if (s == NULL)
		return (0);
	line = ft_strdup1(s);
	rest = ft_strdup(s + ft_strlen(line));
	free(s);
	s = rest;
	return (line);
}
