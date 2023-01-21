/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:40:13 by mjalloul          #+#    #+#             */
/*   Updated: 2023/01/21 17:21:42 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{	
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}