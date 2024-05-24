/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:21:00 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 18:31:57 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "define.h"

typedef struct s_xpm
{
	void	*player;
	void	*empty;
	void	*wall;
	void	*exit_close;
	void	*exit_open;
	void	*collect;
	void	*dead;
	void	*mon_1;
	void	*mon_2;
	void	*mon_3;
	void	*warning;
	void	*warning_s;
}	t_xpm;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	char			*file_name;

	t_xpm			xpm;

	unsigned int	sprite;
	unsigned int	monster_num;
	unsigned int	patrol;
	unsigned int	warning_time;

	int				cnt_collect;
	int				height;
	int				width;
	int				error;
	int				cnt_step;
	char			*map;
	char			*map2;
	int				pos[2];
	int				dead_check;
	int				dead;
}	t_vars;

#endif