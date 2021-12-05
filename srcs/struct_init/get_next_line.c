/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:48:19 by tamighi           #+#    #+#             */
/*   Updated: 2021/12/05 11:27:00 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strjoin(char *line, char buf, t_game *game)
{
	int		i;
	char	*new;

	i = 0;
	while (line && line[i])
		i++;
	new = malloc(i + 2);
	if (!new)
		error_manager(game, game->error + 100);
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i++] = buf;
	new[i] = '\0';
	if (line)
		free(line);
	return (new);
}

char	*get_next_line(int fd, t_game *game)
{
	int		ret;
	char	*line;
	char	buf[1];

	ret = 1;
	line = 0;
	*buf = 0;
	while (ret && *buf != '\n')
	{
		ret = read(fd, buf, 1);
		if (ret == -1 || ret == 0)
			return (0);
		line = ft_strjoin(line, *buf, game);
	}
	return (line);
}
