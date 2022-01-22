/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:22:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 14:06:35 by tamighi          ###   ########.fr       */
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

int	is_player_char(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_known_char(char c)
{
	if (c == ' ' || c == '1' || c == '0'
		|| is_player_char(c))
		return (1);
	return (0);
}

void	check_open_map(char **map, int i, int j)
{
	if (j == 0 || i == 0 || !map[j + 1] || !map[j][i + 1]
		|| map[j - 1][i] == ' ' || map[j][i - 1] == ' '
		|| map[j + 1][i] == ' ' || map[j][i + 1] == ' '
		|| !map[j - 1][i] || !map[j + 1][i])
		map_error_caller(OPEN_MAP, i, j);
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
				check_open_map(map, i, j);
			if (p > 1)
				map_error_caller(MULT_PLAYER, i, j);
		}
		i = -1;
	}
	if (!p)
		parser_error(NO_PLAYER, 0);
}
