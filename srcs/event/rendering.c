/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:17:00 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 14:45:12 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	dead_check_game_end(t_vars *vars)
{
	if (vars->dead == 10000)
		exit_game(vars);
	if (!vars->dead)
		return (0);
	vars->dead++;
	if (vars->keyboard[ESC])
		exit_game(vars);
	return (1);
}

static void	warning_message(t_vars *vars)
{
	if (vars->monster_num)
		return ;
	vars->warning_time++;
	if (vars->warning_time % 7 == 0)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->xpm.warning \
		, vars->width / 4 * 50, vars->height / 3 * 50);
}

static void	print_step(t_vars *vars)
{
	char	*step;
	char	*str;

	step = ft_itoa(vars->cnt_step);
	str = ft_strjoin("step = ", step);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF, str);
	free(step);
	free(str);
}

int	rendering(t_vars *vars)
{
	if (dead_check_game_end(vars) && vars->dead_check)
		return (0);
	manage_monster(vars);
	mlx_clear_window(vars->mlx, vars->win);
	fill_background(vars);
	mini_map(vars);
	print_step(vars);
	warning_message(vars);
	if (vars->dead && ++vars->dead_check)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->mini.dead, vars->pos[Y] * 50, vars->pos[X] * 50);
	return (0);
}
