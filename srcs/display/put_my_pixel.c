/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_my_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:09:53 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/07 15:01:05 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	put_my_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.sizel + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
