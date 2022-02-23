/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:30:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/23 10:58:42 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_ponct(t_cub *cub, int start_y, int *start_x, char text)
{
	int	i;

	i = 0;
	if (text == '/' || (++i && text == ';') || (++i && text == '.')
		|| (++i && text == '+') || (++i && text == '-')
		|| (++i && text == '?') || (++i && text == '!')
		|| (++i && text == '[') || (++i && text == ']'))
	{
		mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->sprites[PONCT][i].img, *start_x, start_y);
		*start_x += cub->sprites[PONCT][i].w;
	}
}

void	draw_text(t_cub *cub, int start_y, int *start_x, char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] >= 'a' && text[i] <= 'z')
		{
			mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->sprites[ALPHA][text[i] - 'a'].img, *start_x, start_y);
			*start_x += cub->sprites[ALPHA][text[i] - 'a'].w;
		}
		else
			draw_ponct(cub, start_y, start_x, text[i]);
		i++;
	}
}

void	draw_nb(t_cub *cub, int start_y, int *start_x, int nb)
{
	int	length;

	length = 1;
	while (nb / length >= 10)
		length *= 10;
	while (length)
	{
		mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->sprites[CHIFFRE][nb / length].img, *start_x, start_y);
		*start_x += cub->sprites[CHIFFRE][nb / length].w;
		nb = nb % length;
		length = length / 10;
	}
}

void	display_menu(t_cub *cub)
{
	t_img	img;
	int		x;

	img = cub->sprites[MENUBAR][0];
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, img.img, MENUBAR_START_X, MENUBAR_START_Y);
	x = POS_TX_BULLET_X;
	draw_text(cub, POS_TX_BULLET_Y, &x, "bullets");
	x = POS_NB_BULLET_X;
	draw_nb(cub, POS_NB_BULLET_Y, &x, cub->gun[cub->gun_type].bullets);
	draw_text(cub, POS_NB_BULLET_Y, &x, "/");
	draw_nb(cub, POS_NB_BULLET_Y, &x, cub->gun[cub->gun_type].max_bullets);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->sprites[PORTRAIT][cub->player.emotion].img, 725, 890);
	x = TX_ENEMY_X;
	draw_text(cub, TX_ENEMY_Y, &x, "enemies");
	x = POS_NB_ENEMY_X;
	draw_nb(cub, POS_NB_ENEMY_Y, &x, cub->nb_enemies);
	draw_text(cub, POS_NB_BULLET_Y, &x, "/");
	draw_nb(cub, POS_NB_ENEMY_Y, &x, cub->max_enemies);
	x = TX_LIFEBAR_X;
	draw_text(cub, TX_LIFEBAR_Y, &x, "life");
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->sprites[LIFE][cub->player.life].img, LIFEBAR_X, LIFEBAR_Y);
}
