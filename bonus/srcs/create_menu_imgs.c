/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_menu_imgs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:52:40 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 14:20:11 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	put_button(t_img menu, t_img button, int start_y, int start_x)
{
	int				i;
	int				j;
	unsigned int	color;

	j = -1;
	while (++j < BUTTONS_H)
	{
		i = -1;
		while (++i < BUTTONS_W)
		{
			color = get_texture_color(button, j, i);
			if (color != 0xFF000000)
				srcs_put_my_pixel(menu, start_y + j, start_x + i, color);
		}
	}
}

void	create_menu_imgs(t_img *img, t_cub *cub)
{
	put_button(img[M_MAIN], cub->sprites[BUTTONS][B_PLAY],
		MM_PLAY_Y, MM_PLAY_X);
	put_button(img[M_MAIN], cub->sprites[BUTTONS][B_EXIT],
		MM_EXIT_Y, MM_EXIT_X);
	put_button(img[M_LOSE], cub->sprites[BUTTONS][B_EXIT],
		LM_EXIT_Y, LM_EXIT_X);
	put_button(img[M_LOSE], cub->sprites[BUTTONS][B_RETRY],
		LM_RETRY_Y, LM_RETRY_X);
	put_button(img[M_LOSE], cub->sprites[BUTTONS][B_MMENU],
		LM_MMENU_Y, LM_MMENU_X);
	put_button(img[M_WIN], cub->sprites[BUTTONS][B_EXIT], WM_EXIT_Y, WM_EXIT_X);
	put_button(img[M_WIN], cub->sprites[BUTTONS][B_CONTINUE],
		WM_CONTINUE_Y, WM_CONTINUE_X);
	put_button(img[M_WIN], cub->sprites[BUTTONS][B_MMENU],
		WM_MMENU_Y, WM_MMENU_X);
	put_button(img[M_BREAK], cub->sprites[BUTTONS][B_EXIT],
		BM_EXIT_Y, BM_EXIT_X);
	put_button(img[M_BREAK], cub->sprites[BUTTONS][B_CONTINUE],
		BM_CONTINUE_Y, BM_CONTINUE_X);
	put_button(img[M_BREAK], cub->sprites[BUTTONS][B_MMENU],
		BM_MMENU_Y, BM_MMENU_X);
	put_button(img[M_BREAK], cub->sprites[BUTTONS][B_RETRY],
		BM_RETRY_Y, BM_RETRY_X);
}
