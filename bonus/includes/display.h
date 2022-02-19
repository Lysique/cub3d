/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:19:37 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/19 13:17:30 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "global.h"

typedef struct s_ray {
	float	p_angle;
	float	fov;
	float	cam_plane_x;
	float	cam_plane_y;
	float	cam_r;
	float	dir_x;
	float	dir_y;
	float	dir;
	float	delta_x;
	float	delta_y;
	float	side_x;
	float	side_y;
	float	dist;
	float	perp_wall_dist;
	float	wall_x;
	float	tex_x;
	float	tex_y;
	float	tex_stepy;
	float	dir2_x;
	float	dir2_y;
	float	row_dist;
	float	tex_stepx;
	float	floor_x;
	float	floor_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		pix_screen_x;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		p;
	t_img	tex;
}				t_ray;

void			view_casting(t_cub *cub);
void			hit_wall_check(t_ray *r, t_cub *cub);
void			f_c_casting(t_ray *r, t_cub *cub);
void			draw_ennemies(t_ray *r, t_cub *cub);
void			sprites_init(t_ray *r, t_cub *cub);
void			hit_wall_check(t_ray *r, t_cub *cub);
void			draw_line(t_ray *r, t_cub *cub);

void			display_map(t_cub *cub);
void			display_char(t_cub *cub);
void			display_gun(t_cub *cub);
void			display_menu(t_cub *cub);

void			put_my_pixel(t_img img, int y, int x, unsigned int color);
unsigned int	get_texture_color(t_img text, int y, int x);
int				is_door(t_door *d, int y, int x);
int				is_ennemy(t_en *en, int y, int x);
int				is_element_before_wall(t_cub *cub, int y, int x);
int				is_raycast_end(t_cub *cub, int y, int x);
void			optimisation_pixel_put(t_img img, int y, int x, unsigned int color);
void			optimisation_pixel_put2(t_img img, int y, int x, unsigned int color);

#endif
