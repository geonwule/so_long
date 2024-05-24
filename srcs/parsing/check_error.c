/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:39:02 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 15:16:58 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	check_map_consist(t_vars *vars)
{
	int	i;

	if (vars->error)
		return ;
	i = 0;
	while (vars->map[i] != '\0')
	{
		if (!ft_strchr("01CEP", vars->map[i]))
		{
			vars->error = NO_CONSIST;
			return ;
		}
		i++;
	}
	return ;
}

static void	check_surrounded(t_vars *vars)
{
	int	i;

	if (vars->error)
		return ;
	i = 0;
	while (vars->map[i] != '\0')
	{
		if ((i < vars->width && vars->map[i] != '1')
			|| (i % vars->width == 0 && vars->map[i] != '1')
			|| ((i >= vars->width * (vars->height - 1)) && vars->map[i] != '1')
			|| ((i + 1) % vars->width == 0 && vars->map[i] != '1'))
		{
			vars->error = NO_SURROUND;
			return ;
		}
		i++;
	}
	return ;
}

static void	check_errno(int errno, t_vars *vars)
{
	if (errno == NO_FILENAME)
		print_error("File name must end :.ber", vars);
	else if (errno == NO_RECTANGULAR)
		print_error("Invalid map: NO RECTANGULAR", vars);
	else if (errno == NO_SURROUND)
		print_error("Invalid map: NO SURROUNDED WALL", vars);
	else if (errno == NO_CONSIST)
		print_error("Invalid map: NO MAP CONSIST", vars);
	else if (errno == NO_VALID)
		print_error("Invalid map: NO VALID PATH", vars);
}

void	map_error(t_vars *vars)
{
	check_map_consist(vars);
	check_surrounded(vars);
	dfs_valid_path(vars);
	if (vars->error)
		check_errno(vars->error, vars);
}
