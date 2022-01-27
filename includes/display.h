/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:19:37 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/27 13:04:10 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "global.h"

# define MINI_PX 300
# define MINI_SIZE 10
# define MIDMINI MINI_SIZE / 2
# define PX_INDEX_CONV 1 / (MINI_PX / MINI_SIZE)

# define SO_NO 1
# define WE_EA 0

# define ORANGE 0x00FC7462
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF

# define OUT_COLOR ORANGE
# define SPACE_COLOR ORANGE
# define WALL_COLOR BLACK
# define IN_COLOR GREEN

typedef struct s_ray {
	float	side_x;
	float	side_y;
	float	delta_x;
	float	delta_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	ray_r;
	float	wall_dist;
	float	camera_r;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		pix_x;
	int		draw_start;
	int		draw_end;
	int		line_h;
	int		hit;
	int		side;
}			t_ray;

void	ray_casting(t_cub *cub);
void	display_map(t_cub *cub);
void	display_char(t_cub *cub, t_img img);
void	put_my_pixel(t_img img, int x, int y, int color);

#endif
