/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_or_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 08:32:23 by tuytters          #+#    #+#             */
/*   Updated: 2022/01/19 09:54:41 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	is_char_allowed_on_map(char c, int i, int j)
{
	if (c == ' ' || c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W')
		return (1);
	printf("Error\nBad character on Map[%d][%d].\n", j, i);
	return (0);
}

int	is_player_char(char c, int check, int i, int j)
{
	if (check == 1 && (c == 'S' || c == 'N' || c == 'W' || c == 'E'))
	{
		printf("Error\nToo many players on Map[%d][%d].\n", j, i);
		return (-1);
	}
	else if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
