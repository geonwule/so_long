/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:55:29 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 15:19:21 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	dfs(t_vars *vars, int *c_cnt, int step, int *e);

static int	one_step_go(t_vars *vars, int *c_cnt, int step, int *e)
{
	if (dfs(vars, c_cnt, step - vars->width, e))
		return (1);
	if (dfs(vars, c_cnt, step + vars->width, e))
		return (1);
	if (dfs(vars, c_cnt, step - 1, e))
		return (1);
	if (dfs(vars, c_cnt, step + 1, e))
		return (1);
	return (0);
}

static int	dfs(t_vars *vars, int *collect_cnt, int step, int *check_exit)
{
	char	*map;

	map = vars->map2;
	if (*collect_cnt == 0 && (map[step] == 'E' || *check_exit == 1))
		return (1);
	if (map[step] == '1')
		return (0);
	if (map[step] == 'E')
	{
		*check_exit = 1;
		return (0);
	}
	if (map[step] == 'C')
	{
		*collect_cnt -= 1;
		map[step] = '1';
	}
	if (map[step] == '0' || map[step] == 'P')
		map[step] = '1';
	if (one_step_go(vars, collect_cnt, step, check_exit))
		return (1);
	return (0);
}

static char	*map_copy(t_vars *vars)
{
	char	*map2;

	map2 = (char *)ft_malloc(sizeof(char) * (ft_strlen(vars->map) + 1));
	ft_strlcpy(map2, vars->map, ft_strlen(vars->map) + 1);
	return (map2);
}

void	dfs_valid_path(t_vars *vars)
{
	int	i;
	int	c_cnt;
	int	e;

	if (vars->error)
		return ;
	i = 0;
	c_cnt = vars->cnt_collect;
	vars->map2 = map_copy(vars);
	e = 0;
	if (!dfs(vars, &c_cnt, vars->pos[X] * vars->width + vars->pos[Y], &e))
		vars->error = NO_VALID;
	free(vars->map2);
}
