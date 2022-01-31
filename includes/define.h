/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:14:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/31 14:45:27 by tuytters         ###   ########.fr       */
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

/*		GAME_SPEED : THE LESS = THE FASTER

 		NUMBER OF TIMES THE PROGRAMS NEEDS TO ENTER LOOP_HOOK BEFORE
 		THE OTHER FUNCTIONS. 300 IS RECOMMENDED. */

# define GAME_SPEED 1

/*		PLAYER SPEED && PLAYER ROTATE_SPEED ; DEPEND ON GAME_SPEED.

 		GAME_SPEED MODIFY THE NUMBER OF TIMES THE PROGRAMES DISPLAYS
 		AND ENTER THE FUNCTIONS. THIS MIGHT SLOW THE TIMES IT ENTERS
 		THE LOOP_HOOK, THERE IS THUS NO PROPER CALCULS FOR SPEED
 		AND ROTATE. 0.12 FOR ROTATE AND 0.14 FOR SPEED ARE RECOMMENDED.*/

# define SPEED 0.08
# define ROTATE 0.08

		/* TEXTURES INDEXES */

# define F 0
# define C 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5

		/* COLORS */

# define ORANGE 0x00FC7462
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define TRANSP 0x80FFFFFF

#endif
