/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:38:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 12:09:36 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "global.h"
# include <stdio.h>

void			cub3d(char *argument);
void			structure_init(t_cub *cub);
void			variables_init(t_cub *cub);
void			imgs_creator(t_cub *cub);
void			img_resize(t_cub *cub);

void			parser(char *argument, t_cub *cub);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				mouse_press(void *param);
int				mouse_move(int x, int y, void *param);
int				mouse_click(int key, int x, int y, void *param);
int				mouse_release(int key, int x, int y, void *param);
int				loop_hook(t_cub *cub);
unsigned int	get_texture_color(t_img text, int y, int x);

#endif
