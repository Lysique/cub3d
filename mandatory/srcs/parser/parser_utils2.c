/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:05:14 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:09:12 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		if (!cub3d_isspace(line[i++]))
			return (0);
	return (1);
}

int	is_close_char(char c)
{
	if (c == '0' || is_player_char(c))
		return (0);
	return (1);
}
