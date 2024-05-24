/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:14:28 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 15:44:00 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	can_move(t_vars *vars, int x, int y)
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
	int		pos[2];
	char	*step_str;

	pos[X] = vars->pos[X];
	pos[Y] = vars->pos[Y];
	if (can_move(vars, pos[X] + x, pos[Y] + y))
	{
		vars->map[pos[X] * vars->width + pos[Y]] = '0';
		vars->map[(pos[X] + x) * vars->width + (pos[Y] + y)] = 'P';
		vars->pos[X] += x;
		vars->pos[Y] += y;
		vars->cnt_step++;
		step_str = ft_itoa(vars->cnt_step);
		ft_write(1, "step = ");
		ft_write(1, step_str);
		ft_write(1, "\n");
		free(step_str);
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

int	key_press(int keycode, t_vars *vars)
{
	key_check(vars, keycode);
	if (keycode == UP || keycode == DOWN \
		|| keycode == LEFT || keycode == RIGHT)
		attack(vars, keycode);
	if (keycode == P)
		reset_game(vars);
	return (0);
}
