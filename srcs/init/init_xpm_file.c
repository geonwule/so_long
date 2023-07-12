/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 03:10:49 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 14:40:15 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	process_img_xpm_set1(t_vars *vars, int x, int y)
{
	vars->mini.player = ft_xpm_file_to_image(vars->mlx, PLAYER, &x, &y);
	vars->mini.empty = ft_xpm_file_to_image(vars->mlx, EMPTY, &x, &y);
	vars->mini.wall = ft_xpm_file_to_image(vars->mlx, WALL, &x, &y);
	vars->mini.exit_close = ft_xpm_file_to_image(vars->mlx, EXIT_CLOSE, &x, &y);
	vars->mini.exit_open = ft_xpm_file_to_image(vars->mlx, EXIT_OPEN, &x, &y);
	vars->mini.potion = ft_xpm_file_to_image(vars->mlx, POTION, &x, &y);
	vars->mini.dead = ft_xpm_file_to_image(vars->mlx, DEAD, &x, &y);
	vars->xpm.warning = ft_xpm_file_to_image(vars->mlx, WARNING, &x, &y);
}

static void	process_img_xpm_set2(t_vars *vars, int x, int y)
{
	vars->mini.mon_1 = ft_xpm_file_to_image(vars->mlx, MON1, &x, &y);
	vars->mini.mon_2 = ft_xpm_file_to_image(vars->mlx, MON2, &x, &y);
	vars->mini.mon_3 = ft_xpm_file_to_image(vars->mlx, MON3, &x, &y);
}

void	init_xpm_file(t_vars *vars)
{
	process_img_xpm_set1(vars, 0, 0);
	process_img_xpm_set2(vars, 0, 0);
}
