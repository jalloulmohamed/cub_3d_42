/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:27:12 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 16:33:28 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rays_h_ul(t_cub3d *var, double *hx, double *hy, double ray_angle)
{
	double	i;
	double	j;

	i = *hx;
	j = *hy;
	while (i > 0 && j > 0 && i < var->map_w && j < var->map_h)
	{
		if (var->map_2d[(int)floor(j) / 50 - 1][(int)floor(i) / 50] == '1')
			break ;
		j -= 50;
		i -= 50 / tan(ray_angle - M_PI);
	}
	*hx = i;
	*hy = j;
}

void	rays_v_ul(t_cub3d *var, double *vx, double *vy, double ray_angle)
{
	double	i;
	double	j;

	i = *vx;
	j = *vy;
	while (i > 0 && j > 0 && i < var->map_w && j < var->map_h)
	{
		if (var->map_2d[(int)floor(j) / 50][(int)floor(i) / 50 - 1] == '1')
			break ;
		i -= 50;
		j -= 50 * tan(ray_angle - M_PI);
	}
	*vx = i;
	*vy = j;
}

void	up_left(t_cub3d *var, double floorx, double floory, double ray_angle)
{
	double	vx;
	double	vy;
	double	hx;
	double	hy;

	hy = floory;
	hx = var->p_x - ((var->p_y - floory) / tan(ray_angle - M_PI));
	vx = floorx;
	vy = var->p_y - ((var->p_x - floorx) * tan(ray_angle - M_PI));
	rays_h_ul(var, &hx, &hy, ray_angle);
	rays_v_ul(var, &vx, &vy, ray_angle);
	if (des(var, hx, hy) < des(var, vx, vy))
	{
		var->ray_type = 'u';
		var->x_wall = hx;
		var->y_wall = hy;
	}
	else
	{
		var->ray_type = 'l';
		var->x_wall = vx;
		var->y_wall = vy;
	}
}
