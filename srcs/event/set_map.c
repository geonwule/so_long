/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:23:47 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 18:31:22 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	sprite_monster(t_vars *vars, int x, int y)
{
	if (vars->sprite % 30 < 10)
		mlx_put_image_to_window(vars->mlx, vars->win, \
							vars->xpm.mon_1, y * 50, x * 50);
	else if (vars->sprite % 30 < 20)
		mlx_put_image_to_window(vars->mlx, vars->win, \
							vars->xpm.mon_2, y * 50, x * 50);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, \
							vars->xpm.mon_3, y * 50, x * 50);
}

static void	put_map_xpm(t_vars *vars, char *map, int x, int y)
{
	if (map[x * vars->width + y] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->xpm.player, y * 50, x * 50);
	else if (map[x * vars->width + y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->xpm.wall, y * 50, x * 50);
	else if (map[x * vars->width + y] == 'M')
		sprite_monster(vars, x, y);
	else if (map[x * vars->width + y] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->xpm.collect, y * 50, x * 50);
	else if (map[x * vars->width + y] == 'E')
	{
		if (vars->cnt_collect > 0)
			mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->xpm.exit_close, y * 50, x * 50);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, \
						vars->xpm.exit_open, y * 50, x * 50);
	}
}

static void	fill_map(t_vars *vars, char *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < vars->height)
	{
		y = 0;
		while (y < vars->width)
		{
			put_map_xpm(vars, map, x, y);
			y++;
		}
		x++;
	}
}

void	set_map(t_vars *vars)
{
	vars->sprite++;
	fill_map(vars, vars->map);
}
