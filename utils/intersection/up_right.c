/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:33:33 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 16:40:22 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rays_h_ur(t_cub3d *var, double *hx, double *hy, double ray_angle)
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
		i += 50 / tan(M_PI * 2 - ray_angle);
	}
	*hx = i;
	*hy = j;
}

void	rays_v_ur(t_cub3d *var, double *vx, double *vy, double ray_angle)
{
	double	i;
	double	j;

	i = *vx;
	j = *vy;
	while (i > 0 && j > 0 && i < var->map_w && j < var->map_h)
	{
		if (var->map_2d[(int)floor(j) / 50][(int)floor(i) / 50] == '1')
			break ;
		i += 50;
		j -= 50 * tan(M_PI * 2 - ray_angle);
	}
	*vx = i;
	*vy = j;
}

void	up_right(t_cub3d *var, double floorx, double floory, double ray_angle)
{
	double	vx;
	double	vy;
	double	hx;
	double	hy;

	hy = floory;
	hx = ((var->p_y - floory) / tan(M_PI * 2 - ray_angle)) + var->p_x;
	vx = floorx;
	vy = var->p_y - ((floorx - var->p_x) * tan(M_PI * 2 - ray_angle));
	rays_h_ur(var, &hx, &hy, ray_angle);
	rays_v_ur(var, &vx, &vy, ray_angle);
	if (des(var, hx, hy) < des(var, vx, vy))
	{
		var->ray_type = 'u';
		var->x_wall = hx;
		var->y_wall = hy;
	}
	else
	{
		var->ray_type = 'r';
		var->x_wall = vx;
		var->y_wall = vy;
	}
}
