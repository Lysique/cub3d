/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:17:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/25 09:18:09 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	display(t_cub *cub)
{
	display_map(cub);
	display_char(cub, cub->display);
	ray_casting(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->display.img, 0, WIN_H - MINI_PX);
}
