/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:57:46 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 13:52:38 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	cub3d_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '	')
		return (1);
	return (0);
}

char	*add_buff(char *line, char buf)
{
	char	*new;
	int		i;

	i = 0;
	while (line && line[i])
		i++;
	new = malloc(i + 3);
	if (!new)
	{
		if (line)
			free(line);
		return (0);
	}
	i = -1;
	while ((++i || line) && line[i])
		new[i] = line[i];
	if (buf != '\n')
		new[i++] = buf;
	new[i] = '\0';
	if (line)
		free(line);
	return (new);
}

char	*cub3d_get_next_line(t_cub *cub, char **arr, int fd)
{
	int		ret;
	char	*line;
	char	buf;

	ret = 1;
	line = 0;
	while (ret && buf != '\n')
	{
		ret = read(fd, &buf, 1);
		if (ret <= 0)
			return (line);
		line = add_buff(line, buf);
		if (!line)
		{
			close(fd);
			parser_error(cub, arr, 1);
		}
	}
	return (line);
}

int	cub3d_strcmp(char *texture, char *line)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		if (line[i] != texture[i])
			return (0);
		i++;
	}
	return (1);
}
