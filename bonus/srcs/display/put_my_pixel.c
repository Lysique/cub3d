/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_my_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:09:53 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/05 14:58:48 by tamighi          ###   ########.fr       */
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
