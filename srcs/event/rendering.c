/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:17:00 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/04 19:35:36 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	draw_mlx(t_vars *vars)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WIN_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WIN_WIDTH)
// 		{
// 			vars->info.img.data[i * WIN_WIDTH + j] = vars->info.buf[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->info.img.img, 0, 0);
// }

static int	dead_check_game_end(t_vars *vars)
{
	if (!vars->dead)
		return (0);
	if (vars->keyboard[ESC])
		exit_game(vars);
	// else if (vars->data.keyboard[P])
	// {
	// 	reset_game(vars);
	// 	vars->data.dead_check = 0;
	// 	return (0);
	// }
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
		, vars->width / 100 * 20, vars->height / 100 * 35);
}

int	rendering(t_vars *vars)
{
	if (dead_check_game_end(vars) && vars->dead_check)
		return (0);
	// print_map(vars, vars->map);
	manage_monster(vars);
	mlx_clear_window(vars->mlx, vars->win);
	fill_background(vars);
	mini_map(vars);
	warning_message(vars);
	if (vars->dead && ++vars->dead_check)
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->mini.dead, vars->pos[Y] * 50, vars->pos[X] * 50);
	return (0);
}
