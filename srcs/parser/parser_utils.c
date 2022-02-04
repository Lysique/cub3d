/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:57:46 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/04 13:09:44 by tuytters         ###   ########.fr       */
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
		parser_error(MALLOC_ERROR, 0);
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

char	*cub3d_get_next_line(int fd)
{
	int		ret;
	char	*line;
	char	buf;

	ret = 1;
	line = 0;
	buf = 0;
	while (buf != '\n')
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

char	*cub3d_cpy(char *str, void *ptr)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new = malloc(i + 1);
	if (!new)
	{
		if (ptr)
			free(ptr);
		parser_error(MALLOC_ERROR, 0);
	}
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

int	is_texture_line(char *line)
{
	if (line[0] == 'F')
		return (F);
	else if (line[0] == 'C')
		return (C);
	else if (line[0] == 'N' && line[1] == 'O')
		return (NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (EA);
	else
		return (-1);
}
