/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:14:12 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/22 15:33:43 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dead_player(t_vars *vars)
{
	map_set(vars, DEAD);
	end_game(vars, 1);
}

static void	exit_put_image(t_vars *vars, int width, int height)
{
	if (vars->c_collect == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_open,
			width * 50, height * 50);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_close,
			width * 50, height * 50);
}

static void	player_put_image(t_vars *vars, int width, int height, int key)
{
	if (key == W)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_up,
			width * 50, height * 50);
	else if (key == A)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_left,
			width * 50, height * 50);
	else if (key == S)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_down,
			width * 50, height * 50);
	else if (key == D)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_right,
			width * 50, height * 50);
	else if (key == DEAD)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_dead,
			width * 50, height * 50);
}

static void	sub_map_set(t_vars *vars, int key_code, int height, int width)
{
	if (vars->map[height * (vars->width) + width] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
			width * 50, height * 50);
	else if (vars->map[height * (vars->width) + width] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile,
			width * 50, height * 50);
	else if (vars->map[height * (vars->width) + width] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->collect,
			width * 50, height * 50);
	else if (vars->map[height * (vars->width) + width] == 'P')
		player_put_image(vars, width, height, key_code);
	else if (vars->map[height * (vars->width) + width] == 'E')
		exit_put_image(vars, width, height);
	else if (vars->map[height * (vars->width) + width] == 'M')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->monster,
			width * 50, height * 50);
}

void	map_set(t_vars *vars, int key_code)
{
	int	height;
	int	width;

	height = 0;
	while (height < vars->height)
	{
		width = 0;
		while (width < vars->width)
		{
			sub_map_set(vars, key_code, height, width);
			width++;
		}
		height++;
	}
}
