#include "cub3d.h"

int main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
	{
		printf("Error\nNeed one argument\n");
		return (RETURN_FAILURE);
	}
	init_vars(&vars);
	read_file(&vars, av[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.width * 50, vars.map.height * 50, "so_long");
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