/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:30:23 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/22 15:36:01 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	input_w(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break ;
		i++;
	}
	if (i - vars->width < 0 || vars->map[i - vars->width] == '1')
		return ;
	if (vars->map[i - vars->width] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i - vars->width] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i - vars->width] == 'M')
		dead_player(vars);
	else if (vars->map[i - vars->width] != '1'
		&& vars->map[i - vars->width] != 'E')
	{
		vars->map[i - vars->width] = 'P';
		vars->map[i] = '0';
		map_set(vars, W);
		move_counting(vars);
	}
}

static void	input_a(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break ;
		i++;
	}
	if (i - 1 < 0 || vars->map[i - 1] == '1')
		return ;
	if (vars->map[i - 1] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i - 1] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i - 1] == 'M')
		dead_player(vars);
	else if (vars->map[i - 1] != '1' && vars->map[i - 1] != 'E')
	{
		vars->map[i - 1] = 'P';
		vars->map[i] = '0';
		map_set(vars, A);
		move_counting(vars);
	}
}

static void	input_s(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break ;
		i++;
	}
	if (i + vars->width < 0 || vars->map[i + vars->width] == '1')
		return ;
	if (vars->map[i + vars->width] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i + vars->width] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i + vars->width] == 'M')
		dead_player(vars);
	else if (vars->map[i + vars->width] != '1'
		&& vars->map[i + vars->width] != 'E')
	{
		vars->map[i + vars->width] = 'P';
		vars->map[i] = '0';
		map_set(vars, S);
		move_counting(vars);
	}
}

static void	input_d(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break ;
		i++;
	}
	if (i + 1 < 0 || vars->map[i + 1] == '1')
		return ;
	if (vars->map[i + 1] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i + 1] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i + 1] == 'M')
		dead_player(vars);
	else if (vars->map[i + 1] != '1' && vars->map[i + 1] != 'E')
	{
		vars->map[i + 1] = 'P';
		vars->map[i] = '0';
		map_set(vars, D);
		move_counting(vars);
	}
}

int	keyboard_input(int keycode, t_vars *vars)
{
	if (keycode == W)
		input_w(vars);
	else if (keycode == A)
		input_a(vars);
	else if (keycode == S)
		input_s(vars);
	else if (keycode == D)
		input_d(vars);
	else if (keycode == ESC)
		exit_game(vars);
	return (0);
}
