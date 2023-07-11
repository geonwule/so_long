/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:14:28 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/11 17:20:04 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_vars *vars)
{
	if (keycode >= 0 && keycode <= 255)
		vars->keyboard[keycode] = 0;
	return (0);
}

static int	can_move2(t_vars *vars, int x, int y)
{
	char	spot;

	spot = vars->map[vars->width * x + y];
	if (spot == 'C' || spot == '0')
	{
		if (spot == 'C')
			vars->cnt_collect -= 1;
		return (1);
	}
	if (spot == 'E' && vars->cnt_collect == 0)
	{
		write(1, "Success game\n", 13);
		exit_game(vars);
	}
	if (spot == 'M')
		vars->dead = 1;
	return (0);
}

static void	move_player(t_vars *vars, int x, int y)
{
	int	pos[2];

	pos[X] = vars->pos[X];
	pos[Y] = vars->pos[Y];
	if (can_move2(vars, pos[X] + x, pos[Y] + y))
	{
		vars->map[pos[X] * vars->width + pos[Y]] = '0';
		vars->map[(pos[X] + x) * vars->width + (pos[Y] + y)] = 'P';
		vars->pos[X] += x;
		vars->pos[Y] += y;
		vars->cnt_step++;
	}
}

static void	key_check(t_vars *vars, int keycode)
{
	if (keycode == ESC)
		exit_game(vars);
	if (keycode == W)
		move_player(vars, -1, 0);
	if (keycode == S)
		move_player(vars, 1, 0);
	if (keycode == D)
		move_player(vars, 0, 1);
	if (keycode == A)
		move_player(vars, 0, -1);
}

void	attack(t_vars *vars, int key)
{
	int	pos[2];

	pos[X] = vars->pos[X];
	pos[Y] = vars->pos[Y];
	if (vars->dead)
		return ;
	if (key == UP && pos[X] - 1 >= 0)
		pos[X] -= 1;
	if (key == DOWN && pos[X] + 1 < vars->height)
		pos[X] += 1;
	if (key == LEFT && pos[Y] - 1 >= 0)
		pos[Y] -= 1;
	if (key == RIGHT && pos[Y] + 1 < vars->width)
		pos[Y] += 1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mini.exit_open,\
							 pos[Y] * 50, pos[X] * 50);
	if (vars->map[pos[X] * vars->width + pos[Y]] == 'M')
		vars->map[pos[X] * vars->width + pos[Y]] = '0';
}

void	reset_game(t_vars *vars)
{
	free(vars->map);
	read_file(vars, vars->file_name);
	init_vars_info(vars);
}

int	key_press(int keycode, t_vars *vars)
{
	// t_info	*info;
	// char	**map;

	key_check(vars, keycode);
	if (keycode == UP || keycode == DOWN \
		|| keycode == LEFT || keycode == RIGHT)
		attack(vars, keycode);
	if (keycode == P)
		reset_game(vars);
	if (keycode >= 0 && keycode <= 255)
		vars->keyboard[keycode] = 1;
	return (0);
}
