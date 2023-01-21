/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:54:30 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 17:10:31 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_cub3d *var, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < W_WIDTH) && (y >= 0 && y < W_HEIGHT))
	{
		dst = var->data.addr + (y * var->data.line_length \
				+x * (var->data.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	rindring_image(t_cub3d *var)
{
	var->data.img = mlx_new_image(var->mlx, W_WIDTH, W_HEIGHT);
	var->data.addr = mlx_get_data_addr(var->data.img, \
	&var->data.bits_per_pixel, &var->data.line_length, &var->data.endian);
	rays(var);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->data.img, 0, 0);
	mlx_destroy_image (var->mlx, var->data.img);
}

void	move_x(t_cub3d *var)
{
	int	i;
	int	j;

	if (var->key_to_move_x == KEY_W)
	{
		i = (int)floor((var->p_x + 20 * cos(var->alpha)) / 50);
		j = (int)floor((var->p_y + 20 * sin(var->alpha)) / 50);
		if (var->map_2d[j][i] == '0')
		{
			var->p_x += STEP * cos(var->alpha);
			var->p_y += STEP * sin(var->alpha);
		}
	}
	else if (var->key_to_move_x == KEY_S)
	{
		i = (int)floor((var->p_x - 20 * cos(var->alpha)) / 50);
		j = (int)floor((var->p_y - 20 * sin(var->alpha)) / 50);
		if (var->map_2d[j][i] == '0')
		{
			var->p_x -= STEP * cos(var->alpha);
			var->p_y -= STEP * sin(var->alpha);
		}
	}
}

void	move_y(t_cub3d *var)
{
	int	i;
	int	j;

	if (var->key_to_move_y == KEY_A)
	{
		i = (int)floor((var->p_x - 20 * cos(var->alpha + M_PI_2)) / 50);
		j = (int)floor((var->p_y - 20 * sin(var->alpha + M_PI_2)) / 50);
		if (var->map_2d[j][i] == '0')
		{
			var->p_x -= STEP * cos(var->alpha + M_PI_2);
			var->p_y -= STEP * sin(var->alpha + M_PI_2);
		}
	}
	else if (var->key_to_move_y == KEY_D)
	{
		i = (int)floor((var->p_x + 20 * cos(var->alpha + M_PI_2)) / 50);
		j = (int)floor((var->p_y + 20 * sin(var->alpha + M_PI_2)) / 50);
		if (var->map_2d[j][i] == '0')
		{
			var->p_x += STEP * cos(var->alpha + M_PI_2);
			var->p_y += STEP * sin(var->alpha + M_PI_2);
		}
	}
}

int	derection(t_cub3d *var)
{
	if (var->key_to_rot != -1)
	{
		if (var->key_to_rot == 124)
			var->alpha += 0.1;
		else if (var->key_to_rot == 123)
			var->alpha -= 0.1;
		rindring_image(var);
	}
	if (var->key_to_move_y != -1)
	{
		move_y(var);
		rindring_image(var);
	}
	if (var->key_to_move_x != -1)
	{
		move_x(var);
		rindring_image(var);
	}
	return (0);
}
