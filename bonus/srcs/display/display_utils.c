/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 08:55:26 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/07 09:50:55 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

unsigned int	get_texture_color(t_img text, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = text.addr + (y * text.sizel + x * (text.bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	put_my_pixel(t_img img, int y, int x, int color)
{
	char	*dst;

	dst = img.addr + (y * img.sizel + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
