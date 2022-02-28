/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:19:37 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:15:05 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "global.h"

# define MINI_PX 300
# define MINI_SIZE 10

		/* MIDMINI = MINI_SIZE / 2 */

# define MIDMINI 5
		/* PX_INDEX_CONV = 1 / (MINI_PX / MINI_SIZE) */

# define PX_INDEX_CONV 0.03333333

# define SO_NO 1
# define WE_EA 0

		/* MINIMAP COLORS */

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
	float	dir2_x;
	float	dir2_y;
	float	plane_x;
	float	plane_y;
	float	ray_r;
	float	wall_dist;
	float	camera_r;
	float	wall_x;
	float	tex_stepy;
	float	tex_stepx;
	float	tex_pos;
	float	row_dist;
	float	floor_x;
	float	floor_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		tex_x;
	int		tex_y;
	int		pix_x;
	int		draw_start;
	int		draw_end;
	int		line_h;
	int		hit;
	int		side;
	int		tex;
	int		p;
	int	cell_x;
	int	cell_y;
	float pos_z;
}			t_ray;

void			ray_casting(t_cub *cub);
void			draw_ray(t_ray *r, t_cub *cub);

void			display_map(t_cub *cub);
void			display_char(t_cub *cub, t_img img);

void			put_my_pixel(t_img img, int x, int y, int color);
unsigned int	get_texture_color(t_img text, int x, int y);

#endif
