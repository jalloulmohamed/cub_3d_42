/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:55:08 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 16:11:22 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_event(int key, t_cub3d *var)
{
	if (key == 13 || key == 1)
		var->key_to_move_x = key;
	if (key == 2 || key == 0)
		var->key_to_move_y = key;
	if (key == 124 || key == 123)
		var->key_to_rot = key;
	if (key == 53)
		exit(0);
	return (0);
}

int	ref(int key, t_cub3d *var)
{
	if (key == 13 || key == 1)
		var->key_to_move_x = -1;
	if (key == 2 || key == 0)
		var->key_to_move_y = -1;
	if (key == 124 || key == 123)
		var->key_to_rot = -1;
	return (0);
}

int	exit_game(int key)
{
	(void)key;
	exit(0);
}
