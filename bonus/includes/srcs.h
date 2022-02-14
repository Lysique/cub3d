/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:38:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/13 17:24:38 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "global.h"
# include <stdio.h>

void	cub3d(char *argument);
void	structure_init(t_cub *cub);
void	variables_init(t_cub *cub);
void	imgs_creator(t_cub *cub);

void	parser(char *argument, t_cub *cub);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
int		mouse_press(void *param);
int		mouse_move(int x, int y, void *param);
int		loop_hook(t_cub *cub);

#endif
