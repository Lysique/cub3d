/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:22:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 17:38:07 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	is_char_allowed_on_map(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_player_char(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	map_checker(t_cub *cub)
{
	int		i;
	int		j;
	char	**map;
	int		p;

	i = -1;
	j = -1;
	p = 0;
	map = cub->map;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if ((map[j][i] == '0' || is_player_char(map[j][i]))
				&& (j == 0 || i == 0 || !map[j + 1] || !map[j][i + 1]
				|| map[j - 1][i] == ' ' || map[j][i - 1] == ' '
				|| map[j + 1][i] == ' ' || map[j][i + 1] == ' '))
				return (-1);
			if (is_player_char(map[j][i]) && p++)
				return (-1);
			if (!is_char_allowed_on_map(map[j][i]))
				return (-1);
		}
		i = -1;
	}
	if (!p)
		return (-1);
	return (1);
}
