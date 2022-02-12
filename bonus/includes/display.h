/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:19:37 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/12 13:13:39 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "global.h"

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
	float	tex_x;
	float	tex_y;
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
	int		p;
	t_img	tex;
}			t_ray;

void			ray_casting(t_cub *cub);
void			f_c_casting(t_cub *cub, t_ray *r);
void			draw_ray(t_ray *r, t_cub *cub);
void			ray_cast_doors(t_ray *r, t_cub *cub);
void			hit_wall_check(t_ray *r, t_cub *cub);

void			display_map(t_cub *cub);
void			display_char(t_cub *cub);
void			display_gun(t_cub *cub);
void			display_menu(t_cub *cub);

void			put_my_pixel(t_img img, int y, int x, unsigned int color);
unsigned int	get_texture_color(t_img text, int y, int x);
int				is_door(t_door *d, int y, int x);
int				is_raycast_end(t_cub *cub, int y, int x);
void			optimisation_pixel_put(t_img img, int y, int x, unsigned int color);

int		get_door_index(t_door *d, int y, int x);

#endif
