/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:23:47 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/11 14:36:38 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_mini_xpm(t_vars *vars, char *map, int x, int y)
{
	if (map[x * vars->width + y] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->mini.player, y * 50, x * 50);
	else if (map[x * vars->width + y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->mini.wall, y * 50, x * 50);
	else if (map[x * vars->width + y] == 'M')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->mini.monster, y * 50, x * 50);
	else if (map[x * vars->width + y] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->mini.potion, y * 50, x * 50);
	else if (map[x * vars->width + y] == 'E')
	{
		if (vars->cnt_collect > 0)
			mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->mini.exit_close, y * 50, x * 50);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->mini.exit_open, y * 50, x * 50);
	}
	// else if (map[x][y] == 'H')
	// 	mlx_put_image_to_window(vars->mlx, vars->win, \
	// 				vars->mini.npc, y * 50, x * 50);
}

static void	fill_minimap(t_vars *vars, char *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->height)
	{
		y = 0;
		while (y < vars->width)
		{
			put_mini_xpm(vars, map, x, y);
			y++;
		}
		x++;
	}
}

void	mini_map(t_vars *vars)
{
	fill_minimap(vars, vars->map);
}
