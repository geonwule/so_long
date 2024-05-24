/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:22:57 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 18:31:58 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
	{
		ft_write(2, "Error\n");
		ft_write(2, "Need one argument\n");
		return (RETURN_FAILURE);
	}
	vars.file_name = av[1];
	init_vars_info(&vars);
	read_file(&vars, vars.file_name);
	vars.mlx = mlx_init();
	init_xpm_file(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.width * 50, \
				vars.height * 50, "so_long");
	mlx_hook(vars.win, KEY_PRESS, PRESS_MASK, key_press, &vars);
	mlx_loop_hook(vars.mlx, rendering, &vars);
	mlx_hook(vars.win, WINDOW_DESTROY, DESTROY_MASK, exit_game, &vars);
	mlx_loop(vars.mlx);
	return (RETURN_SUCCESS);
}
