/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:03:26 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 16:05:49 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	inters(t_cub3d *var, double ray_angle, double *x_wall, double *y_wall)
{
	double	x;
	double	y;

	x = *x_wall;
	y = *y_wall;
	ray_angle = cor_angle(ray_angle);
	flor_x(var, &x, ray_angle);
	flor_y(var, &y, ray_angle);
	if (ft_up(ray_angle) && ft_right(ray_angle))
		up_right(var, x, y, ray_angle);
	if (ft_up(ray_angle) && ft_left(ray_angle))
		up_left(var, x, y, ray_angle);
	if (ft_down(ray_angle) && ft_right(ray_angle))
		down_right(var, x, y, ray_angle);
	if (ft_down(ray_angle) && ft_left(ray_angle))
		down_left(var, x, y, ray_angle);
}
