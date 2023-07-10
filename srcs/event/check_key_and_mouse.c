/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_and_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:17:22 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/05 20:24:57 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	can_move(t_vars *vars, int x, int y)
{
	char	spot;

	spot = vars->map[vars->width * x + y];
	if (spot == 'C' || spot == '0')
		return (1);
	if (spot == 'M')
		vars->dead = 1;
	return (0);
}

static void	move_player(t_vars *vars, int x, int y)
{
	int	pos[2];

	pos[X] = vars->pos[X];
	pos[Y] = vars->pos[Y];
	if (can_move(vars, pos[X] + x, pos[Y] + y))
	{
		vars->map[pos[X] * vars->width + pos[Y]] = '0';
		vars->map[(pos[X] + x) * vars->width + (pos[Y] + y)] = 'P';
		vars->pos[X] += x;
		vars->pos[Y] += y;
	}
}

static void	key_check(t_vars *vars)
{
	if (vars->keyboard[ESC])
		exit_game(vars);
	if (vars->keyboard[W])
		move_player(vars, -1, 0);
	if (vars->keyboard[S])
		move_player(vars, 1, 0);
	if (vars->keyboard[D])
		move_player(vars, 0, 1);
	if (vars->keyboard[A])
		move_player(vars, 0, -1);
}

void	check_key_and_mouse(t_vars *vars)
{
	key_check(vars);
}
