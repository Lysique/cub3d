/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:41:26 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/24 08:47:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	map_error_caller(int error, int i, int j)
{
	t_coord	coord;

	coord.i = i;
	coord.j = j;
	parser_error(error, &coord);
}

int	check_open_map(char **map, int i, int j)
{
	int	k;

	if (j == 0 || i == 0)
		return (1);
	if (!map[j + 1] || !map[j][i + 1])
		return (1);
	k = 0;
	while (map[j - 1][k] && k != i)
		k++;
	if (k != i || !map[j - 1][k])
		return (1);
	k = 0;
	while (map[j + 1][k] && k != i)
		k++;
	if (k != i || !map[j + 1][k])
		return (1);
	return (0);
}

void	map_checker(char **map)
{
	int		i;
	int		j;
	int		p;

	i = -1;
	j = -1;
	p = 0;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (!is_known_char(map[j][i]))
				map_error_caller(UNKNOWN_CHAR, i, j);
			if (map[j][i] == '0' || (is_player_char(map[j][i]) && ++p))
				if (check_open_map(map, i, j))
					map_error_caller(OPEN_MAP, i, j);
			if (p > 1)
				map_error_caller(MULT_PLAYER, i, j);
		}
		i = -1;
	}
	if (!p)
		parser_error(NO_PLAYER, 0);
}
