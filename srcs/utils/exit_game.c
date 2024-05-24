/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:15:17 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/12 15:45:30 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	exit_game(t_vars *vars)
{
	write(1, "Player has exited the game\n", 27);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->map);
	exit(EXIT_SUCCESS);
}
