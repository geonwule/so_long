/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:22:57 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/11 14:35:24 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
	{
		printf("Error\nNeed one argument\n");
		return (RETURN_FAILURE);
	}
	// init_vars(&vars);
	read_file(&vars, av[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * 50, vars.height * 50, "so_long");
	init_vars_info(&vars);
	mlx_hook(vars.win, KEY_PRESS, PRESS_MASK, key_press, &vars);
	mlx_hook(vars.win, KEY_RELEASE, RELEASE_MASK, key_release, &vars);
	// mlx_hook(vars.win, MOUSE_BUTTON, BUTTON_MASK, handle_mouse_button, &vars);
	// mlx_hook(vars.win, MOUSE_MOVE, MOVE_MASK, handle_mouse_move, &vars);
	mlx_loop_hook(vars.mlx, rendering, &vars);
	mlx_hook(vars.win, WINDOW_DESTROY, DESTROY_MASK, exit_game, &vars);
	mlx_loop(vars.mlx);
	return (RETURN_SUCCESS);
}
/*
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
	{
		printf("Error\n");
		printf("Need one argument\n");
		return (RETURN_FAILURE);
	}
	init_vars(&vars);
	read_file(&vars, av[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_vars_info(&vars);
	mlx_hook(vars.win, KEY_PRESS, PRESS_MASK, key_press, &vars);
	mlx_hook(vars.win, KEY_RELEASE, RELEASE_MASK, key_release, &vars);
	mlx_hook(vars.win, MOUSE_BUTTON, BUTTON_MASK, handle_mouse_button, &vars);
	mlx_hook(vars.win, MOUSE_MOVE, MOVE_MASK, handle_mouse_move, &vars);
	mlx_loop_hook(vars.mlx, rendering, &vars);
	mlx_hook(vars.win, WINDOW_DESTROY, DESTROY_MASK, exit_game, &vars);
	mlx_loop(vars.mlx);
	return (RETURN_SUCCESS);
}
*/