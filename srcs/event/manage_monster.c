/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_monster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 04:35:32 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 18:29:20 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	is_next_empty(t_vars *vars, char *map, int i, int j)
{
	if (((i - 1) >= 0 && map[(i - 1) * vars->width + j] == '0') \
		&& ((i + 1) < vars->height && map[(i + 1) * vars->width + j] == '0') \
		&& (i * vars->width + (j - 1) >= 0 \
			&& map[i * vars->width + (j - 1)] == '0') \
		&& (i * vars->width + (j + 1) < vars->height * vars->width \
			&& map[i * vars->width + j + 1] == '0'))
		return (1);
	return (0);
}

static void	monster_rezen(t_vars *vars, char *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vars->height)
	{
		j = -1;
		while (++j < vars->width)
		{
			if (abs(vars->pos[X] - i) + abs(vars->pos[Y] - j) <= 2)
				break ;
			if (map[i * vars->width + j] == '0' \
				&& is_next_empty(vars, map, i, j) && \
				random_generator(ZEN_RATE))
			{
				map[i * vars->width + j] = 'M';
				vars->monster_num++;
				usleep(1);
			}
		}
	}
}

static int	patrol_progress(t_vars *vars, int i, int step)
{
	int	j;

	j = 0;
	while (j < vars->width)
	{
		if (vars->map[i * vars->width + j] == 'M')
		{
			if (vars->map[i * vars->width + j + step] == 'P')
			{
				vars->dead = 1;
				return (1);
			}
			vars->map[i * vars->width + j] = '0';
			vars->map[i * vars->width + j + step] = 'M';
			if (j < j + step)
				j += step;
		}
		j++;
	}
	return (0);
}

static void	patrol(t_vars *vars)
{
	int	i;
	int	step;

	vars->patrol++;
	if (vars->patrol == PATROL_MAX)
		vars->patrol = 0;
	if (vars->patrol % 50 != 25 && vars->patrol % 50 != 0)
		return ;
	if (vars->patrol % 50 == 25)
		step = -1;
	else if (vars->patrol % 50 == 0)
		step = 1;
	i = 0;
	while (i < vars->height)
	{
		if (patrol_progress(vars, i, step))
			return ;
		i++;
	}
}

void	manage_monster(t_vars *vars)
{
	char	*map;

	if (!vars->monster_num && vars->warning_time == 50)
	{
		vars->warning_time = 51;
		map = vars->map;
		monster_rezen(vars, map);
	}
	if (vars->monster_num)
		patrol(vars);
}
