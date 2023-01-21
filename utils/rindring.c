/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rindring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:57:02 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 17:27:46 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	wall_size(t_cub3d *var, double ray_angle)
{
	double	des_to_wall;
	double	wall_pjc;
	double	wall;

	des_to_wall = des(var, var->x_wall, var->y_wall);
	des_to_wall = des_to_wall * cos(ray_angle);
	wall_pjc = (W_WIDTH / 2) / tan((30 * M_PI) / 180);
	wall = (50 / des_to_wall) * wall_pjc;
	return (wall);
}

void	wall_texture(t_cub3d *var, int ray_3d, double y3d, double wall)
{
	int	n;
	int	m;

	n = 0;
	while (y3d <= W_HEIGHT / 2 + wall / 2)
	{
		m = -1;
		while (++m < wall / 50)
		{
			if (var->ray_type == 'l')
				my_mlx_pixel_put(var, ray_3d, (int)y3d + m, \
				*(var->data.adr3 + (int)(n * 50 + fmod(var->y_wall, 50))));
			if (var->ray_type == 'u')
				my_mlx_pixel_put(var, ray_3d, (int)y3d + m, \
				*(var->data.adr1 + (int)(n * 50 + fmod(var->x_wall, 50))));
			if (var->ray_type == 'r')
				my_mlx_pixel_put(var, ray_3d, (int)y3d + m, \
				*(var->data.adr4 + (int)(n * 50 + fmod(var->y_wall, 50))));
			if (var->ray_type == 'd')
				my_mlx_pixel_put(var, ray_3d, (int)y3d + m, \
				*(var->data.adr2 + (int)(n * 50 + fmod(var->x_wall, 50))));
		}
		n++;
		y3d += wall / 50;
	}
}

void	rindring3d(t_cub3d *var, int ray_3d, double ray_angle)
{
	double	wall;
	double	y3d;
	int		l;
	int		n;

	wall = wall_size(var, ray_angle);
	y3d = (W_HEIGHT / 2) - wall / 2;
	l = wall / 2 + W_HEIGHT / 2;
	n = 0;
	while (n < y3d)
		my_mlx_pixel_put(var, ray_3d, n++, var->theme.ciel);
	wall_texture(var, ray_3d, y3d, wall);
	while (l < W_HEIGHT)
	{
		my_mlx_pixel_put(var, ray_3d, l, var->theme.floor);
		l++;
	}
}
