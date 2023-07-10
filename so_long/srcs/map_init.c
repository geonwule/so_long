/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:04:29 by geonwule          #+#    #+#             */
/*   Updated: 2023/03/22 18:21:06 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	contain_check(t_vars *vars, char *map)
{
	int	i;
	int	collect;
	int	starting;
	int	exit;

	i = 0;
	collect = 0;
	starting = 0;
	exit = 0;
	vars->contain = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			collect++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'P')
			starting++;
		i++;
	}
	vars->c_collect = collect;
	if (starting == 1 && exit == 1 && collect > 0)
		vars->contain = 1;
}

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
	map = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (map == NULL)
		return (0);
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

void	map_read(char *map_name, t_vars *vars)
{
	char	*line;
	char	*map;

	map = NULL;
	vars->fd = open(map_name, O_RDONLY);
	if (vars->fd < 0)
		return ;
	line = get_next_line(vars->fd);
	vars->c_collect = 0;
	vars->height = 0;
	vars->width_e = 1;
	vars->width = ft_strlen(line) - 1;
	while (line)
	{
		vars->height++;
		map = ft_strjoin_so(map, line);
		free(line);
		line = get_next_line(vars->fd);
		if (line && vars->width != (ft_strlen_nonl(line)))
			vars->width_e = -1;
	}
	vars->map = map;
	contain_check(vars, vars->map);
	vars->c_move = 0;
	close(vars->fd);
}
