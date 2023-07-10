/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:01:36 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/06 15:21:26 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_strlen_nonl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

static char	*ft_strjoin_so(char const *s1, char const *s2)
{
	char	*map;
	int		s1_len;
	int		s2_len;
	int		i[2];

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2[s2_len - 1] == '\n')
		s2_len -= 1;
	map = (char *)ft_malloc(sizeof(char) * (s1_len + s2_len + 1));
	i[0] = -1;
	i[1] = -1;
	while (++i[0] < s1_len)
		map[i[0]] = s1[i[0]];
	while (++i[1] < s2_len)
		map[i[0] + i[1]] = s2[i[1]];
	map[s1_len + s2_len] = '\0';
	if (s1 != NULL)
		free((void *)s1);
	return (map);
}

static void	init_vars_parsing(t_vars *vars, char *line)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		vars->keyboard[i] = 0;
		i++;
	}
	vars->map = NULL;
	vars->height = 0;
	vars->width = ft_strlen_nonl(line);
	vars->cnt_move = 0;
	vars->cnt_collect = 0;
	vars->dead = 0;
	vars->dead_check = 0;
	vars->error = 0;
	vars->monster_num = 0;
	vars->warning_time = 0;
	vars->patrol = 0;
}

static void	check_pos(t_vars *vars, int i)
{
	vars->pos[X] = i / vars->width;
	vars->pos[Y] = i % vars->width;
}

static void	contain_check(t_vars *vars, char *map)
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

static void	check_errno(int errno, t_vars *vars)
{
	if (errno == NO_RECTANGULAR)
		print_error("Invalid map: NO RECTANGULAR", vars);
	else if (errno == NO_SURROUND)
		print_error("Invalid map: NO SURROUNDED WALL", vars);
	else if (errno == NO_CONSIST)
		print_error("Invalid map: Consist of map Error", vars);
}

void	read_file(t_vars *vars, char *path)
{
	char	*line;
	int		fd;

	fd = ft_open(path);
	line = get_next_line(fd);
	init_vars_parsing(vars, line);
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
		contain_check(vars, vars->map);
	if (vars->error)
		check_errno(vars->error, vars);
}

// void	read_file(t_vars *vars, char *path)
// {
// 	init_vars_parsing(vars);
// 	check_file(vars, path);
// 	init_map_info(vars, path);
// 	if (check_map(vars))
// 		print_error("Invalid map", vars);
// }
