/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_xpm_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 03:13:33 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/05 03:14:26 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	process_img_xpm_set1(t_vars *vars, int x, int y)
{
	vars->mini.player = ft_xpm_file_to_image(vars->mlx, PLAYER, &x, &y);
	vars->mini.empty = ft_xpm_file_to_image(vars->mlx, EMPTY, &x, &y);
	vars->mini.wall = ft_xpm_file_to_image(vars->mlx, WALL, &x, &y);
	vars->mini.monster = ft_xpm_file_to_image(vars->mlx, MONSTER, &x, &y);
	vars->mini.exit_close = ft_xpm_file_to_image(vars->mlx, EXIT_CLOSE, &x, &y);
	vars->mini.exit_oepn = ft_xpm_file_to_image(vars->mlx, EXIT_OPEN, &x, &y);
	vars->mini.potion = ft_xpm_file_to_image(vars->mlx, POTION, &x, &y);
	vars->mini.dead = ft_xpm_file_to_image(vars->mlx, DEAD, &x, &y);
	// vars->mini.dir = ft_xpm_file_to_image(vars->mlx, M_DIR, &x, &y);
	// vars->mini.npc = ft_xpm_file_to_image(vars->mlx, M_NPC, &x, &y);
}

static void	process_img_xpm_set2(t_vars *vars, int x, int y)
{
	vars->xpm.warning = ft_xpm_file_to_image(vars->mlx, WARNING, &x, &y);
}
// {
// 	vars->xpm.quest_start = ft_xpm_file_to_image(vars->mlx, N_QUEST1, &x, &y);
// 	vars->xpm.quest_ing = ft_xpm_file_to_image(vars->mlx, N_QUEST2, &x, &y);
// 	vars->xpm.quest_end = ft_xpm_file_to_image(vars->mlx, N_QUEST3, &x, &y);
// 	vars->xpm.dead = ft_xpm_file_to_image(vars->mlx, E_DEAD, &x, &y);
// 	vars->xpm.damage = ft_xpm_file_to_image(vars->mlx, E_DAMAGE, &x, &y);
// 	vars->xpm.aim = ft_xpm_file_to_image(vars->mlx, E_AIM, &x, &y);
// 	vars->xpm.w_messege = ft_xpm_file_to_image(vars->mlx, E_WARNING, &x, &y);
// 	vars->xpm.hand1 = ft_xpm_file_to_image(vars->mlx, E_HAND1, &x, &y);
// 	vars->xpm.hand2 = ft_xpm_file_to_image(vars->mlx, E_HAND2, &x, &y);
// 	vars->xpm.hp1 = ft_xpm_file_to_image(vars->mlx, U_HP1, &x, &y);
// 	vars->xpm.hp2 = ft_xpm_file_to_image(vars->mlx, U_HP2, &x, &y);
// 	vars->xpm.hp3 = ft_xpm_file_to_image(vars->mlx, U_HP3, &x, &y);
// 	vars->xpm.exp1 = ft_xpm_file_to_image(vars->mlx, U_EXP1, &x, &y);
// 	vars->xpm.exp2 = ft_xpm_file_to_image(vars->mlx, U_EXP2, &x, &y);
// 	vars->xpm.lv = ft_xpm_file_to_image(vars->mlx, U_LEVEL, &x, &y);
// }

void	img_xpm_set(t_vars *vars)
{
	process_img_xpm_set1(vars, 0, 0);
	process_img_xpm_set2(vars, 0, 0);
}
