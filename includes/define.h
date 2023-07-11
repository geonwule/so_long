/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:14:34 by geonwule          #+#    #+#             */
/*   Updated: 2023/07/11 14:30:09 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEX_WIDTH 400	
# define TEX_HEIGHT 400
# define MAP_HEIGHT 15
# define MAP_WIDTH 34
# define BUFFER_SIZE 1
# define ZEN_RATE 3

# define PLAYER "texture/chobo_right.xpm"
# define EMPTY "texture/tile.xpm"
# define WALL "texture/wall.xpm"
# define MONSTER "texture/monster.xpm"
# define EXIT_CLOSE "texture/exit_close.xpm"
# define EXIT_OPEN "texture/exit_open.xpm"
# define POTION "texture/collect.xpm"
# define DEAD "texture/chobo_dead.xpm"
# define WARNING "texture/warning.xpm"

enum	e_map_error
{
	NO_RECTANGULAR = 1,
	NO_SURROUND,
	NO_CONSIST,
}	;

enum	e_pos
{
	X = 0,
	Y = 1,
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
	B = 11,
	R = 15,
	Q = 12,
	E = 14,
	P = 35,
	N = 45,
	M = 46,
	ESC = 53,
	LEFT = 123,
	RIGHT = 124,
	UP = 126,
	DOWN = 125,
	SPACE = 49,
}	;

enum	e_hook_event
{
	KEY_PRESS = 2,
	PRESS_MASK = 1L<<0,
	KEY_RELEASE = 3,
	RELEASE_MASK = 1L<<1,
	MOUSE_BUTTON = 4,
	BUTTON_MASK = 1L<<2,
	MOUSE_MOVE = 6,
	MOVE_MASK = 1L<<6,
	WINDOW_DESTROY = 17,
	DESTROY_MASK = 0,
}	;

#endif