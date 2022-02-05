/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:48:25 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/26 17:15:54 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	player_data(char c, t_cub *cub, int i, int j)
{
	if (c == 'S')
		cub->player.angle = 3 * PI / 2.;
	else if (c == 'N')
		cub->player.angle = PI / 2.;
	else if (c == 'E')
		cub->player.angle = 0;
	else if (c == 'W')
		cub->player.angle = PI;
	cub->player.y = j + 0.5;
	cub->player.x = i + 0.5;
}

void	player_init(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cub->map[++j])
	{
		while (cub->map[j][++i])
		{
			if (is_player_char(cub->map[j][i]))
			{
				player_data(cub->map[j][i], cub, i, j);
				cub->map[j][i] = '0';
				return ;
			}
		}
		i = -1;
	}
}
