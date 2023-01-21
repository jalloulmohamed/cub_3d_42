/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:55:11 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 17:39:08 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	des(t_cub3d *var, double x, double y)
{
	return (sqrt((var->p_x - x) * (var->p_x - x) \
	+(var->p_y - y) * (var->p_y - y)));
}

void	flor_x(t_cub3d *var, double *x, double ray_angle)
{
	double	x1;

	if (ft_right(ray_angle))
		x1 = floor(var->p_x / 50) * 50 + 50;
	if (ft_left(ray_angle))
		x1 = floor(var->p_x / 50) * 50;
	*x = x1;
}

void	flor_y(t_cub3d *var, double *y, double ray_angle)
{
	double	y1;

	if (ft_up (ray_angle))
		y1 = floor(var->p_y / 50) * 50 ;
	if (ft_down(ray_angle))
		y1 = floor(var->p_y / 50) * 50 + 50;
	*y = y1;
}
