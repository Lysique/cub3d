/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:58:56 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 11:27:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	are_all_textures_set(t_game *game)
{
	if (!game->north_texture || !game->south_texture)
		return (0);
	if (!game->west_texture || !game->east_texture)
		return (0);
	if (!game->ceiling_texture || !game->floor_texture)
		return (0);
	return (1);
}

int	texture_to_struct(t_game *game, char *line)
{
	if (are_all_textures_set(game))
		return (0);
	else if (!line)
		return (-1);
	line = skip_spaces(line, line, game);
	if (line[0] == 'N' && line[1] == 'O')
		game->north_texture = skip_spaces(&line[2], line, game);
	else if (line[0] == 'S' && line[1] == 'O')
		game->south_texture = skip_spaces(&line[2], line, game);
	else if (line[0] == 'W' && line[1] == 'E')
		game->west_texture = skip_spaces(&line[2], line, game);
	else if (line[0] == 'E' && line[1] == 'A')
		game->east_texture = skip_spaces(&line[2], line, game);
	else if (line[0] == 'F')
		game->floor_texture = skip_spaces(&line[2], line, game);
	else if (line[0] == 'C')
		game->ceiling_texture = skip_spaces(&line[2], line, game);
	else if (*line != '\n')
		return (free_and_return_error(line));
	else
		free(line);
	return (1);
}

int	add_texture_paths(int fd, t_game *game)
{
	char	*line;
	int		check;

	game->error = 4;
	line = get_next_line(fd, game);
	while (line)
	{
		check = texture_to_struct(game, line);
		if (check == -1)
			return (-1);
		else if (check == 0)
			return (0);
		line = get_next_line(fd, game);
	}
	return (-1);
}
