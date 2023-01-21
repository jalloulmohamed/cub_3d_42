/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:55:14 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 16:03:08 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_ln2d_w_h(t_cub3d *var)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	j = 0;
	i = 0;
	while (var->map_2d[i])
	{
		while (var->map_2d[i][j])
		{
			j++;
		}
		if (j > len)
			len = j;
		j = 0;
		i++;
	}
	var->map_w = (len - 1) * 50;
	var->map_h = i * 50;
}
