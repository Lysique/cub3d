/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:57:46 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 15:13:08 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
		my_write("Memory allocation error.\n");
		if (line)
			free(line);
		return (0);
	}
	i = -1;
	if (!line)
		i = 0;
	while (line && line[++i])
		new[i] = line[i];
	if (buf != '\n')
		new[i++] = buf;
	new[i] = '\0';
	if (line)
		free(line);
	return (new);
}

char	*get_next_line(int fd)
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
			return (0);
	}
	return (line);
}

int	ft_strcmp(char *texture, char *line)
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
