/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:21:00 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/11 17:13:12 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "define.h"

typedef struct s_mini
{
	// void	*north_x;
	// void	*south_x;
	// void	*west_x;
	// void	*east_x;

	void	*player;
	void	*empty;
	void	*wall;
	void	*exit_close;
	void	*exit_open;
	void	*potion;
	void	*dead;
	void	*mon_1;
	void	*mon_2;
	void	*mon_3;

	// void	*dir;
	// void	*npc;
}	t_mini;

typedef struct s_xpm
{
	void	*warning;
}	t_xpm;
typedef struct s_vars
{
	char		*file_name;
	void		*mlx;
	void		*win;
	// t_map		map;
	// t_xpm		xpm;
	// t_info		info;
	// t_data		data;
	// t_sprite	sprite;

	t_xpm		xpm;
	t_mini		mini;


//data
	int			keyboard[256];

//monster
	unsigned int	sprite;
	int				monster_num;
	unsigned int	patrol;
	int				warning_time;


//parsing
	int			cnt_collect;
	int			height;
	int			width;
	int			error;
	int			cnt_step;
	char		*map;
	int			pos[2];
	int			dead_check;
	int			dead;
}	t_vars;

#endif