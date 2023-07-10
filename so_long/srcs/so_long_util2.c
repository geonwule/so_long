/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:52:56 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/22 18:30:03 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_vars *vars, int fail_or_win)
{
	if (fail_or_win)
		write(1, "Oh my god... fail...\n", 21);
	else
		write(1, "Success!! game end!!\n", 21);
	mlx_destroy_window(vars->mlx, vars->win);
	var_free(vars);
	exit(0);
}

int	exit_game(t_vars *vars)
{
	write(1, "Player has exited the game\n", 27);
	mlx_destroy_window(vars->mlx, vars->win);
	var_free(vars);
	exit(0);
}

void	var_free(t_vars *vars)
{
	if (vars->map)
		free(vars->map);
	if (vars->map2)
		free(vars->map2);
	free(vars);
}

void	move_counting(t_vars *vars)
{
	char	*c;

	vars->c_move++;
	c = ft_itoa(vars->c_move);
	write(1, "now step = ", 10);
	write(1, c, ft_strlen(c));
	write(1, "\n", 1);
	free(c);
}

void	img_xpm_set(t_vars *vars)
{
	int	x;
	int	y;

	vars->wall = mlx_xpm_file_to_image(vars->mlx, WALL, &x, &y);
	vars->tile = mlx_xpm_file_to_image(vars->mlx, TILE, &x, &y);
	vars->chobo_up = mlx_xpm_file_to_image(vars->mlx, CHOBO_UP, &x, &y);
	vars->chobo_down = mlx_xpm_file_to_image(vars->mlx, CHOBO_DOWN, &x, &y);
	vars->chobo_right = mlx_xpm_file_to_image(vars->mlx, CHOBO_RIGHT, &x, &y);
	vars->chobo_left = mlx_xpm_file_to_image(vars->mlx, CHOBO_LEFT, &x, &y);
	vars->chobo_dead = mlx_xpm_file_to_image(vars->mlx, CHOBO_DEAD, &x, &y);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, COLLECT, &x, &y);
	vars->exit_close = mlx_xpm_file_to_image(vars->mlx, EXIT_CLOSE, &x, &y);
	vars->exit_open = mlx_xpm_file_to_image(vars->mlx, EXIT_OPEN, &x, &y);
	vars->monster = mlx_xpm_file_to_image(vars->mlx, MONSTER, &x, &y);
}
