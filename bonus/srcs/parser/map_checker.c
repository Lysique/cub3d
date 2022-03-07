/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:41:26 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 15:03:26 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	check_open_map(char **map, int i, int j)
{
	int	k;

	if (j == 0 || i == 0 || map[j][i - 1] == ' ' || map[j][i + 1] == ' ')
		return (1);
	if (!map[j + 1] || !map[j][i + 1])
		return (1);
	k = 0;
	while (map[j - 1][k] && k != i)
		k++;
	if (k != i || !map[j - 1][k] || map[j - 1][k] == ' ')
		return (1);
	k = 0;
	while (map[j + 1][k] && k != i)
		k++;
	if (k != i || !map[j + 1][k] || map[j + 1][k] == ' ')
		return (1);
	return (0);
}

void	door_checker(char **map, int i, int j)
{
	int	error;

	error = 1;
	if (map[j - 1][i] == '1' && map[j + 1][i] == '1'
			&& !is_close_char(map[j][i - 1]) && !is_close_char(map[j][i + 1]))
		error = 0;
	if (map[j][i - 1] == '1' && map[j][i + 1] == '1'
			&& !is_close_char(map[j - 1][i]) && !is_close_char(map[j + 1][i]))
		error = 0;
	if (error)
		map_error_caller(DOOR_ERROR, i, j);
}

void	check_element(char **map, int i, int j)
{
	if (!is_known_char(map[j][i]))
		map_error_caller(UNKNOWN_CHAR, i, j);
	if (!is_close_char(map[j][i]))
		if (check_open_map(map, i, j))
			map_error_caller(OPEN_MAP, i, j);
	if (map[j][i] == '2' || map[j][i] == '3')
		door_checker(map, i, j);
}

void	map_checker(char **map)
{
	int		i;
	int		j;
	int		p;

	j = -1;
	p = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			check_element(map, i, j);
			if (is_player_char(map[j][i]))
				if (++p > 1)
					map_error_caller(MULT_PLAYER, i, j);
		}
	}
	if (!p)
		parser_error(NO_PLAYER, 0);
}
