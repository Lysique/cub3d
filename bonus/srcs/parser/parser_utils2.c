/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:05:14 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 15:33:30 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	is_door_char(char c)
{
	if (c == '2' || c == '3')
		return (c);
	return (0);
}

int	is_player_char(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (c);
	return (0);
}

int	is_known_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'm'
		|| is_player_char(c) || is_door_char(c)
		|| is_ennemy_char(c))
		return (c);
	return (0);
}

int	is_close_char(char c)
{
	if (c == '2' || is_player_char(c) || c == '3' || c == '0'
		|| c == 'm' || is_ennemy_char(c))
		return (0);
	return (1);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		if (!cub3d_isspace(line[i++]))
			return (0);
	return (1);
}
