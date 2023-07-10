/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_dfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:50:48 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/22 18:18:09 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// up, down, left, right -> dfs
static int	dfs(t_vars *vars, int *c_cnt, int step, int *exit)
{
	char	*map;

	map = vars->map2;
	if (*c_cnt == 0 && (map[step] == 'E' || *exit == 1))
		return (1);
	if (map[step] == '1')
		return (0);
	if (map[step] == 'E' && *c_cnt != 0)
	{
		*exit = 1;
		return (0);
	}
	if (map[step] == 'C')
	{
		*c_cnt -= 1;
		map[step] = '1';
	}
	if (map[step] == '0' || map[step] == 'P')
		map[step] = '1';
	if (one_step_go(vars, c_cnt, step, exit))
		return (1);
	return (0);
}

static char	*map_copy(t_vars *vars)
{
	char	*map2;

	map2 = (char *)malloc(sizeof(char) * (ft_strlen(vars->map) + 1));
	if (map2 == NULL)
		return (0);
	ft_strlcpy(map2, vars->map, ft_strlen(vars->map) + 1);
	return (map2);
}

int	dfs_valid_path(t_vars *vars)
{
	int	i;
	int	p;
	int	c_cnt;
	int	e;

	i = 0;
	p = 0;
	c_cnt = vars->c_collect;
	vars->map2 = map_copy(vars);
	while (vars->map[i] != '\0')
	{
		if (vars->map[i] == 'P')
			p = i;
		i++;
	}
	e = 0;
	if (!dfs(vars, &c_cnt, p, &e))
	{
		write(2, "Map error : Not valid path\n", 27);
		return (1);
	}
	return (0);
}
