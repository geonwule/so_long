/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 03:10:49 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 15:53:04 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_vars_info(t_vars *vars)
{
	vars->map = NULL;
	vars->height = 0;
	vars->width = 0;
	vars->cnt_step = 0;
	vars->cnt_collect = 0;
	vars->dead = 0;
	vars->dead_check = 0;
	vars->error = 0;
	vars->monster_num = 0;
	vars->warning_time = 0;
	vars->patrol = 0;
	vars->sprite = 0;
}
