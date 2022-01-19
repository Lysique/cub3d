/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:14:29 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/19 08:32:03 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

// float	ft_distance_p_inter(t_cub *cub, float angle)
// {
// 	float	result;
// 	char	**map;
// 	int		i;
// 	int		j;

// 	map = cub->map;
// 	i = cub->player.x;
// 	j = cub->player.y;
// 	while ()
// 	result = 
// 	return (result);
// }

float	ft_angle(t_cub *cub, int i)
{
	const float	adj = 0.5;
	const float	opp = i / 1920. - 0.5;

	return (atan(opp / adj) + cub->player.angle);
}

void	ray_casting(t_cub *cub)
{
	int		i;
	float	angle;
	// float	dist_p_inter;

	i = 0;
	while (i < 1920)
	{
		angle = ft_angle(cub, i);
		// dist_p_inter = ft_distance_p_inter(cub, angle);
		i++;
	}
}
