/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:10:31 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/30 16:13:53 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_arg_check(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != '\0')
	{
		if (!(vars->map[i] == '0' || vars->map[i] == '1' || vars->map[i] == 'C'
				|| vars->map[i] == 'E' || vars->map[i] == 'P'))
		{
			write(2, "Map error : Argument error\n", 27);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	min_map_contain(t_vars *vars)
{
	if (vars->contain != 1)
	{
		write(2, "Map error : Not enough or overflow map consist\n", 47);
		return (1);
	}
	return (0);
}

static int	rectangular_check(t_vars *vars)
{
	if (vars->width_e == -1)
	{
		write(2, "Map error : Map is not rectangular\n", 35);
		return (1);
	}
	return (0);
}

static int	surrounded_wall(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i] != '\0')
	{
		if ((i < vars->width && vars->map[i] != '1')
			|| (i % vars->width == 0 && vars->map[i] != '1')
			|| ((i >= vars->width * (vars->height - 1)) && vars->map[i] != '1')
			|| ((i + 1) % vars->width == 0 && vars->map[i] != '1'))
		{
			write(2, "Map error : Not surrounded wall\n", 32);
			return (1);
		}
		i++;
	}
	return (0);
}

int	map_error(t_vars *vars)
{
	int	ret;

	ret = 0;
	if (vars->fd < 0)
	{
		write(2, "Error : is not file\n", 20);
		ret = 1;
	}
	else if (map_arg_check(vars))
		ret = 1;
	else if (min_map_contain(vars))
		ret = 1;
	else if (rectangular_check(vars))
		ret = 1;
	else if (surrounded_wall(vars))
		ret = 1;
	else if (dfs_valid_path(vars))
		ret = 1;
	if (ret == 1)
	{
		if (vars)
			var_free(vars);
		return (1);
	}
	return (0);
}
