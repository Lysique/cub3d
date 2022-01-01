/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:00:05 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 16:22:29 by tamighi          ###   ########.fr       */
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

int	is_part_of_map(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	if (!line[i])
	{
		free(line);
		return (0);
	}
	while (line[i])
	{
		if (is_char_allowed_on_map(line[i]) == 0)
		{
			free(line);
			parser_error(cub, 3);
		}
		i++;
	}
	return (1);
}

void	add_line_to_map(t_cub *cub, char *line)
{
	int		i;
	char	**new;

	i = 0;
	while (cub->map && cub->map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 3));
	if (!new)
	{
		if (line)
			free(line);
		my_write("Memory allocation error.\n");
		parser_error(cub, 3);
	}
	i = -1;
	if (!cub->map)
		i = 0;
	while (cub->map && cub->map[++i])
		new[i] = cub->map[i];
	new[i++] = line;
	new[i] = 0;
	if (cub->map)
		free(cub->map);
	cub->map = new;
}

void	map_to_struct(t_cub *cub, int fd)
{
	char	*line;

	cub->map = 0;
	line = get_next_line(fd);
	while (line && !is_part_of_map(cub, line))
		line = get_next_line(fd);
	while (is_part_of_map(cub, line))
	{
		add_line_to_map(cub, line);
		line = get_next_line(fd);
	}
	line = get_next_line(fd);
	while (line && !is_part_of_map(cub, line))
		line = get_next_line(fd);
	if (line)
	{
		free(line);
		parser_error(cub, 3);
	}
}

void	parse_map(t_cub *cub, int fd)
{
	map_to_struct(cub, fd);
	map_checker(cub);
}
