/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:19:37 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/24 15:17:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "global.h"

# define MINI_PX 300
# define MINI_SIZE 10
# define PX_INDEX_CONV 1 / (MINI_PX / MINI_SIZE)

# define ORANGE 0x00FC7462
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RED 0x00FF0000

# define OUT_COLOR ORANGE
# define SPACE_COLOR ORANGE
# define WALL_COLOR BLACK
# define IN_COLOR GREEN

void	ray_casting(t_cub *cub);
void	display_map(t_cub *cub);
void	display_char(t_cub *cub, t_img img);
void	put_my_pixel(t_img img, int x, int y, int color);

#endif
