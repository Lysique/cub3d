/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:34:10 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/13 16:10:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	draw_map_error(char **map, t_coord *c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	my_write("\n");
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (i == c->i && j == c->j)
				my_write("\033[0;31m");
			write(1, &map[j][i], 1);
			if (i == c->i && j == c->j)
				my_write("\033[0m");
		}
		i = -1;
		my_write("\n");
	}
}

void	map_error(int error, char **map, t_coord *c)
{
	if (error == MISSING_NL)
		my_write("Missing newline after texture initialization.\n");
	else if (error == MISSING_MAP)
		my_write("Map is missing in the file.\n");
	else if (error == UNKNOWN_CHAR)
		my_write("Unknown character in the map.\n");
	else if (error == OPEN_MAP)
		my_write("Map is open. Close it.\n");
	else if (error == NO_PLAYER)
		my_write("No player on the map.\n");
	else if (error == MULT_PLAYER)
		my_write("Too many players on the map.\n");
	else if (error == DOOR_ERROR)
		my_write("Bad door emplacement.\n");
	if (c)
		draw_map_error(map, c);
}
