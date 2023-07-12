/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:01:36 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 15:15:36 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	check_pos(t_vars *vars, int i)
{
	vars->pos[X] = i / vars->width;
	vars->pos[Y] = i % vars->width;
}

static void	check_contain(t_vars *vars, char *map)
{
	int	i;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			vars->cnt_collect++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'P')
		{
			check_pos(vars, i);
			player++;
		}
		i++;
	}
	if (!(player == 1 && exit == 1 && vars->cnt_collect > 0))
		vars->error = NO_CONSIST;
}

static void	check_file_name(t_vars *vars, char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		vars->error = NO_FILENAME;
	if (path[len - 1] != 'r' || path[len - 2] != 'e' \
		|| path[len - 3] != 'b' || path[len - 4] != '.')
		vars->error = NO_FILENAME;
	if (vars->error)
		map_error(vars);
}

void	read_file(t_vars *vars, char *path)
{
	char	*line;
	int		fd;

	check_file_name(vars, path);
	fd = ft_open(path);
	line = get_next_line(fd);
	vars->width = ft_strlen_nonl(line);
	while (line)
	{
		vars->height++;
		vars->map = ft_strjoin_so(vars->map, line);
		free(line);
		line = get_next_line(fd);
		if (line && vars->width != (ft_strlen_nonl(line)))
			vars->error = NO_RECTANGULAR;
	}
	close(fd);
	if (!vars->error)
		check_contain(vars, vars->map);
	map_error(vars);
}
