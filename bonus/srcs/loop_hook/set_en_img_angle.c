/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_en_img_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:35:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 16:10:18 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	set_naked_img_angle(t_en *en, float d_angle)
{
	if (d_angle >= 15 * PI / 8 || d_angle < PI / 8)
		en->img_dir = EN1_E;
	else if (d_angle >= 13 * PI / 8 && d_angle < 15 * PI / 8)
		en->img_dir = EN1_SE;
	else if (d_angle >= 11 * PI / 8 && d_angle < 13 * PI / 8)
		en->img_dir = EN1_S;
	else if (d_angle >= 9 * PI / 8 && d_angle < 11 * PI / 8)
		en->img_dir = EN1_SW;
	else if (d_angle >= 7 * PI / 8 && d_angle < 9 * PI / 8)
		en->img_dir = EN1_W;
	else if (d_angle >= 5 * PI / 8 && d_angle < 7 * PI / 8)
		en->img_dir = EN1_NW;
	else if (d_angle >= 3 * PI / 8 && d_angle < 5 * PI / 8)
		en->img_dir = EN1_N;
	else if (d_angle >= 1 * PI / 8 && d_angle < 3 * PI / 8)
		en->img_dir = EN1_NE;
}

void	set_soldier_img_angle(t_en *en, float d_angle)
{
	if (d_angle >= 15 * PI / 8 || d_angle < PI / 8)
		en->img_dir = EN2_E;
	else if (d_angle >= 13 * PI / 8 && d_angle < 15 * PI / 8)
		en->img_dir = EN2_SE;
	else if (d_angle >= 11 * PI / 8 && d_angle < 13 * PI / 8)
		en->img_dir = EN2_S;
	else if (d_angle >= 9 * PI / 8 && d_angle < 11 * PI / 8)
		en->img_dir = EN2_SW;
	else if (d_angle >= 7 * PI / 8 && d_angle < 9 * PI / 8)
		en->img_dir = EN2_W;
	else if (d_angle >= 5 * PI / 8 && d_angle < 7 * PI / 8)
		en->img_dir = EN2_NW;
	else if (d_angle >= 3 * PI / 8 && d_angle < 5 * PI / 8)
		en->img_dir = EN2_N;
	else if (d_angle >= 1 * PI / 8 && d_angle < 3 * PI / 8)
		en->img_dir = EN2_NE;
}

void	set_boss_img_angle(t_en *en, float d_angle)
{
	if (d_angle >= 15 * PI / 8 || d_angle < PI / 8)
		en->img_dir = EN3_E;
	else if (d_angle >= 13 * PI / 8 && d_angle < 15 * PI / 8)
		en->img_dir = EN3_SE;
	else if (d_angle >= 11 * PI / 8 && d_angle < 13 * PI / 8)
		en->img_dir = EN3_S;
	else if (d_angle >= 9 * PI / 8 && d_angle < 11 * PI / 8)
		en->img_dir = EN3_SW;
	else if (d_angle >= 7 * PI / 8 && d_angle < 9 * PI / 8)
		en->img_dir = EN3_W;
	else if (d_angle >= 5 * PI / 8 && d_angle < 7 * PI / 8)
		en->img_dir = EN3_NW;
	else if (d_angle >= 3 * PI / 8 && d_angle < 5 * PI / 8)
		en->img_dir = EN3_N;
	else if (d_angle >= 1 * PI / 8 && d_angle < 3 * PI / 8)
		en->img_dir = EN3_NE;
}

void	set_en_img_angle(t_en *en, t_cub *cub)
{
	float	angle;
	float	d_angle;

	angle = get_angle(cub->player.y - en->y, cub->player.x - en->x);
	d_angle = en->angle - angle - 3 * PI / 2;
	while (d_angle < 0)
		d_angle += 2 * PI;
	if (en->type == SOLDIER_EN)
		set_soldier_img_angle(en, d_angle);
	else if (en->type == NAKED_EN)
		set_naked_img_angle(en, d_angle);
	else if (en->type == BOSS_EN)
		set_boss_img_angle(en, d_angle);
}
