/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:30:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/13 16:32:08 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_img(t_cub *cub, t_img img, int start_y, int start_x)
{
	int				pix_x;
	int				pix_y;
	unsigned int	color;

	pix_x = -1;
	while (++pix_x < img.w)
	{
		pix_y = -1;
		while (++pix_y < img.h)
		{
			color = get_texture_color(img, pix_y, pix_x);
			put_my_pixel(cub->display, pix_y + start_y, pix_x + start_x, color);
		}
	}
}
