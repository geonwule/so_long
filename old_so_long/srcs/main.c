/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:02:53 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 13:27:18 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	*vars_init(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		malloc_error();
	vars->map = NULL;
	vars->map2 = NULL;
	vars->step = -1;
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	char	*mapname;

	if (ac != 2)
	{
		write(2, "input only one map\n", 19);
		return (0);
	}
	vars = vars_init();
	mapname = av[1];
	map_read(mapname, vars);
	if (map_error(vars))
		return (0);
	vars->dead = 0;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * 50, vars->height * 50,
			"so_long");
	img_xpm_set(vars);
	map_set(vars, D);
	mlx_key_hook(vars->win, keyboard_input, vars);
	mlx_hook(vars->win, 17, 0, exit_game, vars);
	mlx_loop(vars->mlx);
}
