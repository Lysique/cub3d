/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:44:24 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 10:57:55 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	add_line_to_map(t_cub *cub, char *line)
{
	int		i;
	char	**new;

	i = 0;
	while (cub->map && cub->map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
	{
		if (line)
			free(line);
		my_write("Memory allocation error.\n");
		return (-1);
	}
	i = -1;
	while ((++i || cub->map) && cub->map[i])
		new[i] = cub->map[i];
	new[i++] = line;
	new[i] = 0;
	if (cub->map)
		free(cub->map);
	cub->map = new;
	return (1);
}

int	map_to_struct(t_cub *cub, int fd)
{
	char	*line;

//	line = get_next_line(fd);
	line = 0;
	(void)fd;
	while (line && line[0] == '\0')
	{
		free(line);
//		line = get_next_line(fd);
	}
	while (line && line[0] != '\0')
	{
		if (add_line_to_map(cub, line) == -1)
			return (-1);
//		line = get_next_line(fd);
	}
	while (line && line[0] == '\0')
	{
		free(line);
//		line = get_next_line(fd);
	}
	if (line || !cub->map)
		return (-1);
	return (1);
}

int	parse_map(t_cub *cub, int fd)
{
	cub->map = 0;
	if (map_to_struct(cub, fd) == -1 || !cub->map)
		return (-1);
	if (map_checker(cub) == -1)
		return (-1);
	return (1);
}
