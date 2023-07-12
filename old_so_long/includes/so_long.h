/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:02:17 by geonwule          #+#    #+#             */
/*   Updated: 2023/05/30 16:58:49 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../mlx_opengl/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define TILE "./textures/tile.xpm"
# define WALL "./textures/wall.xpm"
# define COLLECT "./textures/collect.xpm"
# define EXIT_OPEN "./textures/exit_open.xpm"
# define EXIT_CLOSE "./textures/exit_close.xpm"
# define CHOBO_UP "./textures/chobo_up.xpm"
# define CHOBO_DOWN "./textures/chobo_down.xpm"
# define CHOBO_RIGHT "./textures/chobo_right.xpm"
# define CHOBO_LEFT "./textures/chobo_left.xpm"
# define CHOBO_DEAD "./textures/chobo_dead.xpm"
# define MONSTER "./textures/monster.xpm"
# define W 13
# define A 0
# define S 1
# define D 2
# define DEAD 3
# define ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_vars
{
	void	*mlx;
	void	*win;

	int		width;
	int		width_e;
	int		height;
	char	*map;
	char	*map2;
	int		contain;
	int		c_collect;
	int		c_move;
	int		fd;
	int		dead;

	void	*tile;
	void	*wall;
	void	*collect;
	void	*exit_open;
	void	*exit_close;
	void	*chobo_up;
	void	*chobo_down;
	void	*chobo_right;
	void	*chobo_left;
	void	*chobo_dead;
	void	*monster;

	int		step;
}			t_vars;

// map_init
void		map_read(char *map_name, t_vars *vars);
//get_next_line.c
char		*get_next_line(int fd);
//get_next_line_util.c
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1, char *back);

// map_error
int			map_error(t_vars *vars);
int			dfs_valid_path(t_vars *vars);

// map_set
void		map_set(t_vars *vars, int key_code); //, int c_collect);

// key_input
int			keyboard_input(int keycode, t_vars *vars);
// only_bonus
void		dead_player(t_vars *vars);

// so_long_util
char		*ft_itoa(int n);
void		img_xpm_set(t_vars *vars);
void		move_counting(t_vars *vars);
void		var_free(t_vars *vars);
int			exit_game(t_vars *vars);
void		end_game(t_vars *vars, int fail_or_win);
void		malloc_error(void);

#endif
