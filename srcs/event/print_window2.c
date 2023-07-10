/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 05:05:28 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/04 18:51:41 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	warning_message(t_vars *vars)
{
	if (vars->data.m_num)
		return ;
	vars->data.warning_time++;
	if (vars->data.warning_time % 7 == 0)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->xpm.w_messege \
		, vars->width / 100 * 20, vars->height / 100 * 35);
}


void	print_window2(t_vars *vars)
{
	warning_message(vars);
}
