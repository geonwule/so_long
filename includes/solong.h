/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:19:21 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 18:30:46 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../Libft/libft.h"
# include "../mlx_opengl/mlx.h"
# include "define.h"
# include "structure.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
//bonus_random_generator
# include <time.h>
# include <sys/time.h>

// init/init_vars_info.c
void	init_vars_info(t_vars *vars);
// init/init_xpm_file.c
void	init_xpm_file(t_vars *vars);
//	init/init_background.c
void	fill_background(t_vars *vars);

// parsing/read_file.c
void	read_file(t_vars *vars, char *path);
// parsing/check_error.c
void	map_error(t_vars *vars);
// parsing/check_valid.c
void	dfs_valid_path(t_vars *vars);

// event/event_util.c
void	attack(t_vars *vars, int key);
void	reset_game(t_vars *vars);
// event/key_event.c
int		key_press(int keycode, t_vars *vars);
// event/manage_monster.c
void	manage_monster(t_vars *vars);
// event/rendering.c
int		rendering(t_vars *vars);
// event/set_map.c
void	set_map(t_vars *vars);

// utils/print_error.c
void	print_error(char *str, t_vars *vars);
// utils/ft_write.c
void	ft_write(int fd, char *str);
// utils/random_generator.c
int		random_generator(int frequency);
// utils/ft_malloc.c
void	*ft_malloc(size_t size);
// utils/ft_open.c
int		ft_open(char *file_path);
// utils/ft_strjoin_so
char	*ft_strjoin_so(char const *s1, char const *s2);
// utils/ft_strlen_nonl
int		ft_strlen_nonl(char *str);
// utils/exit_game.c
int		exit_game(t_vars *vars);
// utils/ft_get_data_addr.c
char	*ft_get_data_addr(void *img_ptr, int *bits, int *size, int *end);
// utils/ft_xpm_file_to_image.c
void	*ft_xpm_file_to_image(void *mlx_ptr, char *path, int *w, int *h);

// get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s1, char *back);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif
