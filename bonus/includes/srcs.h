/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:38:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 11:07:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "global.h"
# include <stdio.h>

void			cub3d(char *argument);
void			structure_init(t_cub *cub);
void			imgs_creator(t_cub *cub);
void			img_resize(t_cub *cub);
void			create_shaders(t_img *img, t_cub *cub);
void			create_menu_imgs(t_img *img, t_cub *cub);

void			parser(char *argument, t_cub *cub);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				mouse_press(void *param);
int				mouse_move(int x, int y, void *param);
int				mouse_click(int key, int x, int y, void *param);
int				mouse_release(int key, int x, int y, void *param);
int				loop_hook(t_cub *cub);

unsigned int	get_texture_color(t_img text, int y, int x);
void			srcs_put_my_pixel(t_img img, int y, int x, unsigned int color);

#endif
