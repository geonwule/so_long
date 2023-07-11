/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 04:35:32 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/11 14:32:08 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_next_empty(t_vars *vars, char *map, int i, int j)
{
	if (((i - 1) >= 0 && map[(i - 1) * vars->width + j] == '0') \
		&& ((i + 1) < vars->height && map[(i + 1) * vars->width + j] == '0') \
		&& (i * vars->width + (j - 1) >= 0 && map[i * vars->width + (j - 1)] == '0') \
		&& (i * vars->width + (j + 1) < vars->height * vars->width \
			&& map[i * vars->width + j + 1] == '0'))
		return (1);
	return (0);
}

static void	monster_rezen(t_vars *vars)
{
	int		i;
	int		j;
	char	*map;

	map = vars->map;
	if (vars->monster_num || vars->warning_time < 50)
		return ;
	vars->warning_time = 0;
	i = -1;
	while (++i < vars->height)
	{
		j = -1;
		while (++j < vars->width)
		{
			if (abs(vars->pos[X] - i) + abs(vars->pos[Y] - j) <= 2)
				break ;
			if (map[i * vars->width + j] == '0' && is_next_empty(vars, map, i, j) && \
				random_generator(ZEN_RATE))
			{
				map[i * vars->width + j] = 'M';
				vars->monster_num++;
				usleep(1);
			}
		}
	}
}

static void	patrol(t_vars *vars)
{
	int	i;
	int	j;
	int	step;

	vars->patrol++;
	if (vars->patrol % 50 != 25 && vars->patrol % 50 != 0)
		return ;
	i = -1;
	while (++i < vars->height)
	{
		j = -1;
		while (++j < vars->width)
		{
			if (vars->map[i * vars->width + j] == 'M')
			{
				if (vars->patrol % 50 == 25)
					step = -1;
				else if (vars->patrol % 50 == 0)
					step = 1;
				if (vars->map[i * vars->width + j + step] == 'P')
				{
					vars->dead = 1;
					return ;
				}
				vars->map[i * vars->width + j] = '0';
				vars->map[i * vars->width + j + step] = 'M';
				if (j < j + step)
					j += step;
			}
		}
	}
}

void	manage_monster(t_vars *vars)
{
	char	*map;

	map = vars->map;
	monster_rezen(vars);
	if (vars->monster_num)
		patrol(vars);
}
