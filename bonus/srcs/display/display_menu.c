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

void	draw_ponct3(t_cub *cub, int start_y, int *start_x, char text)
{
	if (text == '[')
	{
		draw_img(cub, cub->sprites[PONCT][L_BRACKET], start_y, *start_x);
		*start_x += cub->sprites[PONCT][L_BRACKET].w;
	}
	else if (text == ']')
	{
		draw_img(cub, cub->sprites[PONCT][R_BRACKET], start_y, *start_x);
		*start_x += cub->sprites[PONCT][R_BRACKET].w;
	}
}

void	draw_ponct2(t_cub *cub, int start_y, int *start_x, char text)
{
	if (text == '-')
	{
		draw_img(cub, cub->sprites[PONCT][MINDER], start_y, *start_x);
		*start_x += cub->sprites[PONCT][MINDER].w;
	}
	else if (text == '?')
	{
		draw_img(cub, cub->sprites[PONCT][QUEST_M], start_y, *start_x);
		*start_x += cub->sprites[PONCT][QUEST_M].w;
	}
	else if (text == '!')
	{
		draw_img(cub, cub->sprites[PONCT][EXCLA_M], start_y, *start_x);
		*start_x += cub->sprites[PONCT][EXCLA_M].w;
	}
	draw_ponct3(cub, start_y, start_x, text);
}

void	draw_ponct(t_cub *cub, int start_y, int *start_x, char text)
{
	if (text == '/')
	{
		draw_img(cub, cub->sprites[PONCT][SLASH], start_y, *start_x);
		*start_x += cub->sprites[PONCT][SLASH].w;
	}
	else if (text == ':')
	{
		draw_img(cub, cub->sprites[PONCT][DOUBLE_D], start_y, *start_x);
		*start_x += cub->sprites[PONCT][DOUBLE_D].w;
	}
	else if (text == '.')
	{
		draw_img(cub, cub->sprites[PONCT][DOT], start_y, *start_x);
		*start_x += cub->sprites[PONCT][DOT].w;
	}
	else if (text == '+')
	{
		draw_img(cub, cub->sprites[PONCT][MORE], start_y, *start_x);
		*start_x += cub->sprites[PONCT][MORE].w;
	}
	draw_ponct2(cub, start_y, start_x, text);
}

void	draw_text(t_cub *cub, int start_y, int start_x, char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			draw_img(cub, cub->sprites[CHIFFRE][text[i] - '0'], start_y, start_x);
			start_x += cub->sprites[CHIFFRE][text[i] - '0'].w;
		}
		else if (text[i] >= 'a' && text[i] <= 'z')
		{
			draw_img(cub, cub->sprites[ALPHA][text[i] - 'a'], start_y, start_x);
			start_x += cub->sprites[ALPHA][text[i] - 'a'].w;
		}
		else
			draw_ponct(cub, start_y, &start_x, text[i]);
		i++;
	}
}

void	display_menu(t_cub *cub)
{
	t_img	img;
	char	*nbr_bullets;
	char	*nbr_max_bullets;
	char	*nbr_enemy;
	char	*nbr_max_enemy;

	img = cub->sprites[MENUBAR][0];
	draw_img(cub, img, MENUBAR_START_Y, MENUBAR_START_X);
	draw_text(cub, POS_TX_BULLET_Y, POS_TX_BULLET_X, "bullets");
	nbr_bullets = ft_itoa(cub->gun[cub->gun_type].bullets);
	nbr_max_bullets = ft_itoa(cub->gun[cub->gun_type].max_bullets);
	nbr_max_bullets = ft_strjoin("/", nbr_max_bullets);
	nbr_bullets = ft_strjoin(nbr_bullets, nbr_max_bullets);
	draw_text(cub, POS_NB_BULLET_Y, POS_NB_BULLET_X, nbr_bullets);
	draw_text(cub, TX_ENEMY_Y, TX_ENEMY_X, "enemys");
	nbr_enemy = ft_itoa(cub->nb_enemy);
	nbr_max_enemy = ft_itoa(cub->max_enemy);
	nbr_max_enemy = ft_strjoin("/", nbr_max_enemy);
	nbr_enemy = ft_strjoin(nbr_enemy, nbr_max_enemy);
	draw_text(cub, POS_NB_ENEMY_Y, POS_NB_ENEMY_X, nbr_enemy);
	draw_text(cub, TX_LIFEBAR_Y, TX_LIFEBAR_X, "life");
	draw_img(cub, cub->sprites[LIFE][cub->player.life], LIFEBAR_Y, LIFEBAR_X);
}
