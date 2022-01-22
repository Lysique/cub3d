/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:22:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/22 16:42:55 by tamighi          ###   ########.fr       */
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

int	add_line_to_map(t_cub *cub, char *line)
{
	int		i;
	char	**new;

	i = 0;
	while (cub->map && cub->map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		parser_error(MALLOC_ERROR, 0);
	i = -1;
	while ((++i || cub->map) && cub->map[i])
		new[i] = cub->map[i];
	new[i] = cub3d_cpy(line, new);
	new[++i] = 0;
	if (cub->map)
		free(cub->map);
	cub->map = new;
	return (1);
}

char	**parse_map(t_parser *p, char **file)
{
	if (!*file)
		parser_error(MISSING_MAP, 0);
	if (!is_line_empty(*file))
		parser_error(MISSING_NL, 0);
	while (is_line_empty(*file))
		file++;
	while (*file && !is_line_empty(*file))
		add_line_to_map(p->cub, *(file++));
	if (!p->cub->map)
		parser_error(MISSING_MAP, 0);
	map_checker(p->cub->map);
	return (file);
}
