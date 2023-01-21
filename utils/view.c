/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:55:35 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 16:01:10 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_down(double angle)
{
	return (angle >= 0 && angle < M_PI);
}

int	ft_up(double angle)
{
	return (!ft_down(angle));
}

int	ft_right(double angle)
{
	return (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
}

int	ft_left(double angle)
{
	return (!ft_right(angle));
}

double	cor_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle <= 0)
	{
		angle += 2 * M_PI;
	}
	return (angle);
}
