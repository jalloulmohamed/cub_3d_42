/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:58:43 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 15:59:02 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 2 || argc < 2)
	{
		perror("Error: ");
	}
	else
	{
		fd = open(argv[1], O_RDONLY, 777);
		if (fd == -1)
		{
			perror("Error: ");
			return (0);
		}
		map(fd);
	}
}
