/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:14:34 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/12 18:28:21 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define BUFFER_SIZE 1
# define ZEN_RATE 3

# define PLAYER "texture/chobo_right.xpm"
# define EMPTY "texture/tile.xpm"
# define WALL "texture/wall.xpm"
# define MON1 "texture/mon_1.xpm"
# define MON2 "texture/mon_2.xpm"
# define MON3 "texture/mon_3.xpm"
# define EXIT_CLOSE "texture/exit_close.xpm"
# define EXIT_OPEN "texture/exit_open.xpm"
# define COLLECT "texture/collect.xpm"
# define DEAD "texture/chobo_dead.xpm"
# define WARNING "texture/warning.xpm"
# define WARNING_S "texture/warning_s.xpm"
# define PATROL_MAX 100000000
# define WARNING_MAX 100000000

enum	e_pos
{
	X = 0,
	Y = 1,
}	;

enum	e_map_error
{
	NO_RECTANGULAR = 1,
	NO_SURROUND,
	NO_CONSIST,
	NO_VALID,
	NO_FILENAME,
}	;

enum	e_return_value
{
	RETURN_SUCCESS = 0,
	RETURN_FAILURE,
}	;

enum	e_key
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	P = 35,
	ESC = 53,
	LEFT = 123,
	RIGHT = 124,
	UP = 126,
	DOWN = 125,
}	;

enum	e_hook_event
{
	KEY_PRESS = 2,
	PRESS_MASK = 1L<<0,
	KEY_RELEASE = 3,
	RELEASE_MASK = 1L<<1,
	WINDOW_DESTROY = 17,
	DESTROY_MASK = 0,
}	;

#endif