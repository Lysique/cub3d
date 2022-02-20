/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:17:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/20 12:30:28 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	display(t_cub *cub)
{
	view_casting(cub);
	display_menu(cub);
	display_map(cub);
	display_char(cub);
	display_gun(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->display.img, 0, 0);
}
