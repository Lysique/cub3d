/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 08:55:26 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 12:50:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	optimisation_pixel_put(t_img img, int y, int x, unsigned int color)
{
	int	i;
	int	j;

	i = OPTI;
	while (i--)
	{
		j = OPTI;
		while (j--)
			put_my_pixel(img, y + i, x + j, color);
	}
}

int	is_element_before_wall(t_cub *cub, int y, int x)
{
	if (get_door_index(cub->doors, y, x) != -1)
		return (1);
	return (0);
}

int	is_raycast_end(t_cub *cub, int y, int x)
{
	t_door	*d;
	char	**map;
	int		i;

	map = cub->map;
	if (map[y][x] == '0')
		return (0);
	d = cub->doors;
	i = get_door_index(cub->doors, y, x);
	if (i == -1)
		return (1);
	if (d[i].open || d[i].is_moving)
		return (0);
	else
		return (1);
}

unsigned int	get_texture_color(t_img text, int y, int x)
{
	char			*dst;
	unsigned int	color;

	if (y < 0 || x < 0 || y >= text.h || x >= text.w)
		return (0xFF000000);
	dst = text.addr + (y * text.sizel + x * (text.bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	put_my_pixel(t_img img, int y, int x, unsigned int color)
{
	char	*dst;

	if (color == 0xFF000000)
		return ;
	dst = img.addr + (y * img.sizel + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
