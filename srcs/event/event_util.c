/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:43:13 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 18:32:15 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->xpm.exit_open, \
							pos[Y] * 50, pos[X] * 50);
	if (vars->map[pos[X] * vars->width + pos[Y]] == 'M')
		vars->map[pos[X] * vars->width + pos[Y]] = '0';
}

void	reset_game(t_vars *vars)
{
	free(vars->map);
	init_vars_info(vars);
	read_file(vars, vars->file_name);
}
