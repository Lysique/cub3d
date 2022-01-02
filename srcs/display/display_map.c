/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/02 17:10:02 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	blackhole_display(t_cub *cub, int *x, int *y)
{
	int	pix_x;
	int	pix_y;

	pix_x = (cub->player.x - (5 * UNIT)) - *x;
	pix_y = (*y - (cub->player.y - (5 * UNIT))) / UNIT;
	*y += (1 * UNIT);
	printf("%d\n", pix_y);
}

void	magic_displayer(t_cub *cub, int x, int y)
{
	while (y < 0)
		blackhole_display(cub, &x, &y);
}

void	display_map(t_cub *cub)
{
	int	y;
	int	x;

	y = cub->player.y - UNIT * 5;
	x = cub->player.x - UNIT * 5;
	magic_displayer(cub, x, y);
}
