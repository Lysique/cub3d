/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:14:48 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 13:20:22 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_part_of_map(char *line, t_game *game)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (!line)
		return (0);
	while (line[i] == ' ' || line[i] == '	')
		if (line[i++] == '	')
			ret = 0;
	if (line[i] == '1' && ret)
		return (1);
	else if (line[i] == '\n' || line[i] == '\0')
		return (0);
	else
		error_manager(game, 5);
	return (0);
}

char	**add_line_to_map(char **map, char *line, t_game *game)
{
	char	**new;
	int		i;

	i = 0;
	while (map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		error_manager(game, game->error + 100);
	i = 0;
	while (map[i])
	{
		new[i] = map[i];
		i++;
	}
	new[i++] = line;
	new[i] = 0;
	free(map);
	return (new);
}

int	check_rest_of_file(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line)
	{
		while (line[i] == ' ' || line[i] == '	')
			i++;
		if (line[i] != '\n' || line[i] != '\0')
		{
			free(line);
			return (-1);
		}
		i = 0;
		free(line);
		line = get_next_line(game->fd, game);
	}
	return (0);
}

int	check_map(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (map[j])
	{
		while(map[j][i])
		{
			if (map[j][i] == '0' && (j == 0 || i == 0 ||!map[j + 1] || !map[j - 1]
				|| map[j - 1][i] == ' ' || map[j][i - 1] == ' '
				|| map[j + 1][i] == ' ' || map[j][i + 1] == ' '))
				return (-1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	add_map(t_game *game)
{
	char	*line;

	game->error = 5;
	game->map = malloc(sizeof(char *));
	*game->map = 0;
	if (!game->map)
		error_manager(game, game->error + 100);
	line = get_next_line(game->fd, game);
	while (line && !is_part_of_map(line, game))
	{
		free(line);
		line = get_next_line(game->fd, game);
	}
	while (is_part_of_map(line, game))
	{
		game->map = add_line_to_map(game->map, line, game);
		line = get_next_line(game->fd, game);
	}
	if (check_rest_of_file(line, game) == -1)
		return (-1);
	if (check_map(game->map) == -1)
		return (-1);
	return (0);
}
