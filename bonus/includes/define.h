/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:14:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/08 11:03:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*######## GLOBAL DEFINE ########*/

		/* GLOBAL VARIABLES */

# define PI 3.14159265359
# define MIDPI 1.570796326795

# define WIN_H 1080
# define WIN_W 1920

/*		PLAYER SPEED && PLAYER ROTATE_SPEED

 		0.0015 FOR ROTATE AND 0.0015 FOR SPEED ARE RECOMMENDED.*/

# define SPEED 0.0015
# define ROTATE 0.0015
# define SENSI_MOUSE 0.00009

		/* TEXTURES INDEXES */

# define F 0
# define C 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5

		/* NB_SPRITES 
		   
		   NB_SPR : NUMBER OF SPRITES CATEGORIES
		   MAX_SPR : MAXIMUM NUMBER OF SPRITES IN A CATEGORY. */

# define NB_SPR 2
# define MAX_SPR 6

		/* SPRITES INDEXES */

# define LIFE 0
# define DOOR 1

		/* ERRORS */

# define EXOK 0
# define HANDLED 1
# define MALLOC_ERROR 2
# define IMG_ERROR 3
# define MLX_ERROR 4
# define MUSIC_NOT_FOUND 5

		/* COLORS */

# define ORANGE 0x00FC7462
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF

/*######## DISPLAY_DEFINE ########*/

# define MINI_PX 300
# define MINI_SIZE 10

		/* MIDMINI = MINI_SIZE / 2 */

# define MIDMINI 5
		/* PX_INDEX_CONV = 1 / (MINI_PX / MINI_SIZE) */

# define PX_INDEX_CONV 0.033333

# define SO_NO 1
# define WE_EA 0

		/* MINIMAP COLORS */

# define OUT_COLOR ORANGE
# define SPACE_COLOR ORANGE
# define WALL_COLOR BLACK
# define IN_COLOR GREEN

/*######## KEYS_DEFINE ########*/

# define K_ESC 53
# define K_D 2
# define K_A 0
# define K_S 1
# define K_W 13
# define K_LEFT 123
# define K_RIGHT 124

# define K_SPACE 49

#endif
