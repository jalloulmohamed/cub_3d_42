/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:56:09 by amiski            #+#    #+#             */
/*   Updated: 2023/01/21 18:49:36 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_map1(char **map2d, int i, int j)
{
	if (map2d[i][j] == '0')
		if (!ft_strchr("NSEW10", map2d[i][j + 1]) || \
		!ft_strchr("NSEW10", map2d[i][j - 1]) || \
		!ft_strchr("NSEW10", map2d[i + 1][j]) || \
		!ft_strchr("NSEW10", map2d[i - 1][j]))
			return (3);
	if (!ft_strchr("NSEW10 \t\n", map2d[i][j]))
		return (4);
	if (ft_strchr("NSEW", map2d[i][j]))
		return (5);
	return (0);
}

void	ft_free(char **tab, char *s)
{
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab);
	free(s);
}

int	nbr_v(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	path_valid(char *s, char **tex)
{
	int		fd;
	char	*tmp;

	tmp = ft_strtrim(s, " \t");
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (fd < 0)
	{
		printf("Error\nbad texture\n");
		free(s);
		return (0);
	}
	close(fd);
	*tex = ft_strtrim(s, " \t\n");
	free(s);
	return (1);
}

int	check_color(char *s, unsigned int *var)
{
	char	**color;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (nbr_v(s) != 2)
		return (0);
	color = ft_split(s, ',');
	while (color[i])
	{
		j = ft_atoi(color[i]);
		tmp = ft_strtrim(color[i], " \t\n");
		if (ft_strlen(tmp) > 3 || j > 255 || j < 0)
			return (free(tmp), 0);
		free(tmp);
		i++;
	}
	*var = (ft_atoi(color[0]) << 16) | (ft_atoi(color[1]) << 8) | \
		(ft_atoi(color[2]));
	ft_free(color, s);
	return (1);
}
