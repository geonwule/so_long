/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:24:20 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/04 18:12:21 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_background(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->height)
	{
		y = 0;
		while (y < vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->mini.empty, y * 50, x * 50);
			y++;
		}
		x++;
	}
}