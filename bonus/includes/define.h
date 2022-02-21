/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:14:23 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 13:00:26 by tamighi          ###   ########.fr       */
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

# define OPTI 2

# define SG_BULLETS 2
# define MG_BULLETS 50

/*#################### TEXTURES INDEXES ####################*/

		/* TEXTURES INDEXES */

# define F 0
# define C 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5

		/* SPRITES INDEXES */

# define LIFE 0
# define DOOR 1
# define SHOTGUN 2
# define MACHINEGUN 3
# define MENUBAR 4
# define NAKED_EN 5

		/* NB_SPRITES 
		   
		   NB_SPR : NUMBER OF SPRITES CATEGORIES
		   MAX_SPR : MAXIMUM NUMBER OF SPRITES IN A CATEGORY. */

# define NB_SPR 6
# define MAX_SPR 13

/*#################### ENNEMY SETTINGS ####################*/

		/*ENNEMY NUDE */

# define ENNU_LIFE 15
# define ENNU_NBSPR 9
# define ENNU_NBRUNSPR 6

		/* ENNEMIES ACTION */

# define E_STILL 1

/*#################### PLAYER SETTINGS ####################*/

		/* HITBOXS
		 *
		 * Note : 1 unit represent 1 map case.
		 *
		 * HITBOX : Collision with walls.
		 *
		 * DOOR_REACH : Distance to where we can open and close a door.
		 *
		 * 			DEFAULT VALUES :
		 *
		 * HITBOX : 0.3 / DOOR_REACH : 1.7
		 */
		/* MOVING SPEED
		 *
		 * Note : These values are multiplied by cub->time
		 * (time in ms between 2 loop_hooks).
		 *
		 * SPEED : Speed when moving with keyboard.
		 *
		 * ROTATION : Speed when rotating with keyboard.
		 *
		 * SENSI_MOUSE : Speed when rotating with mouse.
		 *
		 * 			DEFAULT VALUES :
		 *
		 * 	SPEED : 0.0015 / ROTATE : 0.0015 / SENSI_MOUSE : 0.0000015
		 */
		/* FRAME SPEED
		 *
		 * STEP_SOUND_FRAME : Time in ms between each step sound.
		 *
		 */

# define HITBOX 0.3
# define DOOR_REACH 1.7

# define SPEED 0.0015
# define ROTATE 0.0015
# define SENSI_MOUSE 0.00015

# define STEP_SOUND_FRAME 300

		/* PLAYER ACTION */

# define FREE_GUN 0
# define RELOADING 1
# define SWAPPING_GUN 2
# define SHOOTING 3

/*#################### DOOR DEFINE ####################*/

		/* FRAME SPEED
		 *
		 * DOOR_FRAME : Time in ms between each door sprite.
		 */

# define DOOR_FRAME 100

/*#################### GUN DEFINE ####################*/

		/* SHARED DEFINE
		 *
		 * RELOAD_GUN_SPEED : Time between each reload frame in ms.
		 * 
		 * SWAP_GUN_BREAK : Time break after swapping gun.
		 */

# define RELOAD_GUN_SPEED 150
# define SWAP_GUN_BREAK 200

		/* SHOT GUN
		 */

# define SHOTGUN_SPEED 100
# define SHOTGUN_WAIT_TIME 500

		/* MACHIN GUN 
		 */

# define MACHINGUN_SPEED 60

		/* GUN ACTION */

# define GS_FREE 0
# define GS_SHOT 1
# define GS_WAIT 2
# define GS_RELOAD 3

/*#################### DISPLAY DEFINE ####################*/

				/* Note : Be carefull to not exceed WIN_H and WIN_W 
				 * when modifying values
				 */

		/* MINIMAP 
		 *
		 * MINI_PX_X/Y : Size of the x and y of the minimap in pixel
		 * (see PX_INDEX_CONV).
		 *
		 * MINI_SIZE_X/Y : Number of blocks in the x and y of the minimap.
		 * Should always be an even number(see PX_INDEX_CONV). 
		 *
		 * MINI_PX_SPACE_X/Y : The space between the edge of the screen
		 * and the minimap
		 *
		 * PX_INDEX_CONV_X/Y : Conversion screen pixel to map.
		 * (1 / (MINI_PX / MINI_SIZE)) 
		 * 		
		 * 				DEFAULT VALUES :
		 *
		 * PX_X/Y : 200 / SIZE_X/Y : 10 / PX_SPACE_X/Y : 20 / INDEX_CONV_X/Y : 0.05
		 */
		/* MINIMAP CHARACTER
		 *
		 * CHAR_SIZE : Size of the square representing the character in
		 * the minimap in pixel. Should always be an even number.
		 *
		 * CHAR_LINE_SIZE : Size of the line pointing to the direction of the character
		 * in the minimap in pixel.
		 *
		 * CHAR_COLOR/LINE_COLOR : Color of the square and the line.
		 *
		 * 				DEFAULT VALUES :
		 *
		 * SIZE : 10 / LINE SIZE : 20
		 */
		/* MENUBAR 
		 *
		 * MENUBAR_H/W : The size of the menubar in pixel. 
		 *
		 * MENUBAR_START_X/Y : Place of the minibar. 			
		 *
		 * 				DEFAULT VALUES : 
		 *
		 * H : 200 / W : 1690 / START_X : 230 / START_Y : 880 
		 */
		/*GUN PLACEMENT
		 *
		 * POS_GUN_X : The x pixel of the middle of the image
		 * POS_GUN_Y : The y pixel of the start of the image
		 *
		 * SIZE_GUN_X/Y : Multiply the height and width of the gun image
		 *
		 * 				DEFAULT VALUES :
		 *
		 * POS_X : 960 / POS_Y : 880 / SIZE_X/Y : 2
		 */

# define MINI_PX_X 200
# define MINI_PX_Y 200

# define MINI_SIZE_X 10
# define MINI_SIZE_Y 10

# define MINI_PX_SPACE_X 20
# define MINI_PX_SPACE_Y 20

# define PX_INDEX_CONV_X 0.05
# define PX_INDEX_CONV_Y 0.05

# define CHAR_SIZE 10
# define CHAR_LINE_SIZE 20

# define CHAR_COLOR BLUE
# define CHAR_LINE_COLOR RED

# define MENUBAR_H 200
# define MENUBAR_W 1690

# define MENUBAR_START_X 230
# define MENUBAR_START_Y 880

# define POS_GUN_X 960
# define POS_GUN_Y 880

# define SIZE_GUN_X 2
# define SIZE_GUN_Y 2

		/* MINIMAP COLORS */

# define OUT_COLOR ORANGE
# define SPACE_COLOR ORANGE
# define WALL_COLOR BLACK
# define IN_COLOR GREEN

		/* DISPLAY UTILS DEFINES */

# define SO_NO 1
# define WE_EA 0

/*##################### KEYS DEFINE ####################*/

# define K_ESC 53

# define K_D 2
# define K_A 0
# define K_S 1
# define K_W 13

# define K_LEFT 123
# define K_RIGHT 124
# define K_UP 126
# define K_DOWN 125

# define K_SHIFT 258

# define K_SPACE 49

/*#################### COLORS ####################*/

# define ORANGE 0x00FC7462
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF

/*#################### GLOBAL ERRORS ####################*/

# define EXOK 0
# define HANDLED 1
# define MALLOC_ERROR 2
# define IMG_ERROR 3
# define MLX_ERROR 4
# define MUSIC_NOT_FOUND 5

/*#################### PARSER_ERROR DEFINE #####################*/

# define NB_ERRORS 100

# define OPEN_ERROR 1
# define MALLOC_ERROR 2
# define EMPTY_FILE 3
# define FILE_NOT_ENDED 4

/*		Error = {TYPE_ERROR}_ERROR * NB_ERRORS + x
 
		X = nth error of type {TYPE_ERROR}. Should not exceed NB_ERRORS.
 		Type errors : [TEXTURE_ERROR; MAP_ERROR]*/

# define TEXTURE_ERROR 1
# define MISSING_TEXTURE 101
# define DUPL_TEXTURE 102
# define FORMAT_TEXTURE 103
# define MISSING_FILE_NAME 104
# define MISSING_SPACE 105
# define XPM_ERROR 106

# define MAP_ERROR 2
# define MISSING_NL 201
# define MISSING_MAP 202
# define UNKNOWN_CHAR 203
# define OPEN_MAP 204
# define MULT_PLAYER 205
# define NO_PLAYER 206
# define DOOR_ERROR 207

#endif
