/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:55:54 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 19:08:26 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays(t_cub3d	*var)
{
	double	ray_angle;
	int		ray_3d;
	double	x_wall;
	double	y_wall;

	ray_3d = 0;
	ray_angle = -VIEW / 2;
	while (ray_angle < VIEW / 2)
	{
		x_wall = 0;
		y_wall = 0;
		inters(var, var->alpha + ray_angle, &var->x_wall, &var->y_wall);
		rindring3d(var, ray_3d, ray_angle);
		ray_angle += VIEW / W_WIDTH;
		ray_3d++;
	}
}

int	get_image_add(t_cub3d *var)
{
	int	w;
	int	h;

	var->data.img = mlx_xpm_file_to_image(var->mlx, var->theme.no, &w, &h);
	var->data.adr1 = (unsigned int *)mlx_get_data_addr(var->data.img, \
		&var->data.bits_per_pixel, &var->data.line_length, &var->data.endian);
	if (w != 50 || h != 50)
		return (1);
	var->data.img = mlx_xpm_file_to_image(var->mlx, var->theme.so, &w, &h);
	var->data.adr2 = (unsigned int *)mlx_get_data_addr(var->data.img, \
		&var->data.bits_per_pixel, &var->data.line_length, &var->data.endian);
	if (w != 50 || h != 50)
		return (1);
	var->data.img = mlx_xpm_file_to_image(var->mlx, var->theme.we, &w, &h);
	var->data.adr3 = (unsigned int *)mlx_get_data_addr(var->data.img, \
		&var->data.bits_per_pixel, &var->data.line_length, &var->data.endian);
	if (w != 50 || h != 50)
		return (1);
	var->data.img = mlx_xpm_file_to_image(var->mlx, var->theme.ea, &w, &h);
	var->data.adr4 = (unsigned int *)mlx_get_data_addr(var->data.img, \
		&var->data.bits_per_pixel, &var->data.line_length, &var->data.endian);
	if (w != 50 || h != 50)
		return (1);
	return (0);
}

void	window(t_cub3d var)
{
	var.key_to_move_x = -1;
	var.key_to_move_y = -1;
	var.key_to_rot = -1;
	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, W_WIDTH, W_HEIGHT, "cub3d!");
	if (get_image_add(&var))
	{
		ft_putstr_fd("EROOR\n BAD IMAGE SIZE\n", 2);
		exit(0);
	}
	ft_ln2d_w_h(&var);
	rindring_image(&var);
	mlx_hook(var.mlx_win, 2, 1L, key_event, &var);
	mlx_hook(var.mlx_win, 3, 1L, ref, &var);
	mlx_loop_hook(var.mlx, derection, &var);
	mlx_hook(var.mlx_win, 17, 1L, exit_game, &var);
	mlx_loop(var.mlx);
}
