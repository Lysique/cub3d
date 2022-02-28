/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:37:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:50:12 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	lh_hit_wall_check(t_ray *r, float dist)
{
	t_cub	*cub;

	cub = set_cubptr(0);
	while (is_raycast_end(cub, r->map_y, r->map_x) == 0)
	{
		if (r->side_y < r->side_x)
		{
			if (r->side_y > dist)
				return (0);
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
		}
		else
		{
			if (r->side_x > dist)
				return (0);
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
		}
	}
	return (1);
}

int	lh_wall_hit_checker(float angle, float dist, float x, float y)
{
	t_ray	r;

	r.dir_x = cos(angle);
	r.dir_y = sin(angle) * -1;
	r.delta_x = sqrtf(1 + (r.dir_y * r.dir_y) / (r.dir_x * r.dir_x));
	r.delta_y = sqrtf(1 + (r.dir_x * r.dir_x) / (r.dir_y * r.dir_y));
	r.map_x = (int)x;
	r.map_y = (int)y;
	side_init(&r, x, y);
	return (lh_hit_wall_check(&r, dist));
}

int	bad_trajectory_checker(float angle, float delta_x,
		float delta_y, float angle2)
{
	delta_y = fabsf(delta_y);
	delta_x = fabsf(delta_x);
	if (delta_y > delta_x)
	{
		if (sin(angle) < 0 && sin(angle2) > 0)
			return (1);
		else if (sin(angle) > 0 && sin(angle2) < 0)
			return (1);
	}
	else if (delta_x > delta_y)
	{
		if (cos(angle) < 0 && cos(angle2) > 0)
			return (1);
		else if (cos(angle) > 0 && cos(angle2) < 0)
			return (1);
	}
	return (0);
}

int	check_if_hit(t_en *en, t_cub *cub)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	dist;
	float	m;

	delta_x = cub->player.x - en->x;
	delta_y = cub->player.y - en->y;
	dist = sqrtf(delta_x * delta_x + delta_y * delta_y);
	angle = get_angle(delta_y, delta_x);
	if (bad_trajectory_checker(angle, delta_x, delta_y, cub->player.angle) == 1)
		return (0);
	if (lh_wall_hit_checker(angle, dist, cub->player.x, cub->player.y) == 1)
		return (0);
	m = tan(angle - cub->player.angle + PI / 2);
	if (dist / m < en->hbox && dist / m > -en->hbox)
		return (1);
	return (0);
}

void	hit_manager(t_cub *cub, t_gun *gun)
{
	int	i;
	int	checker;

	i = -1;
	gun->bullets--;
	order_enemies(cub);
	while (cub->en[++i].action != -1)
		;
	while (i--)
	{
		if (cub->en[i].life <= 0)
			continue ;
		checker = check_if_hit(&cub->en[i], cub);
		if (checker == 1)
			cub->en[i].life -= gun->damage;
		if (checker != 0)
			break ;
	}
	if (i != -1 && cub->en[i].life <= 0)
		cub->nb_enemies--;
}
