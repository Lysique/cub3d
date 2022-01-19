/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:22:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/19 09:51:51 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	check_map_elements(t_cub *cub)
{
	int		i;
	int		j;
	int		p;

	i = -1;
	j = -1;
	p = 0;
	while (cub->map[++j])
	{
		while (cub->map[j][++i])
		{
			if (is_player_char(cub->map[j][i], p, i, j) && p++)
				return (-1);
			if (!is_char_allowed_on_map(cub->map[j][i], i, j))
				return (-1);
		}
		i = -1;
	}
	if (!p)
	{
		printf("Error\nNo player on the map.\n");
		return (-1);
	}
	return (1);
}

int	check_open_detail(int i, int j, t_cub *cub)
{
	char	**map;

	map = cub->map;
	if (j == 0 || i == 0 || !map[j + 1] || !map[j][i + 1]
				|| map[j - 1][i] == ' ' || map[j][i - 1] == ' '
				|| map[j + 1][i] == ' ' || map[j][i + 1] == ' '
				|| !map[j - 1][i] || !map[j + 1][i])
	{
		printf("Error\nMap[%d][%d] wrong. The map is perforated.\n", j, i);
		return (-1);
	}
	return (1);
}

int	check_open_map(t_cub *cub)
{
	int		i;
	int		j;
	char	**map;

	map = cub->map;
	i = -1;
	j = -1;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if ((map[j][i] == '0' || is_player_char(map[j][i], 0, i , j)))
				if (check_open_detail(i, j, cub) == -1)
					return (-1);
		}
		i = -1;
	}
	return (1);
}

int	map_checker(t_cub *cub)
{
	if (check_open_map(cub) == -1 || check_map_elements(cub) == -1)
		return (-1);
	return (1);
}
