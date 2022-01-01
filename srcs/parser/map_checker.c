/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:22:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 16:43:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	is_player_char(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	map_checker(t_cub *cub)
{
	int		i;
	int		j;
	char	**map;
	int		p;

	i = 0;
	j = 0;
	p = 0;
	map = cub->map;
	while (map[j])
	{
		while (map[j][i])
		{
			if ((map[j][i] == '0' || is_player_char(map[j][i]))
				&& (j == 0 || i == 0 || !map[j + 1] || !map[j][i + 1]
				|| map[j - 1][i] == ' ' || map[j][i - 1] == ' '
				|| map[j + 1][i] == ' ' || map[j][i + 1] == ' '))
				parser_error(cub, 3);
			if (is_player_char(map[j][i]) && p++)
				parse_error(cub, 3);
			i++;
		}
		i = 0;
		j++;
	}
}
